#include <bits/stdc++.h>
using namespace std;
void print() { cout << "\n"; }
template <typename T>
void print(const T& x) {
  cout << x;
}
template <typename T, typename... R>
void print(const T& x, const R&... r) {
  cout << x;
  print(r...);
}
template <typename T>
void _prints(const T& x) {
  cout << x;
}
template <typename T, typename... R>
void _prints(const T& x, const R&... r) {
  cout << x << " ";
  _prints(r...);
}
template <typename T>
void prints(const T& x) {
  cout << x << " ";
}
template <typename T, typename... R>
void prints(const T& x, const R&... r) {
  _prints(x, r...);
  print();
}
template <typename T>
void read(T& x) {
  cin >> x;
}
template <typename T, typename... R>
void read(T& x, R&... r) {
  cin >> x;
  read(r...);
}
template <typename _T>
void _debug(const char* s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... R>
void _debug(const char* s, _T x, R... r) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ", ";
  _debug(s + 1, r...);
}
int _int(const char& c) {
  if (c >= 'a' && c <= 'z') return c - 'a';
  if (c >= 'A' && c <= 'Z') return c - 'A';
  if (c >= '0' && c <= '9') return c - '0';
  return c;
}
using ll = long long;
using ld = long double;
const int N = 2e3 + 5, INF = 1e9, MOD = 1e9 + 7;
int dp[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  read(t);
  for (int tt = 0; tt < t; tt++) {
    int n, k;
    read(n, k);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
      read(arr[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        bool flag = (arr[i + 1] == j + 1);
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + flag);
      }
    }
    int ans = INF;
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] >= k) ans = min(ans, n - i);
    }
    memset(dp, 0, sizeof(dp));
    print(ans != INF ? ans : -1);
    print();
  }
  return 0;
}
