#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1073741824")
#pragma warning(disable : 4996)
using namespace std;
const int N = 1010;
int lft[N][N], rgt[N][N], up[N][N], down[N][N], a[N][N];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  }
  for (int i = 1; i <= n; i++) {
    lft[i][0] = 0;
    rgt[i][m + 1] = m + 1;
  }
  for (int j = 1; j <= m; j++) {
    up[0][j] = 0;
    down[n + 1][j] = n + 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) up[i][j] = a[i][j] ? up[i - 1][j] : i;
  for (int i = n; i > 0; i--)
    for (int j = 1; j <= m; j++) down[i][j] = a[i][j] ? down[i + 1][j] : i;
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++) lft[i][j] = a[i][j] ? lft[i][j - 1] : j;
  for (int j = m; j > 0; j--)
    for (int i = 1; i <= n; i++) rgt[i][j] = a[i][j] ? rgt[i][j + 1] : j;
  while (q--) {
    int c, x, y;
    scanf("%d%d%d", &c, &x, &y);
    if (c == 1) {
      a[x][y] ^= 1;
      for (int i = x; i <= n; i++) up[i][y] = a[i][y] ? up[i - 1][y] : i;
      for (int i = x; i > 0; i--) down[i][y] = a[i][y] ? down[i + 1][y] : i;
      for (int i = y; i <= m; i++) lft[x][i] = a[x][i] ? lft[x][i - 1] : i;
      for (int i = y; i > 0; i--) rgt[x][i] = a[x][i] ? rgt[x][i + 1] : i;
    } else {
      int ans = 0;
      vector<pair<int, int>> st;
      int l[N];
      for (int i = 1; i <= m; i++) {
        while (!st.empty() && st.back().second <= up[x][i]) st.pop_back();
        l[i] = st.empty() ? 0 : st.back().first;
        st.push_back({i, up[x][i]});
      }
      st.clear();
      for (int i = m; i >= 1; i--) {
        while (!st.empty() && st.back().second <= up[x][i]) st.pop_back();
        int r = st.empty() ? m + 1 : st.back().first;
        st.push_back({i, up[x][i]});
        if (y > l[i] && y < r)
          ans = max(ans, (r - l[i] - 1) * abs(x - up[x][i]));
      }
      st.clear();
      for (int i = 1; i <= m; i++) {
        while (!st.empty() && st.back().second >= down[x][i]) st.pop_back();
        l[i] = st.empty() ? 0 : st.back().first;
        st.push_back({i, down[x][i]});
      }
      st.clear();
      for (int i = m; i >= 1; i--) {
        while (!st.empty() && st.back().second >= down[x][i]) st.pop_back();
        int r = st.empty() ? m + 1 : st.back().first;
        st.push_back({i, down[x][i]});
        if (y > l[i] && y < r)
          ans = max(ans, (r - l[i] - 1) * (abs(x - down[x][i])));
      }
      st.clear();
      for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.back().second <= lft[i][y]) st.pop_back();
        l[i] = st.empty() ? 0 : st.back().first;
        st.push_back({i, lft[i][y]});
      }
      st.clear();
      for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.back().second <= lft[i][y]) st.pop_back();
        int r = st.empty() ? n + 1 : st.back().first;
        st.push_back({i, lft[i][y]});
        if (x > l[i] && x < r)
          ans = max(ans, (r - l[i] - 1) * (abs(y - lft[i][y])));
      }
      st.clear();
      for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.back().second >= rgt[i][y]) st.pop_back();
        l[i] = st.empty() ? 0 : st.back().first;
        st.push_back({i, rgt[i][y]});
      }
      st.clear();
      for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.back().second >= rgt[i][y]) st.pop_back();
        int r = st.empty() ? n + 1 : st.back().first;
        st.push_back({i, rgt[i][y]});
        if (x > l[i] && x < r)
          ans = max(ans, (r - l[i] - 1) * (abs(y - rgt[i][y])));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
