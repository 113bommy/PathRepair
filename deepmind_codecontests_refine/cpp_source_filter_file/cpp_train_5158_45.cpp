#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 987654321;
template <typename X = int>
inline X min(X a, X b, X c) {
  return min(min(a, b), c);
}
template <typename X = int>
inline X max(X a, X b, X c) {
  return max(max(a, b), c);
}
template <typename X = int>
inline X mid(X s, X e) {
  return (s + (e - s) / 2);
}
template <typename X = int>
inline X len(X s, X e) {
  return (e - s + 1);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int x[5] = {}, y[5] = {};
  long long int ans = 0;
  for (int i = 0; i < 5; i++) {
    x[i] = (n - i) / 5, y[i] = (m - i) / 5;
    if (i != 0 and n >= i) x[i]++;
    if (i != 0 and m >= i) y[i]++;
  }
  for (int i = 0; i < 5; i++) ans += x[i] * y[(5 - i) % 5];
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  while (T--) solve();
  return 0;
}
