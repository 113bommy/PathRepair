#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d %d %d %d", &a[i], &b[i], &c[i], &d[i], &e[i]);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i != j && j != k && i != k) {
          long long x1 = a[j] - a[i], x2 = b[j] - b[i], x3 = c[j] - c[i],
                    x4 = d[j] - d[i], x5 = e[j] - e[i];
          long long y1 = a[k] - a[i], y2 = b[k] - b[i], y3 = c[k] - c[i],
                    y4 = d[k] - d[i], y5 = e[k] - e[i];
          long long z = x1 * y1 + x2 * y2 + x3 * y3 + x4 * y4 + x5 * y5;
          if (z > 0) {
            flag = 1;
          }
        }
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
    if (flag == 0) ans.push_back(i);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
  return 0;
}
