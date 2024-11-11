#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long x[255], y[255];
int ans[maxn];
int solve() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i < n + 1; ++i) ans[i] = 1;
  for (int i = 0; i < m; ++i) scanf("%lld", &x[i]), scanf("%lld", &y[i]);
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j < m; ++j) {
      if (y[i] == y[j] || (x[i] - x[j]) * y[i] % (y[i] - y[j])) continue;
      long long t = x[i] + (x[i] - x[j]) * y[i] / (y[i] - y[j]);
      if (t >= 1 && t <= n) {
        int cnt(0);
        for (int k = 0; k < m; ++k)
          if ((x[i] - x[k]) * (y[j] - y[k]) == (x[j] - x[k]) * (y[i] - y[k]))
            cnt++;
        ans[t] = max(ans[t], cnt);
      }
    }
  int cnt(0);
  for (int i = 1; i < n + 1; ++i) cnt += ans[i];
  return printf("%d\n", cnt);
}
int main() { solve(); }
