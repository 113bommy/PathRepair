#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int p[n], c[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> c[i];
    }
    bool possible = true;
    if (c[0] > p[0]) possible = false;
    for (int i = 1; i < n; i++) {
      if (c[i] < c[i - 1] || p[i] < p[i - 1] ||
          c[i] - c[i - 1] > p[i] - p[i - 1]) {
        possible = false;
        break;
      }
    }
    if (possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
