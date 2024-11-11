#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
  for (int i = 0; i <= n / 3; i++) {
    for (int j = 0; j <= n / 5; j++) {
      for (int k = 0; k <= n / 7; k++) {
        if (i * 3 + j * 5 + k * 7 == n) {
          cout << i << " " << j << " " << k << endl;
          return;
        }
      }
    }
  }
  cout << -1 << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    solve();
  }
}
