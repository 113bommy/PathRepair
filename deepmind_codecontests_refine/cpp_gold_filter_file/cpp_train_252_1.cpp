#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int mod = inf + 7;
int n, x, w[2000100], p[2000100];
long long res;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    w[x] = w[x] + 1;
  }
  for (int i = 0; i <= 20; i++)
    for (int mask = 0; mask < (1 << 20); mask++)
      if (mask & (1 << i)) w[mask ^ (1 << i)] += w[mask];
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 2 % mod;
  for (int mask = 0; mask < (1 << 20); mask++) {
    int c = 1;
    for (int i = 0; i < 20; i++)
      if (mask & (1 << i)) c = -c;
    res = (res + c * p[w[mask]] + mod) % mod;
  }
  printf("%I64d", res);
  return 0;
}
