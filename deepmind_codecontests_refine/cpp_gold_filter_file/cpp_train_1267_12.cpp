#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> v(n);
  int ans;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    bool notsorainy = true;
    for (int j = max(0, i - x); j <= min(n - 1, i + y); j++) {
      if (i != j) {
        if (v[i] > v[j]) {
          notsorainy = false;
          break;
        }
      }
    }
    if (notsorainy) {
      ans = i + 1;
      break;
    }
  }
  cout << ans;
}
