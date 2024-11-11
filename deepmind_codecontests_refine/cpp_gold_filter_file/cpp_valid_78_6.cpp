#include <bits/stdc++.h>
int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    cout << (l + l > r ? r - l : r - r / 2 - 1) << '\n';
  }
  return 0;
}
