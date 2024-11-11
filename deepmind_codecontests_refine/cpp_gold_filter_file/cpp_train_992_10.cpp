#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
template <class T, class U>
inline bool ifmax(T &x, U y) {
  if (y > x) return x = y, true;
  return false;
}
template <class T, class U>
inline bool ifmin(T &x, U y) {
  if (y < x) return x = y, true;
  return false;
}
long long fstpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
void fukof() {}
void problem() {}
const long long mod = 1e9 + 7;
const long long N = 200005;
const long long inf = 1e9;
vector<int> adj[N];
int dsu[N];
bool vis[N];
void dfs(int src) {
  if (vis[src])
    return;
  else
    vis[src] = true;
  if (src != adj[src][0]) dfs(adj[src][0]);
  dsu[src] = dsu[adj[src][0]];
}
void solve() {
  int n;
  cin >> n;
  memset(vis, 0, sizeof(vis));
  vector<int> a(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
  };
  for (long long i = (1); i < (1 + n); i++)
    adj[i].push_back(a[i - 1]), dsu[i] = i;
  for (long long i = 0; i < (n); i++) dfs(i + 1);
  vector<int> v;
  for (long long i = (1); i < (1 + n); i++) {
    v.push_back(dsu[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  ;
  if (v.size() == 1) {
    if (a[v[0] - 1] != v[0]) {
      cout << 1 << endl;
      a[v[0] - 1] = v[0];
      for (long long i = 0; i < (n); i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      ;
      ;
      return;
    } else {
      cout << 0 << endl;
      for (long long i = 0; i < (n); i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      ;
      ;
      return;
    }
  } else {
    int par = v[0];
    int ans = v.size() - 1;
    for (long long i = 0; i < (v.size()); i++) {
      if (a[v[i] - 1] == v[i]) par = v[i];
    }
    if (a[par - 1] != par) ans++;
    for (long long i = 0; i < (v.size()); i++) {
      a[v[i] - 1] = par;
    }
    cout << ans << endl;
    for (long long i = 0; i < (n); i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    ;
    ;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int tc = 1;
  while (tc--) {
    problem();
    fukof();
    solve();
  }
  return 0;
}
