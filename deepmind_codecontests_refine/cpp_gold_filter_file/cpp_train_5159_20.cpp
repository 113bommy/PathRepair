#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
const long double eps = 1e-14;
const long double eps2 = 1e-9;
const long double INF = 1 << 30;
inline int dcmp(const long double& x) {
  return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);
}
template <typename T>
inline bool getmin(T& a, const T& b) {
  return dcmp(b - a) < 0 ? (a = b, true) : false;
}
template <typename T>
inline bool getmax(T& a, const T& b) {
  return dcmp(b - a) > 0 ? (a = b, true) : false;
}
struct Iron {
  int show, speed, st, ed;
  inline void read() {
    scanf("%d%d%d%d", &show, &speed, &st, &ed);
    st--, ed--;
  }
} iron[maxm];
struct Iron2 {
  long double from, fromt, to, tot;
};
struct Path {
  int id, from, to;
};
struct Event {
  long double t;
  int segid;
  bool operator<(const Event& rhs) const { return dcmp(t - rhs.t) < 0; }
};
int n, m;
vector<int> G[maxn], chain[maxn];
int fa[maxn], dep[maxn], chainid[maxn], size[maxn];
int pre[maxn], dfs_clock;
void dfs(int now) {
  vector<int>& vec = chain[chainid[now]];
  for (int i = ((int)(vec.size())) - 1; i >= 0; i--) pre[vec[i]] = dfs_clock++;
  for (int i = 0; i < ((int)(vec.size())); i++) {
    int now = vec[i];
    for (const int& to : G[now])
      if ((!i || to != vec[i - 1]) && to != fa[now]) dfs(to);
  }
}
inline void make_HLD() {
  int first = 0, last = 0;
  int* q = new int[n];
  q[last++] = 0;
  fa[0] = -1;
  dep[0] = 0;
  while (last - first > 0) {
    int now = q[first++];
    for (const int& to : G[now])
      if (to != fa[now]) {
        fa[to] = now;
        dep[to] = dep[now] + 1;
        q[last++] = to;
      }
  }
  for (int i = last - 1; i >= 0; i--) {
    int now = q[i], hs = -1;
    size[now] = 1;
    for (const int& to : G[now])
      if (to != fa[now]) {
        size[now] += size[to];
        if (hs < 0 || size[to] > size[hs]) hs = to;
      }
    if (hs < 0)
      chainid[now] = now;
    else
      chainid[now] = chainid[hs];
    chain[chainid[now]].push_back(now);
  }
  dfs_clock = 0;
  delete[] q;
  dfs(0);
}
inline bool inrange(const long double& x, const long double& L,
                    const long double& R) {
  return dcmp(x - L) >= 0 && dcmp(x - R) <= 0;
}
inline long double getIntersectime(const Iron2& A, const Iron2& B) {
  const long double &x1 = A.from, &t1 = A.fromt, &x2 = A.to, &t2 = A.tot,
                    &x3 = B.from, &t3 = B.fromt, &x4 = B.to, &t4 = B.tot;
  long double deno = (x2 - x1) * (t4 - t3) - (t2 - t1) * (x4 - x3);
  long double nume = (x3 - x1) * (t2 - t1) * (t4 - t3) -
                     t3 * (t2 - t1) * (x4 - x3) + t1 * (t4 - t3) * (x2 - x1);
  if (dcmp(deno) == 0) {
    if (dcmp((t2 - t1) * (x3 - x1) - (t3 - t1) * (x2 - x1)) != 0) return INF;
    long double f1 = ((t2 - t1) * (t3 - t1) + (x2 - x1) * (x3 - x1)) /
                     ((t2 - t1) * (t2 - t1) + (x2 - x1) * (x2 - x1));
    long double f2 = ((t2 - t1) * (t4 - t1) + (x2 - x1) * (x4 - x1)) /
                     ((t2 - t1) * (t2 - t1) + (x2 - x1) * (x2 - x1));
    if (dcmp(f1) < 0 && dcmp(f2) < 0) return INF;
    if (dcmp(f1 - 1) > 0 && dcmp(f2 - 1) > 0) return INF;
    long double f = max(0.l, min(f1, f2));
    return t1 + (t2 - t1) * f;
  }
  long double ans = nume / deno;
  if (inrange(ans, max(t1, t3), min(t2, t4)))
    return ans;
  else
    return INF;
}
long double curtime;
vector<Iron2> vec;
struct cmp {
  inline long double getpos(const Iron2& I, const long double& t) const {
    return I.from + ((I.to - I.from) / (I.tot - I.fromt)) * (t - I.fromt);
  }
  bool operator()(const int& a, const int& b) const {
    long double d1 = dcmp(getpos(vec[a], curtime) - getpos(vec[b], curtime)),
                d2 = dcmp(getpos(vec[a], curtime + 1) -
                          getpos(vec[b], curtime + 1));
    return d1 < 0 || (d1 == 0 && d2 < 0) || (d1 == 0 && d2 == 0 && a < b);
  }
};
vector<Iron2> Seg[maxn];
inline long double solve_path(const int& nowSeg) {
  vec = Seg[nowSeg];
  set<int, cmp> S;
  vector<Event> eve;
  for (int i = 0; i < ((int)(vec.size())); i++)
    eve.push_back((Event){vec[i].fromt, i << 1}),
        eve.push_back((Event){vec[i].tot, i << 1 | 1});
  sort(eve.begin(), eve.end());
  long double ans = INF;
  for (const Event& e : eve) {
    curtime = e.t;
    if (dcmp(curtime - ans) >= 0) break;
    int id = e.segid;
    if (!(id & 1)) {
      id /= 2;
      set<int>::iterator it = S.lower_bound(id);
      assert(S.find(id) == S.end());
      if (it != S.end()) getmin(ans, getIntersectime(vec[id], vec[*it]));
      if (it != S.begin())
        it--, getmin(ans, getIntersectime(vec[id], vec[*it]));
      S.insert(id);
    } else {
      id /= 2;
      set<int>::iterator it = S.lower_bound(id), itL = it, itR = it;
      assert((*it) == id);
      itR++;
      if (itL != S.begin() && itR != S.end()) {
        itL--;
        getmin(ans, getIntersectime(vec[*itL], vec[*itR]));
      }
      S.erase(it);
    }
  }
  return ans;
}
vector<Path> path, L, R;
inline void getPath(int a, int b) {
  L.clear();
  R.clear();
  while (chainid[a] != chainid[b]) {
    int atop = chain[chainid[a]].back(), btop = chain[chainid[b]].back();
    if (dep[atop] > dep[btop])
      L.push_back((Path){chainid[a], a, fa[atop]}), a = fa[atop];
    else
      R.push_back((Path){chainid[b], fa[btop], b}), b = fa[btop];
  }
  L.push_back((Path){chainid[a], a, b});
  path.clear();
  for (int i = 0; i < ((int)(L.size())); i++) path.push_back(L[i]);
  for (int i = ((int)(R.size())) - 1; i >= 0; i--) path.push_back(R[i]);
}
inline int PosOnPath(int id, int now) {
  if (chainid[now] != id) return 0;
  return pre[now] - pre[chain[id].back()] + 1;
}
inline long double solve_tree() {
  make_HLD();
  for (int i = 0; i < m; i++) {
    getPath(iron[i].st, iron[i].ed);
    long double curt = iron[i].show, v = iron[i].speed;
    for (const Path& p : path) {
      int from = PosOnPath(p.id, p.from), to = PosOnPath(p.id, p.to);
      long double arrt = curt + abs(to - from) / v;
      long double cc = dcmp(arrt - curt) == 0 ? 0 : (to - from) / (arrt - curt);
      Seg[p.id].push_back(
          (Iron2){from - eps2 * cc, curt - eps2, to + eps2 * cc, arrt + eps2});
      curt = arrt;
    }
  }
  long double res = INF;
  for (int i = 0; i < n; i++) getmin(res, solve_path(i));
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < m; i++) iron[i].read();
  long double ans = solve_tree();
  if (dcmp(ans - INF) >= 0)
    printf("-1\n");
  else
    printf("%.13f\n", (double)ans);
}
