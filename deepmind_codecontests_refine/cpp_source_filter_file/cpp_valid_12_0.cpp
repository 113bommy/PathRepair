#include <bits/stdc++.h>
using namespace std;
void no() {
  cout << "NO" << '\n';
  ;
}
void yes() {
  cout << "YES" << '\n';
  ;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k > (n) * (m / 2)) {
    no();
    return;
  }
  if (n % 2 == 0) {
    if (k % 2 == 0) {
      yes();
      return;
    } else {
      no();
      return;
    }
  } else {
    if (k <= m / 2) {
      no();
      return;
    } else {
      if ((k - m / 2) % 2 == 0 && n % 2) {
        yes();
        return;
      } else {
        no();
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
