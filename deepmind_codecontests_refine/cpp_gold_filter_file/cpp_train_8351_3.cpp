#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const unordered_map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y / 2, x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
char arr[14][14];
vector<long long> dp[1 << 14][14];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  char arr[n][n];
  for (long long i = 0; i < (n); ++i)
    for (long long j = 0; j < (n); ++j) cin >> arr[i][j];
  for (long long i = 0; i < (1 << n); ++i)
    for (long long j = 0; j < (n); ++j) {
      if (i & (1 << j))
        for (long long k = 0; k < (((1 << __builtin_popcount(i)) - 1)); ++k)
          dp[i][j].emplace_back(0);
    }
  for (long long i = 0; i < (n); ++i) dp[1 << i][i][0] = 1;
  for (long long i = 0; i < (1 << n); ++i) {
    for (long long j = 0; j < (n); ++j) {
      if (i & (1 << j)) {
        for (long long k = 0; k < (((1 << __builtin_popcount(i)) - 1)); ++k) {
          if (!dp[i][j][k]) continue;
          for (long long p = 0; p < (n); ++p) {
            if (i & (1 << p)) continue;
            dp[i | (1 << p)][p][k * 2 + (arr[j][p] - '0')] += dp[i][j][k];
          }
        }
      }
    }
  }
  long long ans[1 << (n - 1)];
  for (long long i = 0; i < (1 << (n - 1)); ++i) ans[i] = 0;
  for (long long i = 0; i < (n); ++i)
    for (long long j = 0; j < (1 << (n - 1)); ++j)
      ans[j] += dp[(1 << n) - 1][i][j];
  for (long long i = 0; i < (1 << (n - 1)); ++i) cout << ans[i] << " ";
}
