#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
const long long MOD = 998244353;
const long long mod = 1e9 + 7;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << v.first << ' ' << v.second;
  return os;
}
template <class T, class S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& v) {
  for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' ';
  return os;
}
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
clock_t time_p = clock();
void starboy1299() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long N = 3e5 + 100;
long long dp[N][3];
long long n;
long long arr[N];
long long f(long long idx, long long turn) {
  if (idx >= n) return 0;
  if (dp[idx][turn] != -1) return dp[idx][turn];
  long long ans = INT_MIN;
  if (turn == 0) {
    ans = max(ans, f(idx + 1, turn));
    ans = max(ans, arr[idx] + f(idx + 1, 1));
  } else {
    ans = max(ans, f(idx + 1, turn));
    ans = max(ans, -arr[idx] + f(idx + 1, 0));
  }
  return dp[idx][turn] = ans;
}
void solve() {
  long long q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  memset(dp, -1, sizeof(dp));
  cout << f(0, 0) << '\n';
}
int32_t main() {
  fast();
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  starboy1299();
}
