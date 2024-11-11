#include <bits/stdc++.h>
using namespace std;
template <class T>
using vv = vector<vector<T>>;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "{";
  for (int(i) = 0; (i) < (t.size()); ++(i)) {
    os << t[i] << ",";
  }
  os << "}" << endl;
  return os;
}
template <class T, size_t n>
ostream &operator<<(ostream &os, const array<T, n> &t) {
  os << "{";
  for (int(i) = 0; (i) < (n); ++(i)) {
    os << t[i] << ",";
  }
  os << "}" << endl;
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T, class U>
ostream &operator<<(ostream &os, const tuple<S, T, U> &t) {
  return os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")";
}
template <class S, class T, class U, class V>
ostream &operator<<(ostream &os, const tuple<S, T, U, V> &t) {
  return os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ","
            << get<3>(t) << ")";
}
template <class T>
inline bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
inline bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
const long long MOD = 1e9 + 7;
void no() {
  printf("-1\n");
  exit(0);
}
void yes(vector<int> re) {
  int n = re.size();
  printf("%d\n", n - 1);
  for (int x : re) printf("%d ", x + 1);
  exit(0);
}
struct UF {
  vector<int> data;
  UF(int size) : data(size, -1) {}
  bool unite(int x, int y) {
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
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, int>> es;
  vv<int> g(n);
  for (int(i) = 0; (i) < (m); ++(i)) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    es.emplace_back(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  (n, m, es, 1);
  UF uf(n);
  for (pair<int, int> p : es) uf.unite(p.first, p.second);
  if (uf.findSet(0, n - 1)) {
    vector<int> dst(n, MOD);
    dst[0] = 0;
    vector<int> prv(n);
    queue<int> que;
    que.emplace(0);
    while (que.size()) {
      int v = que.front();
      que.pop();
      for (int w : g[v])
        if (MN(dst[w], dst[v] + 1)) {
          que.emplace(w);
          prv[w] = v;
        }
    }
    vector<int> re{n - 1};
    while (re.back()) {
      int t = prv[re.back()];
      re.push_back(t);
    }
    reverse((re).begin(), (re).end());
    (2, re, 1);
    if (re.size() > 4) {
      re.resize(3);
      re.push_back(0);
      re.push_back(n - 1);
    }
    (2, re, 1);
    yes(re);
  }
  {
    int cnt = 0;
    for (pair<int, int> e : es)
      if (uf.findSet(0, e.first)) ++cnt;
    long long t = uf.size(0);
    t *= t - 1;
    t /= 2;
    (cnt, t, uf.size(0), 1);
    if (t == cnt) no();
  }
  int N = uf.size(0);
  if (N == 2) no();
  (N, 1);
  {
    if (g[0].size() == N - 1) {
      set<pair<int, int>> st((es).begin(), (es).end());
      UF uf(n);
      for (int(i) = 1; (i) < (n); ++(i))
        for (int j : g[i])
          if (j) uf.unite(i, j);
      vector<int> cnt(n);
      for (int(i) = 1; (i) < (n); ++(i))
        for (int j : g[i])
          if (j > i) ++cnt[uf.root(j)];
      for (int v : g[0])
        if (uf.root(v) == v) {
          long long t = uf.size(v);
          t *= t - 1;
          t /= 2;
          if (t > cnt[v]) {
            int mn = MOD, w;
            for (int i : g[0])
              if (uf.findSet(v, i) && MN(mn, (int)g[i].size())) w = i;
            for (int v : g[w])
              if (v)
                for (int x : g[v])
                  if (x && x != w && st.count(pair<int, int>(x, w)) == 0 &&
                      st.count(pair<int, int>(w, x)) == 0)
                    yes({0, w, v, x, w, n - 1});
            assert(0);
          }
        }
      no();
    }
    vector<int> re{0};
    int rt = 0;
    (rt, 1);
    vector<int> A(n), B(n);
    for (int(i) = 0; (i) < (n); ++(i))
      if (uf.findSet(0, i) && i != rt && i != 0) B[i] = 1;
    for (int w : g[rt])
      if (w != 0) A[w] = 1, B[w] = 0;
    for (pair<int, int> e : es) {
      if (A[e.first] && B[e.second]) {
        re.push_back(e.first);
        re.push_back(e.second);
        re.push_back(rt);
        re.push_back(n - 1);
        yes(re);
      }
      if (A[e.second] && B[e.first]) {
        re.push_back(e.second);
        re.push_back(e.first);
        re.push_back(rt);
        re.push_back(n - 1);
        yes(re);
      }
    }
    assert(0);
  }
  return 0;
}
