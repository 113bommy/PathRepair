#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
char c[maxn][maxn];
static int dx[] = {-1, 0, 0, 1};
static int dy[] = {0, -1, 1, 0};
namespace dsu {
int fa[maxn * maxn];
int cnt[maxn * maxn];
int id(int x, int y) { return x * m + y; }
int findfa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = findfa(fa[x]);
}
void unite(int x, int y) {
  x = findfa(x);
  y = findfa(y);
  if (x == y) return;
  if (cnt[x] < cnt[y]) swap(x, y);
  fa[y] = x;
  cnt[x] += cnt[y];
}
}  // namespace dsu
using namespace dsu;
bool judge(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m) return 0;
  if (c[x][y] == '*') return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  for (int i = 0; i < n * m; i++) fa[i] = i, cnt[i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '*') continue;
      for (int k = 0; k < 4; k++) {
        int _i = i + dx[k];
        int _j = j + dy[k];
        if (!judge(_i, _j)) continue;
        int id1 = id(i, j);
        int id2 = id(_i, _j);
        unite(id1, id2);
      }
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] != '*') {
        cout << ".";
        continue;
      }
      set<int> st;
      for (int k = 0; k < 4; k++) {
        int _i = i + dx[k];
        int _j = j + dy[k];
        if (!judge(_i, _j)) continue;
        st.insert(findfa(id(_i, _j)));
      }
      int ans = 0;
      while (!st.empty()) {
        int id = *st.begin();
        st.erase(st.begin());
        ans += cnt[id];
      }
      cout << ans + 1;
    }
    cout << endl;
  }
  return 0;
}
