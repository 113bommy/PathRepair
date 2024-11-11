#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
template <class T, class U>
inline void checkmin(T &x, U y) {
  if (y < x) x = y;
}
template <class T, class U>
inline void checkmax(T &x, U y) {
  if (y > x) x = y;
}
template <class T, class U>
inline bool ifmin(T &x, U y) {
  if (y < x) return x = y, true;
  return false;
}
template <class T, class U>
inline bool ifmax(T &x, U y) {
  if (y > x) return x = y, true;
  return false;
}
template <class T>
inline void sort(T &a) {
  sort(a.begin(), a.end());
}
template <class T>
inline void rsort(T &a) {
  sort(a.rbegin(), a.rend());
}
template <class T>
inline void reverse(T &a) {
  reverse(a.begin(), a.end());
}
template <class T>
inline istream &operator>>(istream &stream, vector<T> &a) {
  for (auto &i : a) stream >> i;
  return stream;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  srand(85453532);
  long long n;
  cin >> n;
  vector<long long> arr(n);
  cin >> arr;
  vector<long long> brr;
  long long past = -1;
  for (auto i : arr) {
    if (i != past) brr.push_back(i);
    past = i;
  }
  n = int(brr.size());
  vector<vector<long long>> dp(n, vector<long long>(n, 4000000000000000007ll));
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int l = 1; l < n; ++l)
    for (int i = 0; i + l < n; ++i) {
      if (brr[i] == brr[i + l])
        checkmin(dp[i][i + l], dp[i + 1][i + l - 1] + 1);
      checkmin(dp[i][i + l], dp[i + 1][i + l] + 1);
      checkmin(dp[i][i + 1], dp[i][i + l - 1] + 1);
    }
  cout << dp[0][n - 1];
  return 0;
}
