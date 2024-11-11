#include <bits/stdc++.h>
using namespace std;
void _dbg(string) { cout << endl; }
template <class H, class... T>
void _dbg(string s, H h, T... t) {
  int l = s.find(',');
  cout << s.substr(0, l) << " = " << h << ", ";
  _dbg(s.substr(l + 1), t...);
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U> &p) {
  o << "(" << p.first << "," << p.second << ")";
  return o;
}
template <class T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
class UnionFind {
 public:
  vector<int> par, rank;
  UnionFind(int sz) : par(sz, -1), rank(sz, 0) {}
  int find(int x) {
    if (par[x] < 0)
      return x;
    else
      return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[y] += par[x];
      par[x] = y;
    } else {
      par[x] += par[y];
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  inline bool same(int x, int y) { return find(x) == find(y); }
  inline int size(int x) { return -par[find(x)]; }
};
bool checked[200005];
int x[100005], y[100005];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> sx, sy;
  for (int i = (int)(0); i < (int)(n); i++) {
    scanf("%d %d", x + i, y + i);
    sx.push_back((x[i]));
    sy.push_back((y[i]));
  }
  sort((sx).begin(), (sx).end()),
      (sx).erase(unique((sx).begin(), (sx).end()), end(sx));
  sort((sy).begin(), (sy).end()),
      (sy).erase(unique((sy).begin(), (sy).end()), end(sy));
  int m = sx.size() + sy.size();
  UnionFind uf(m);
  for (int i = (int)(0); i < (int)(n); i++) {
    int ix = lower_bound((sx).begin(), (sx).end(), x[i]) - sx.begin();
    int iy = lower_bound((sy).begin(), (sy).end(), y[i]) - sy.begin();
    iy += sx.size();
    uf.unite(ix, iy);
  }
  vector<int> sz(m, 0);
  for (int i = (int)(0); i < (int)(n); i++) {
    int id = lower_bound((sx).begin(), (sx).end(), x[i]) - sx.begin();
    sz[uf.find(id)]++;
  }
  vector<long long> pow2(n + 5);
  pow2[0] = 1;
  for (int i = (int)(0); i < (int)(n); i++)
    pow2[i + 1] = pow2[i] * 2 % 1000000007;
  long long ans = 1;
  for (int i = (int)(0); i < (int)(m); i++)
    if (uf.par[i] < 0) {
      long long mul = pow2[uf.size(i)];
      if (uf.size(i) - 1 == sz[i]) mul--;
      ans = ans * mul % 1000000007;
    }
  cout << ans % 1000000007 << endl;
  return 0;
}
