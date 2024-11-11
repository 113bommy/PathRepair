#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long N = 102;
long long n, k;
vector<long long> adj[N];
void dfs(long long node, long long par, long long sub_index, long long dep,
         long long &max_dep, vector<vector<long long>> &cnt) {
  cnt[dep][sub_index]++;
  max_dep = max(max_dep, dep);
  for (auto i : adj[node]) {
    if (i == par) continue;
    ;
    dfs(i, node, sub_index, dep + 1, max_dep, cnt);
  }
}
long long rec(long long pos, long long setsize, long long &dep, long long &root,
              vector<vector<long long>> &cnt, vector<vector<long long>> &dp) {
  if (pos == (long long)adj[root].size()) {
    return setsize == k;
  }
  if (dp[pos][setsize] != -1) return dp[pos][setsize];
  long long ans = 0;
  if (setsize + 1 < k)
    ans = (ans % 1000000007 + (rec(pos + 1, setsize + 1, dep, root, cnt, dp) %
                               1000000007 * cnt[dep][pos] % 1000000007) %
                                  1000000007) %
          1000000007;
  ans = (ans % 1000000007 +
         rec(pos + 1, setsize, dep, root, cnt, dp) % 1000000007) %
        1000000007;
  return dp[pos][setsize] = ans;
}
void solve() {
  cin >> n >> k;
  for (long long i = 0; i <= n; i++) adj[i].clear();
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (k == 2) {
    long long ans = (n * (n - 1) / 2) % 1000000007;
    cout << ans << "\n";
    return;
  }
  long long ans = 0;
  for (long long root = 0; root < n; root++) {
    vector<vector<long long>> cnt(
        n + 1, vector<long long>((long long)adj[root].size() + 1));
    long long sub_index = 0;
    long long max_dep = 1;
    for (auto i : adj[root]) {
      dfs(i, root, sub_index, 1, max_dep, cnt);
      sub_index++;
    }
    for (long long i = 1; i <= max_dep; i++) {
      vector<vector<long long>> dp((long long)adj[root].size(),
                                   vector<long long>(k + 1, -1));
      long long dep = i;
      ans = (ans % 1000000007 + rec(0, 0, dep, root, cnt, dp) % 1000000007) %
            1000000007;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
