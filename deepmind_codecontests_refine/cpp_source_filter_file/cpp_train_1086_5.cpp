#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFLL = 1e18;
const double EPS = 1e-8;
const long long int MOD = 1000000007;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
struct Unionfind {
  vector<int> size;
  vector<int> par;
  Unionfind() {}
  Unionfind(int n) : size(n, 1), par(n) {
    for (int i = (0); i < (int)(n); i++) par[i] = i;
  }
  void init(int n) {
    size.resize(n);
    par.resize(n);
    for (int i = (0); i < (int)(n); i++) {
      size[i] = 1;
      par[i] = i;
    }
  }
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (size[y] < size[x]) swap(x, y);
    par[x] = y;
    size[y] += size[x];
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
};
const int MAX_N = 100010;
Unionfind uf;
long long int n, m;
long long int a[MAX_N];
int x, y;
vector<int> G[MAX_N];
vector<pair<long long int, long long int> > ps;
long long int ans;
int main() {
  scanf("%lld %lld", &n, &m);
  for (int i = (0); i < (int)(n); i++) {
    scanf("%lld", &a[i]);
    ps.emplace_back(a[i], i);
  }
  sort((ps).begin(), (ps).end());
  reverse((ps).begin(), (ps).end());
  for (int i = (0); i < (int)(m); i++) {
    scanf("%d %d", &x, &y);
    x--;
    y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  uf.init(n);
  for (int i = (0); i < (int)(n); i++) {
    x = ps[i].second;
    long long int c = ps[i].first;
    for (auto &w : G[x]) {
      if (a[w] > c && !uf.same(w, x)) {
        ans += c * (long long int)uf.size[uf.find(x)] *
               (long long int)uf.size[uf.find(w)] * 2;
        uf.unite(w, x);
      }
    }
  }
  printf("%.12lf\n", (double)ans / (double)(n * (n - 1)));
  return 0;
}
