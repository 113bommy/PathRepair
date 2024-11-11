#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 7;
vector<int> g[MAX], r[MAX], res;
bool mk[MAX], ans[MAX];
int n, m;
void prop(int x) {
  mk[x] = ans[x] = 1;
  for (int nn : g[x]) mk[nn] = 1;
}
void bkchk() {
  for (int i = 1; i <= n; ++i) {
    if (ans[i])
      for (int nn : r[i])
        if (ans[nn]) ans[i] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y), r[y].emplace_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!mk[i]) prop(i);
  }
  bkchk();
  for (int i = 1; i <= n; ++i)
    if (ans[i]) res.emplace_back(i);
  cout << res.size() << '\n';
  for (int x : res) cout << x << ' ';
  return 0;
}
