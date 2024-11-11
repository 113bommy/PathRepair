#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acos(-1.0);
const int INF = -10000000;
const pair<int, int> prototype(INF, INF);
int n, m;
bool ok = false;
inline int p(int x, int n) {
  int r = ((x % n) + n) % n;
  return r;
}
char a[1500][1500];
pair<int, int> v[1500][1500];
set<int> st;
void dfs(int x, int y, int from) {
  if (!ok) {
    pair<int, int> cur(x, y);
    int tm = x * 931 + y * 931 * 931;
    if (!st.count(tm))
      st.insert(tm);
    else
      return;
    pair<int, int> z = v[p(x, n)][p(y, m)];
    if (z != prototype && z != pair<int, int>(x, y)) {
      ok = true;
      return;
    }
    v[p(x, n)][p(y, m)] = make_pair(x, y);
    if (from != 1 && a[p(x - 1, n)][p(y, m)] != '#') dfs(x - 1, y, 3);
    if (from != 2 && a[p(x, n)][p(y + 1, m)] != '#') dfs(x, y + 1, 4);
    if (from != 3 && a[p(x + 1, n)][p(y, m)] != '#') dfs(x + 1, y, 1);
    if (from != 4 && a[p(x, n)][p(y - 1, m)] != '#') dfs(x, y - 1, 2);
  }
}
int main() {
  for (int i = 0; i < 1500; ++i)
    for (int j = 0; j < 1500; ++j) v[i][j] = prototype;
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; ++i) gets(a[i]);
  int x = -1, y = -1;
  for (int i = 0; i < n && x == -1; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 'S') {
        x = i;
        y = j;
        break;
      }
  dfs(x, y, 0);
  puts(ok ? "Yes" : "No");
  return 0;
}
