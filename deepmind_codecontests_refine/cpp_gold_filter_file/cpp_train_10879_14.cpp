#include <bits/stdc++.h>
using namespace std;
const int Mod = int(1e9) + 7;
const int N = 1010000;
int m, n, k, a[N], ans, c[N];
long long l, dp[N], ss[N];
pair<int, int> p[N];
inline long long in() {
  long long x = 0;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int main() {
  n = in();
  l = in();
  k = in();
  for (int i = 0; i < n; ++i) a[i] = in();
  m = n * k;
  for (int i = 0; i < m; ++i) p[i] = make_pair(a[i % n], i);
  sort(p, p + m);
  for (int j = 0; j < m; ++j) {
    int i = p[j].second;
    if (i < n)
      dp[i] = 1;
    else
      dp[i] = ss[i / n - 1];
    ss[i / n] = (ss[i / n] + dp[i]) % Mod;
    if (i < l) {
      long long x = (l - 1 - i + n) / n;
      ans = (ans + (x % Mod) * dp[i]) % Mod;
    }
  }
  if (ans < 0) ans += Mod;
  printf("%d\n", ans);
}
