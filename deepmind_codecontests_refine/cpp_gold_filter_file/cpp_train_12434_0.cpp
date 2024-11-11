#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], f[110];
vector<int> p[100010];
int main() {
  int i, j, k, n, m;
  int s, e;
  while (~scanf("%d%d%d%d", &n, &m, &s, &e)) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i < 100010; i++) p[i].clear();
    for (i = 1; i <= m; i++) {
      scanf("%d", &j);
      p[j].push_back(i);
    }
    int ans = 0;
    int lim = s / e + 1;
    for (i = 1; i <= lim + 2; i++) f[i] = 2000000007;
    f[0] = 0;
    for (i = 1; i <= n; i++) {
      for (j = lim; j >= 0; j--)
        if (f[j] <= m) {
          int second = f[j];
          int first = lower_bound(p[a[i]].begin(), p[a[i]].end(), second + 1) -
                      p[a[i]].begin();
          if (first < p[a[i]].size()) {
            k = p[a[i]][first];
            f[j + 1] = min(f[j + 1], k);
            int t = i + k;
            if (t <= n + m && t + (j + 1) * e <= s) ans = max(ans, j + 1);
          }
        }
    }
    printf("%d\n", ans);
  }
}
