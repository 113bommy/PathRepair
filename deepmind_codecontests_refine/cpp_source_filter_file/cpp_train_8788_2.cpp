#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int N = 1e5 + 5;
int sze[N];
int p[N];
int dist[501][501];
int pref[501];
int find(int u) {
  while (p[u] != u) u = p[u];
  return u;
}
bool same(int u, int v) {
  ;
  return find(u) == find(v);
}
void connect(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  if (sze[u] < sze[v]) swap(u, v);
  sze[u] += sze[v];
  p[v] = u;
}
int n, m, k;
void solve() {
  for (int i = 0; i < N; i++) {
    sze[i] = 1;
    p[i] = i;
  }
  for (int i = 0; i < 501; i++) {
    for (int j = 0; j < 501; j++) {
      dist[i][j] = 1000000007;
      if (i == j) dist[i][j] = 0;
    }
  }
  cin >> n >> m >> k;
  int temp;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> temp;
    sum += temp;
    pref[i] = sum;
  }
  int u, v, x;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> x;
    --u;
    --v;
    if (x == 0) connect(u, v);
    int U = upper_bound(pref, pref + k, u) - pref;
    int V = upper_bound(pref, pref + k, v) - pref;
    assert(U < k);
    assert(V < k);
    ;
    dist[U][V] = min(dist[U][V], x);
    dist[V][U] = min(dist[V][U], x);
  }
  for (int i = 0; i < k; i++) {
    int low = 0;
    if (i > 0) low = pref[i - 1];
    int val = find(low);
    for (; low < pref[i]; low++) {
      if (find(low) != val) {
        cout << "No";
        return;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < k; l++) {
        dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
      }
    }
  }
  cout << "Yes \n";
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      assert(dist[i][j] == dist[j][i]);
      if (dist[i][j] == 1000000007)
        cout << "-1 ";
      else
        cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long test = 1;
  while (test--) {
    ;
    solve();
    cout << "\n";
  }
  return 0;
}
