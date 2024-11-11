#include <bits/stdc++.h>
using namespace std;
const int N = 2010, mod = 1073741824 - 1;
int f[N * N];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int a, b, c;
int p[N * N], l = 0;
short mu[N * N];
bool A[N * N];
void init() {
  int n = a * b;
  mu[1] = 1;
  for (int i = (2); i <= (n); i++) {
    if (!A[i]) p[++l] = i, mu[i] = -1;
    for (int j = (1); j <= (l); j++) {
      int k = i * p[j];
      if (k > n) break;
      A[k] = 1;
      if (i % p[j])
        mu[k] = -mu[i];
      else {
        mu[k] = 0;
        break;
      }
    }
  }
  for (int d = (1); d <= (n); d++)
    if (mu[d]) {
      int sum = 0;
      for (int i = d; i <= n; i += d) sum += c / i;
      sum *= mu[d];
      for (int i = d; i <= n; i += d) f[i] += sum;
    }
}
int main() {
  scanf("%d%d%d", &a, &b, &c);
  int ans = 0;
  init();
  for (int i = (1); i <= (a); i++)
    for (int j = (1); j <= (b); j++)
      if (gcd(i, j) == 1) ans += (a / i) * (b / j) * f[i * j];
  ans &= mod;
  printf("%d\n", ans);
}
