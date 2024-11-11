#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int it = 0; it < t; ++it) {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (auto& x : v) cin >> x;
    vector<int> kek(n, 0);
    if (n % 2 == 1) {
      for (int i = 0; i <= n / 2; i++) {
        kek[i] = i;
      }
      kek[n / 2 + 1] = n / 2 + 1;
      for (int i = 0; i <= n / 2; i++) {
        kek[n - 1 - i] = i;
      }
      bool yes = true;
      for (int i = 0; i < n; i++) {
        if (v[i] < kek[i]) yes = false;
      }
      if (yes)
        cout << "Yes\n";
      else
        cout << "No\n";
    } else {
      for (int i = 0; i < n / 2; i++) {
        kek[i] = i;
      }
      kek[n / 2] = n / 2;
      for (int i = n / 2 + 1; i < n; i++) {
        kek[i] = n - 1 - i;
      }
      bool yes = true;
      for (int i = 0; i < n; i++) {
        if (v[i] < kek[i]) yes = false;
      }
      if (yes) {
        cout << "Yes\n";
        continue;
      }
      reverse(kek.begin(), kek.end());
      yes = true;
      for (int i = 0; i < n; i++) {
        if (v[i] < kek[i]) yes = false;
      }
      if (yes) {
        cout << "Yes\n";
        continue;
      }
      cout << "No\n";
    }
  }
}
