#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int maxn = 1010;
const int maxk = 110;
long long n, k, m;
long long f[maxn][maxk];
long long p1[maxn];
long long p2[maxn];
void build() {
  p1[0] = p2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p1[i] = p1[i - 1] * 10 % k;
    p2[i] = p2[i - 1] * 10 % m;
  }
}
void solve() {
  memset(f, 0, sizeof(f));
  scanf("%I64d%I64d%I64d", &n, &k, &m);
  build();
  for (int i = 1; i < 10; i++) f[1][i % k]++;
  for (int i = 1; i < n; i++)
    for (int j = 0; j < k; j++)
      for (int l = 0; l < 10; l++)
        if (l * p1[i] % k != j)
          f[i + 1][j] = (f[i + 1][j] + f[i][(k + j - (l * p1[i] % k)) % k]) % m;
        else if (l)
          f[i + 1][j] = (f[i + 1][j] + 1) % m;
  long long ans = f[n][0];
  for (int i = 1; i < n; i++) ans = (ans + f[i][0] * 9 * p2[n - i - 1]) % m;
  printf("%I64d", ans);
}
int main() {
  solve();
  return 0;
}
