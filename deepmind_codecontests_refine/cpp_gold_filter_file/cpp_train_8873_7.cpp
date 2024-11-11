#include <bits/stdc++.h>
using namespace std;
int t, n;
char c[52][52];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> c[i][j];
      }
    }
    bool y = true;
    for (int i = 1; i <= n - 1; i++) {
      for (int j = 1; j <= n - 1; j++) {
        if (c[i][j] == '1' && c[i + 1][j] == '0' && c[i][j + 1] == '0') {
          y = false;
        }
      }
    }
    cout << ((y) ? "YES" : "NO") << endl;
  }
}
