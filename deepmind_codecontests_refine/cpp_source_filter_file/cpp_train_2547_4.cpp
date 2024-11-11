#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const int N = 3e5 + 5;
const int LOG = 19;
int n, m, x, y, _time;
vector<int> v[N];
pair<int, int> vc[2][N];
int sz[2];
int lca[LOG][N], dep[N];
int child[N], start[N], node[N], head[N], tail[N];
int suf[N << 1], order[N << 1], mylog[N << 1], lcp[LOG + 1][N << 1];
pair<int, int> C[N << 1];
char s[N], a[N << 1];
inline void dfs(int root = 0, int x = 1, int d = 1) {
  child[x] = 1;
  lca[0][x] = root;
  dep[x] = d;
  for (int i = 1; i <= LOG - 1; i++) lca[i][x] = lca[i - 1][lca[i - 1][x]];
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++)
    if (*it != root) {
      dfs(x, *it, d + 1);
      child[x] += child[*it];
    }
}
inline void dfs2(int root = 0, int x = 1, int h = 1) {
  head[x] = h;
  tail[h] = x;
  start[x] = ++_time;
  node[_time] = x;
  a[_time] = a[2 * n - _time + 1] = s[x];
  int mx = -1;
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++)
    if (*it != root) mx = max(mx, child[*it]);
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++)
    if (*it != root and child[*it] == mx) {
      dfs2(x, *it, h);
      break;
    }
  for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end(); it++)
    if (*it != root) {
      if (child[*it] == mx) {
        mx = -1;
        continue;
      }
      dfs2(x, *it, *it);
    }
}
int get(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = LOG - 1; i >= 0; i--)
    if (dep[x] - (1 << i) >= dep[y]) x = lca[i][x];
  if (x == y) return x;
  for (int i = LOG - 1; i >= 0; i--)
    if (lca[i][x] != lca[i][y]) {
      x = lca[i][x];
      y = lca[i][y];
    }
  return lca[0][x];
}
int get_lcp(int x, int y) {
  x = suf[x];
  y = suf[y];
  if (x == y) return 2 * n - order[x] + 1;
  if (x > y) swap(x, y);
  x++;
  int t = mylog[y - x + 1];
  return min(lcp[t][x], lcp[t][y - (1 << t) + 1]);
}
void get_vec(bool w, int a, int b, int x) {
  sz[w] = 0;
  while (dep[a] >= dep[x]) {
    int go = head[a];
    if (dep[x] > dep[go]) go = x;
    vc[w][sz[w]++] = make_pair(2 * n - start[a] + 1, dep[a] - dep[go] + 1);
    a = lca[0][go];
  }
  int st = sz[w];
  while (dep[b] > dep[x]) {
    int go = head[b];
    if (dep[x] >= dep[go]) go = node[start[x] + 1];
    vc[w][sz[w]++] = make_pair(start[go], dep[b] - dep[go] + 1);
    b = lca[0][go];
  }
  reverse(vc[w] + st, vc[w] + sz[w]);
}
int get_lcp(int a, int b, int x, int c, int d, int y) {
  get_vec(0, a, b, x);
  get_vec(1, c, d, y);
  int i = 0, j = 0;
  int ans = 0;
  while (i < sz[0] and j < sz[1]) {
    int res = get_lcp(vc[0][i].first, vc[1][j].first);
    if (res < vc[0][i].second and res < vc[1][j].second) return ans + res;
    if (vc[0][i].second == vc[1][j].second) {
      ans += vc[0][i].second;
      i++;
      j++;
      continue;
    }
    if (vc[0][i].second < vc[1][j].second) {
      ans += vc[0][i].second;
      vc[1][j].second -= vc[0][i].second;
      vc[1][j].first += vc[0][i].second;
      i++;
    } else {
      ans += vc[1][j].second;
      vc[0][i].second -= vc[1][j].second;
      vc[0][i].first -= vc[1][j].second;
      j++;
    }
  }
  return ans;
}
bool cmp(int x, int y) { return C[x] < C[y]; }
int main() {
  cin >> n;
  scanf("%s", s + 1);
  for (int i = 2; i <= n; i++) {
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs();
  dfs2();
  for (int i = 1; i <= 2 * n; i++) suf[i] = a[i];
  for (int i = 1; i <= 2 * n; i++) order[i] = i;
  for (int i = 1; i <= LOG + 2; i++) {
    for (int j = 1; j <= 2 * n; j++)
      C[j] = make_pair(suf[j],
                       j + (1 << i - 1) <= 2 * n ? suf[j + (1 << i - 1)] : 0);
    sort(order + 1, order + 2 * n + 1, cmp);
    for (int i = 1; i <= 2 * n; i++)
      suf[order[i]] = suf[order[i - 1]] + (C[order[i]] != C[order[i - 1]]);
  }
  int j = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (suf[i] == 1) continue;
    while (i + j <= 2 * n and order[suf[i] - 1] + j <= 2 * n and
           a[i + j] == a[order[suf[i] - 1] + j])
      j++;
    lcp[0][suf[i]] = j;
    if (j) j--;
  }
  for (int i = 2; i <= 2 * n; i++) mylog[i] = mylog[i >> 1] + 1;
  for (int i = 1; i <= LOG; i++)
    for (int j = 1; j <= 2 * n; j++)
      if (j + (1 << i) - 1 <= 2 * n)
        lcp[i][j] = min(lcp[i - 1][j], lcp[i - 1][j + (1 << i - 1)]);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    x = get(a, b);
    y = get(c, d);
    printf("%d\n", get_lcp(a, b, x, c, d, y));
  }
  return 0;
}
