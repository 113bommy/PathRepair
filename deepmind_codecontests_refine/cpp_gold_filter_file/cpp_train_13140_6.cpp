#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename U>
bool compare(T x, U y) {
  return (abs(x - y) <= 1e-9);
}
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (auto &x : a) cin >> x;
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) cout << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
