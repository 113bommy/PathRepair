#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (2 * t--) {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto&& i : v) cin >> i;
    for (int i = 1; i < n; i++) {
      while (v[i] > 0 && d >= i) {
        v[0] += 1;
        v[i] -= 1;
        d = d - i;
      }
    }
    cout << v[0] << "\n";
  }
  return 0;
}
