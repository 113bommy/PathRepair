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
long long dp[5001][5001];
long long parent[2][5001 * 2];
long long arr[500001];
long long ans[500001];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long i, j;
  for (i = 1; i < n; i++) cin >> arr[i];
  for (i = 1; i < n; i++) {
    dp[i][1] = arr[i];
    for (j = 2; j < n; j++) {
      dp[i][j] = dp[i][j - 1] * arr[i + j - 1] % 1000000007;
    }
  }
  long long ff = 1;
  long long bakwass = 1;
  for (i = 2; i <= n; i++) {
    ff *= arr[i - 1];
    ff %= 1000000007;
    long long temp[5001 * 2] = {0};
    for (j = 1; j < n; j++) temp[j] = dp[i - 1][j];
    long long f = 1;
    temp[1] -= 1;
    temp[1] += 1000000007;
    temp[1] %= 1000000007;
    for (j = 2; j < n; j++) {
      f = f * arr[i + j - 2] % 1000000007;
      temp[j] -= f;
      temp[j] += 1000000007;
      temp[j] %= 1000000007;
    }
    parent[bakwass][1] = 1;
    for (j = 2; j < 2 * n; j++) {
      parent[bakwass][j] = parent[1 - bakwass][j - 1] + temp[j - 1];
      parent[bakwass][j] %= 1000000007;
    }
    for (j = 1; j < 2 * n; j++) {
      ans[j] = ans[j] + parent[bakwass][j] * ff % 1000000007;
      ans[j] %= 1000000007;
    }
    bakwass++;
    bakwass %= 2;
  }
  long long f = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j] * f % 1000000007;
    }
    f *= arr[i];
    f %= 1000000007;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j < n; j++) ans[j] += dp[i][j], ans[j] %= 1000000007;
  }
  for (j = 1; j < 2 * n - 1; j++)
    cout << ans[j] * power(2, 1000000007 - 2) % 1000000007 << " ";
}
