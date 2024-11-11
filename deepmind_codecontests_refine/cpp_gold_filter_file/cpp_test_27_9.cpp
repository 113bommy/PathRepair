#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (m < n - 1 || m > (n * (n - 1LL)) / 2) {
    cout << "NO" << '\n';
    return;
  }
  if (n == 1) {
    if (k > 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  } else if (m < n * (n - 1LL) / 2) {
    if (k > 3) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  } else {
    if (k > 2) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
