#include <bits/stdc++.h>
using namespace std;
struct query {
  int u, v, t;
};
namespace std {
string to_string(string const &s) { return '"' + s + '"'; }
string to_string(char c) { return string(1, c); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(query const &q) {
  return "(" + to_string(q.u) + " " + to_string(q.v) + " " + to_string(q.t) +
         ")";
}
template <class T1, class T2>
string to_string(pair<T1, T2> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class T>
string to_string(T c) {
  string s = "[";
  for (auto vvv : c) {
    s += to_string(vvv) + ",";
  }
  s += "]";
  return s;
}
void debug_impl() { cerr << endl; };
template <typename T1, typename... T2>
void debug_impl(T1 a, T2... b) {
  cerr << " " << to_string(a);
  debug_impl(b...);
}
}  // namespace std
struct change {
  int t;
  void *ptr;
  long long val;
};
int dsu[2000000];
pair<int, int> dsu_sz[2000000];
vector<change> dsu_changes;
long long ans;
vector<query> q;
vector<int> res;
vector<vector<pair<int, int>>> st;
void _set(int &x, int v) {
  change c;
  c.t = 0;
  c.ptr = &x;
  c.val = x;
  dsu_changes.push_back(c);
  x = v;
}
void _set(long long &x, long long v) {
  change c;
  c.t = 1;
  c.ptr = &x;
  c.val = x;
  dsu_changes.push_back(c);
  x = v;
}
int dsu_get(int v) {
  if (v == dsu[v]) {
    return v;
  }
  int t = dsu_get(dsu[v]);
  _set(dsu[v], t);
  return t;
}
void dsu_join(int u, int v) {
  u = dsu_get(u);
  v = dsu_get(v);
  if (u == v) {
    return;
  }
  if (dsu_sz[u].first + dsu_sz[u].second < dsu_sz[v].first + dsu_sz[v].second) {
    swap(u, v);
  }
  long long new_ans = ans + 1LL * (dsu_sz[u].first * dsu_sz[v].second) +
                      1LL * (dsu_sz[v].first * dsu_sz[u].second);
  _set(dsu[v], u);
  auto new_sz = make_pair(dsu_sz[u].first + dsu_sz[v].first,
                          dsu_sz[u].second + dsu_sz[v].second);
  _set(dsu_sz[u].first, new_sz.first);
  _set(dsu_sz[u].second, new_sz.second);
  _set(ans, new_ans);
}
void addST(int tv, int tl, int tr, int l, int r, int u, int v) {
  if (l >= r) return;
  if (l == tl && r == tr) {
    st[tv].push_back({u, v});
    return;
  }
  int tm = (tl + tr) / 2;
  addST(tv * 2 + 1, tl, tm, l, min(r, tm), u, v);
  addST(tv * 2 + 2, tm, tr, max(l, tm), r, u, v);
}
void undo(change &c) {
  if (c.t == 1) {
    long long *ptr = static_cast<long long *>(c.ptr);
    *ptr = c.val;
  } else {
    int *ptr = static_cast<int *>(c.ptr);
    *ptr = static_cast<int>(c.val);
  }
}
void dfsST(int v, int tl, int tr) {
  int s = dsu_changes.size();
  for (auto &p : st[v]) {
    dsu_join(p.first, p.second);
  }
  if (tr == tl + 1) {
    if (tl < q.size() && q[tl].t == 0) {
      res[tl] = ans;
    }
  } else {
    int tm = (tl + tr) / 2;
    dfsST(v * 2 + 1, tl, tm);
    dfsST(v * 2 + 2, tm, tr);
  }
  while (dsu_changes.size() > s) {
    auto p = dsu_changes.back();
    undo(p);
    dsu_changes.pop_back();
  }
}
int compress(vector<int> &a) {
  int res = 0;
  map<int, int> m;
  for (int x : a) {
    if (!m.count(x)) {
      m[x] = res;
      res++;
    }
  }
  for (int &x : a) x = m[x];
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> xs(n);
  vector<int> ys(n);
  for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];
  int xc = compress(xs);
  int yc = compress(ys);
  ;
  ;
  int N = xc + yc;
  for (int i = 0; i < N; i++) {
    dsu[i] = i;
    if (i < xc)
      dsu_sz[i] = make_pair(1, 0);
    else
      dsu_sz[i] = make_pair(0, 1);
  }
  ans = 0;
  set<pair<int, int>> edges;
  query question;
  question.t = 0;
  question.u = question.v = -1;
  for (int i = 0; i < n; i++) {
    int u = xs[i];
    int v = xc + ys[i];
    auto it = edges.find({u, v});
    query _q;
    _q.u = u;
    _q.v = v;
    if (it == edges.end()) {
      edges.emplace(u, v);
      _q.t = 1;
    } else {
      edges.erase(it);
      _q.t = 2;
    }
    q.push_back(_q);
    q.push_back(question);
  };
  ;
  int k = q.size();
  map<pair<int, int>, vector<int>> qm;
  for (int i = 0; i < k; i++) {
    auto &x = q[i];
    if (x.t) {
      qm[{x.u, x.v}].push_back(i);
    }
  }
  st.resize((k + 1) * 4);
  for (auto &p : qm) {
    if (p.second.size() % 2) {
      p.second.push_back(k);
    }
    for (int i = 0; i < p.second.size(); i += 2) {
      int u = p.first.first;
      int v = p.first.second;
      int l = p.second[i];
      int r = p.second[i + 1];
      ;
      ;
      addST(0, 0, k + 1, l, r, u, v);
    }
  }
  res.resize(k);
  dfsST(0, 0, k + 1);
  for (int i = 0; i < k; i++) {
    if (!q[i].t) {
      cout << res[i] << " ";
    }
  }
  cout << endl;
  return 0;
}
