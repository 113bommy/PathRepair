#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
struct UnionFind {
  vector<int> data;
  UnionFind(int size = 0) : data(size, -1) {}
  bool unionSet(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};
int n, m;
UnionFind uf;
vector<vector<int> > g;
int size[2001][2001];
int memo[2001][2001];
int rec(int r, int p) {
  if (p != -1 && memo[r][p] != 0) return memo[r][p];
  int rnum = uf.size(r);
  if (p == -1) {
    vector<int> childs;
    int res = rnum * rnum;
    for (__typeof((g[r]).begin()) v = (g[r]).begin(); v != (g[r]).end(); v++)
      if (*v != p) {
        res += rec(*v, r);
        res += size[*v][r] * rnum;
        childs.push_back(size[*v][r]);
      }
    vector<int> dp(2001);
    dp[0] = 1;
    for (int i = 0; i < (int)(childs.size()); i++) {
      for (int j = ((int)(2001 - childs[i]) - 1); j >= 0; j--) {
        dp[j + childs[i]] |= dp[j];
      }
    }
    int mm = 0;
    for (int i = 0; i < (int)(n - rnum); i++) {
      if (dp[i]) mm = max(mm, i * (n - rnum - i));
    }
    return res + mm;
  } else {
    memo[r][p] = rnum * rnum;
    size[r][p] = rnum;
    for (__typeof((g[r]).begin()) v = (g[r]).begin(); v != (g[r]).end(); v++)
      if (*v != p) {
        memo[r][p] += rec(*v, r);
        memo[r][p] += rnum * size[*v][r];
        size[r][p] += size[*v][r];
      }
    return memo[r][p];
  }
}
int BCCdfs(int r, int p, vector<vector<int> > &g, vector<int> &steps,
           vector<int> &visited, UnionFind &uf, int step) {
  if (visited[r] >= 1) return steps[r];
  steps[r] = step;
  visited[r]++;
  int minstep = INF;
  for (__typeof((g[r]).begin()) v = (g[r]).begin(); v != (g[r]).end(); v++)
    if (*v != p) {
      int ret = BCCdfs(*v, r, g, steps, visited, uf, step + 1);
      if (ret <= step) uf.unionSet(r, *v);
      chmin(minstep, ret);
    }
  return minstep;
}
UnionFind BCC(vector<vector<int> > &g) {
  vector<int> steps(g.size());
  vector<int> visited(g.size());
  uf = UnionFind(g.size());
  for (int i = 0; i < (int)(g.size()); i++)
    if (visited[i]) BCCdfs(i, -1, g, steps, visited, uf, 0);
  return uf;
}
int main() {
  scanf("%d%d", &n, &m);
  g = vector<vector<int> >(n);
  for (int i = 0; i < (int)(m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  UnionFind uf = BCC(g);
  vector<vector<int> > g2(n);
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(g[i].size()); j++) {
      if (uf.root(i) != uf.root(g[i][j])) {
        g2[uf.root(i)].push_back(uf.root(g[i][j]));
        g2[uf.root(g[i][j])].push_back(uf.root(i));
      }
    }
  }
  for (int i = 0; i < (int)(n); i++) {
    sort(g2[i].begin(), g2[i].end());
    g2[i].erase(unique(g2[i].begin(), g2[i].end()), g2[i].end());
    ;
  }
  g = g2;
  int ans = 0;
  for (int i = 0; i < (int)(n); i++)
    if (uf.root(i) == i) {
      ans = max(ans, rec(i, -1));
    }
  cout << ans << endl;
  return 0;
}
