#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << p.first << ',' << p.second;
}
template <typename T>
struct point {
  T x, y;
  point(T xx = 0, T yy = 0) : x(xx), y(yy) {}
  T len2() const { return x * x + y * y; }
  double len() const { return sqrt(double(len2())); }
  bool operator==(const point<T>& p) const { return x == p.x && y == p.y; }
};
template <typename T>
point<T> operator+(const point<T>& a, const point<T>& b) {
  return point<T>(a.x + b.x, a.y + b.y);
}
template <typename T>
point<T> operator-(const point<T>& a, const point<T>& b) {
  return point<T>(a.x - b.x, a.y - b.y);
}
template <typename T>
T scal(const point<T>& a, const point<T>& b) {
  return a.x * b.x + a.y * b.y;
}
template <typename T>
T vect(const point<T>& a, const point<T>& b) {
  return a.x * b.y - a.y * b.x;
}
template <typename T>
ostream& operator<<(ostream& os, const point<T>& p) {
  return os << '(' << p.x << ',' << p.y << ')';
}
const int maxn = 1 << 20;
int parent[maxn];
int root;
vector<int> g[maxn];
int depth[maxn];
int lane[maxn];
set<int> whites[maxn];
pair<int, int> a[maxn];
vector<int> bases;
void dfs(int v, int par) {
  if (par < 0)
    depth[v] = 0;
  else
    depth[v] = depth[par] + 1;
  parent[v] = par;
  int z = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int p = g[v][i];
    if (p == par) continue;
    dfs(p, v);
    z++;
  }
  if (par >= 0) assert(z <= 1);
  if (z == 0) {
    for (int t = z; t != root; t = parent[t]) {
      lane[t] = v;
    }
    bases.push_back(v);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[i] = pair<int, int>(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  root = 0;
  for (int i = 0; i < n; i++)
    if (g[i].size() > g[root].size()) {
      root = i;
    }
  dfs(root, -1);
  int q;
  cin >> q;
  for (int i = 0; i < n - 1; i++) {
    if (depth[a[i].first] < depth[a[i].second]) swap(a[i].first, a[i].second);
  }
  for (int i = 0; i < q; i++) {
    int x, y, z;
    scanf("%d%d", &x, &y);
    y--;
    if (x == 3) {
      scanf("%d", &z);
      z--;
      if (y == z) {
        puts("0");
        continue;
      }
      if (z == root) swap(y, z);
      if (y == root) {
        int zz = lane[z];
        int dd = depth[z];
        if (whites[zz].size() && *whites[zz].begin() < dd) {
          puts("-1");
          continue;
        }
        printf("%d\n", dd);
        continue;
      }
      int d1 = depth[y];
      int d2 = depth[z];
      if (lane[y] == lane[z]) {
        int l = lane[y];
        if (d1 > d2) swap(d1, d2);
        set<int>::iterator it = whites[l].lower_bound(d1);
        if (it != whites[l].end() && *it < d2) {
          puts("-1");
          continue;
        }
        printf("%d\n", d2 - d1);
        continue;
      }
      int ly = lane[y];
      int lz = lane[z];
      if ((whites[ly].size() && *whites[ly].begin() < d1) ||
          (whites[lz].size() && *whites[lz].begin() < d2)) {
        puts("-1");
        continue;
      }
      printf("%d\n", d1 + d2);
    } else {
      int l = lane[a[y].first];
      int d = depth[a[y].second];
      if (x == 1) {
        assert(whites[l].count(d));
        whites[l].erase(d);
      } else if (x == 2) {
        assert(!whites[l].count(d));
        whites[l].insert(d);
      }
    }
  }
  return 0;
}
