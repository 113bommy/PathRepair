#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5) + 5;
const long long is_query = -(1LL << 62), inf = 1e18;
struct Line {
  long long m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    long long x = rhs.m;
    return b - s->b < (s->m - m) * x;
  }
};
struct HullDynamic : public multiset<Line> {
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (long double)(x->b - y->b) * (z->m - y->m) >=
           (long double)(y->b - z->b) * (y->m - x->m);
  }
  void add(long long m, long long b) {
    auto y = insert({m, b});
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) {
      erase(y);
      return;
    }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  long long query(long long x) {
    auto l = *lower_bound((Line){x, is_query});
    return l.m * x + l.b;
  }
};
vector<int> mat[MAX];
int subT[MAX], maxC[MAX], lf[MAX], rg[MAX], ti, dfa[MAX];
long long A[MAX], B[MAX], prin[MAX];
void dfs(int p, int pa) {
  subT[p] = 1;
  maxC[p] = -1;
  lf[p] = ++ti;
  dfa[lf[p]] = p;
  for (int x : mat[p]) {
    if (x == pa) continue;
    dfs(x, p);
    subT[p] += subT[x];
    if (maxC[p] == -1)
      maxC[p] = x;
    else if (subT[maxC[p]] < subT[x])
      maxC[p] = x;
  }
  rg[p] = ti;
}
void dsu(int p, int pa, HullDynamic& use) {
  for (auto x : mat[p])
    if (x != pa && x != maxC[p]) {
      HullDynamic temp;
      dsu(x, p, temp);
    }
  if (maxC[p] != -1) dsu(maxC[p], p, use);
  for (int x : mat[p]) {
    if (x == pa || x == maxC[p]) continue;
    for (int i = lf[x]; i <= rg[x]; i++) {
      int pos = dfa[i];
      use.add(-B[pos], -prin[pos]);
    }
  }
  if (maxC[p] != -1)
    prin[p] = -use.query(A[p]);
  else
    prin[p] = 0;
  use.add(-B[p], -prin[p]);
}
int main() {
  ios::sync_with_stdio(false);
  int n, u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    mat[u].push_back(v);
    mat[v].push_back(u);
  }
  dfs(1, 1);
  HullDynamic use;
  dsu(1, 1, use);
  for (int i = 1; i <= n; i++) cout << prin[i] << ' ';
  return 0;
}
