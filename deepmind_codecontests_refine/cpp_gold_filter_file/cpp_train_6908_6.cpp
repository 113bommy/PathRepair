#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fu = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) (fu |= (ch == '-'));
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return fu ? -x : x;
}
int A, B, C, G[2005][2005], ans;
int gcd(int a, int b) {
  return b == 0 ? a : (G[a][b] ? G[a][b] : G[a][b] = G[b][a] = gcd(b, a % b));
}
int prime[2005], pcnt, mu[2005];
bool noprime[2005];
void init() {
  mu[1] = 1;
  for (int i = 2; i <= A; i++) {
    if (!noprime[i]) prime[++pcnt] = i, mu[i] = -1;
    for (int j = 1; j <= pcnt && i * prime[j] <= A; j++) {
      noprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
      mu[i * prime[j]] = -mu[i];
    }
  }
}
int solve(int up, int a, int b) {
  int ret = 0;
  for (int i = 1; i <= up; i++)
    if (gcd(i * a, b) == 1) ret += up / i;
  return ret;
}
int main() {
  A = read(), B = read(), C = read();
  if (A > B) A ^= B ^= A ^= B;
  if (A > C) A ^= C ^= A ^= C;
  if (B > C) B ^= C ^= B ^= C;
  init();
  for (int k = 1, t = 0; k <= B; k++, t = 0) {
    for (int d = 1; d <= A; d++) {
      t += mu[d] * solve(A / d, d, k) * solve(C / d, d, k);
    }
    ans = (ans + B / k * t) % 1073741824;
  }
  printf("%d\n", (ans % 1073741824 + 1073741824) % 1073741824);
  return 0;
}
