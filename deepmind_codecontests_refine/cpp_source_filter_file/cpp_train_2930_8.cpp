#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const vector<T>& v) {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
inline ostream& operator<<(ostream& o, const vector<T>& v) {
  if ((int)(v).size()) o << join(v);
  return o;
}
template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
inline long long int suma(const vector<T>& a) {
  long long int res(0);
  for (auto&& x : a) res += x;
  return res;
}
const double eps = 1e-10;
const long long int LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 250005;
struct DivideSet {
  multiset<long long int> ls, rs;
  int k;
  long long int l, r;
  DivideSet() : k(0), l(0), r(0) {}
  void ladd(long long int x) {
    ls.insert(x);
    l += x;
  }
  void radd(long long int x) {
    rs.insert(x);
    r += x;
  }
  void ldel(long long int x) {
    ls.erase(ls.find(x));
    l -= x;
  }
  void rdel(long long int x) {
    rs.erase(rs.find(x));
    r -= x;
  }
  void fix() {
    if ((int)(ls).size() && (int)(rs).size()) {
      while (1) {
        auto lt = ls.end();
        --lt;
        auto rt = rs.begin();
        long long int ltx = *lt, rtx = *rt;
        if (ltx <= rtx) break;
        ls.erase(lt);
        l -= ltx;
        ladd(rtx);
        rs.erase(rt);
        r -= rtx;
        radd(ltx);
      }
    }
    while ((int)(rs).size()) {
      auto it = rs.begin();
      if (*it > 0 && (int)(ls).size() >= k) break;
      ladd(*it);
      r -= *it;
      rs.erase(it);
    }
    while ((int)(ls).size() > k) {
      auto it = ls.end();
      --it;
      if (*it <= 0) break;
      radd(*it);
      l -= *it;
      ls.erase(it);
    }
  }
  long long int lx() { return (int)(ls).size() ? *(ls.rbegin()) : -LINF; }
  long long int rx() { return (int)(rs).size() ? *(rs.begin()) : LINF; }
  int size() { return (int)(ls).size() + (int)(rs).size(); }
  int lsz() { return (int)(ls).size(); }
  int rsz() { return (int)(rs).size(); }
  void add(long long int x) {
    radd(x);
    fix();
  }
  void del(long long int x) {
    if (lx() < x)
      rdel(x);
    else
      ldel(x);
    fix();
  }
  void inc() {
    ++k;
    fix();
  }
  void dec() {
    --k;
    fix();
  }
};
DivideSet ds[MX];
vector<int> to[MX], co[MX];
int pa[MX], pc[MX];
long long int val[MX];
void pfs(int v, int p = -1) {
  pa[v] = p;
  for (int i = 0; i < ((int)(to[v]).size()); ++i) {
    int u = to[v][i], c = co[v][i];
    if (u == p) continue;
    pfs(u, v);
    val[u] = pc[u] = c;
    ds[v].add(c);
  }
}
int deg[MX], act[MX];
vector<long long int> dp[MX];
long long int now;
void dfs(int v) {
  for (int i = 0; i < ((int)(to[v]).size()); ++i) {
    int u = to[v][i], c = co[v][i];
    ds[v].del(val[u]);
    dfs(u);
    val[u] = (dp[u][1] + c) - dp[u][0];
    ds[v].add(val[u]);
  }
  dp[v] = vector<long long int>(2, ds[v].l);
  dp[v][1] -= max(ds[v].lx(), 0ll);
  now += dp[v][0];
}
int main() {
  int n;
  scanf("%d", &n);
  long long int tot = 0;
  for (int i = 0; i < (n - 1); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    to[a].push_back(b);
    co[a].push_back(c);
    to[b].push_back(a);
    co[b].push_back(c);
    tot += c;
  }
  pfs(0);
  vector<vector<int> > dvs(n);
  for (int v = 0; v < (n); ++v) {
    deg[v] = (int)(to[v]).size();
    dvs[deg[v]].push_back(v);
    to[v] = co[v] = vector<int>();
  }
  vector<long long int> ans(n, tot);
  vector<int> vs;
  for (int i = (n)-1; i >= 0; --i)
    if (i) {
      for (int v : vs) ds[v].inc();
      for (int v : dvs[i]) {
        vs.push_back(v);
        act[v] = 1;
        if (pa[v] != -1) {
          to[pa[v]].push_back(v);
          co[pa[v]].push_back(pc[v]);
        }
      }
      now = 0;
      for (int v : vs) {
        if (pa[v] != -1 && act[pa[v]]) continue;
        dfs(v);
        if (pa[v] != -1) {
          now += max(0ll, (dp[v][1] + pc[v]) - dp[v][0]);
        }
      }
      ans[i] = now;
    }
  cout << ans << endl;
  return 0;
}
