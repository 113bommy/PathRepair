#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int ans[N], cnt[N], p[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int res = 1;
  ans[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> p[i], p[i]--;
    int v = i;
    while (v && ans[v] >= ans[p[v]]) {
      res = max(res, ans[v]);
      int u = p[v];
      int mem = ans[u];
      if (!u) ans[u] = ans[v] + 1;
      if (ans[v] > ans[u]) {
        ans[u] = ans[v];
        cnt[u] = 1;
      } else {
        if (ans[u] == ans[v] && ++cnt[u] > 1) {
          ans[u] = ans[v] + 1;
          cnt[u] = 0;
        }
      }
      v = p[v];
      res = max(res, ans[v]);
      if (ans[u] == mem) break;
    }
    cout << res << ' ';
  }
  return 0;
}
