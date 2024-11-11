#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++) os << ", ";
    os << val;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using si = set<int>;
using mpii = map<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
template <class T>
inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<unordered_set<int>> e(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[u].insert(v);
    e[v].insert(u);
  }
  if (1LL * k * (k - 1) > m * 2) {
    cout << "-1" << endl;
    return;
  }
  vi deg(n);
  deque<int> que;
  vi vis(n, 0);
  for (int i = 0; i < n; i++) {
    deg[i] = ((int)(e[i]).size());
    if (deg[i] < k) {
      vis[i] = 1;
      que.push_back(i);
    }
  }
  vi clique;
  while (!que.empty()) {
    int u = que.front();
    vis[u] = 2;
    que.pop_back();
    if (deg[u] == k - 1 && clique.empty()) {
      clique.push_back(u);
      for (int v : e[u]) {
        if (vis[v] <= 1) {
          clique.push_back(v);
        }
      }
      assert(((int)(clique).size()) == k);
      bool ok = 1;
      for (int x : clique) {
        for (int y : clique) {
          if (x == y) continue;
          if (e[x].count(y) == 0) {
            ok = 0;
            break;
          }
        }
        if (!ok) break;
      }
      if (!ok) clique.clear();
    }
    for (int v : e[u]) {
      deg[v]--;
      if (deg[v] < k && !vis[v]) {
        que.push_back(v);
        vis[v] = 1;
      }
    }
  }
  if (count((vis).begin(), (vis).end(), 0) >= k) {
    vi ans;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ans.push_back(i);
      }
    }
    int cnt = ((int)(ans).size());
    cout << 1 << ' ' << cnt << endl;
    for (int i = 0; i < cnt; i++) {
      cout << ans[i] + 1 << " \n"[i == cnt - 1];
    }
  } else if (!clique.empty()) {
    cout << "2\n";
    int cnt = ((int)(clique).size());
    for (int i = 0; i < cnt; i++) {
      cout << clique[i] + 1 << " \n"[i == cnt - 1];
    }
  } else {
    cout << "-1" << endl;
  }
}
void solve(int _cas) { solve(); }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL), cout.precision(12);
  int cas;
  cin >> cas;
  for (int i = 0; i < (cas); i++) solve(i + 1);
}
