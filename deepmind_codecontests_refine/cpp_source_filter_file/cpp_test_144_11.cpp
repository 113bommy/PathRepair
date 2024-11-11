#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int id = -1;
    while (k--) {
      for (int i = 0; i < n % m; i++) {
        cout << (n + m - 1) / m;
        for (int j = 0; j < (n + m - 1) / m; j++) {
          cout << ' ' << (id = (id + 1) % n) + 1;
        }
        cout << '\n';
      }
      for (int i = 0; i < m - n % m; i++) {
        cout << n / m;
        for (int j = 0; j < n / m; j++) {
          cout << ' ' << (id + 1 + i * n / m + j) % n + 1;
        }
        cout << '\n';
      }
    }
    if (t) cout << '\n';
  }
  return 0;
}
