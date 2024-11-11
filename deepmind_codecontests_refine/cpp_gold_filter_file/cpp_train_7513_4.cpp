#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
set<pair<int, int>> st;
long long ans;
int n, m;
bool isfind = false;
void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (x == n && y == m) {
    ans++;
    isfind = true;
    return;
  }
  if (isfind) return;
  if (st.count(make_pair(x, y))) return;
  if (x != 1 || y != 1) st.insert(make_pair(x, y));
  dfs(x + 1, y);
  dfs(x, y + 1);
}
int main() {
  cin >> n >> m;
  bool gg[4] = {false, false, false, false};
  getchar();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c = getchar();
      if (c == '#') {
        st.insert(make_pair(i, j));
        if (i == 2 && j == 1) {
          gg[0] = 1;
        } else if (i == 1 && j == 2) {
          gg[1] = 1;
        } else if (i == n - 1 && j == m)
          gg[2] = 1;
        else if (i == n && j == m - 1)
          gg[3] = 1;
      }
    }
    getchar();
  }
  if ((gg[0] && gg[1]) || (gg[2] && gg[3])) {
    cout << 0 << endl;
    return 0;
  }
  dfs(1, 1);
  isfind = false;
  dfs(1, 1);
  if (gg[0] || gg[1]) ans = min(ans, 1ll);
  if (gg[2] || gg[3]) ans = min(ans, 1ll);
  cout << min(ans, 2ll) << endl;
  return 0;
}
