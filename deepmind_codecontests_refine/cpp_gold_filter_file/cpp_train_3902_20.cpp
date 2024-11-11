#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n, p = 1;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    if (i % 4 != 0 && i % 4 != 2) {
      for (int j = 0; j < n; j++) {
        cout << "#";
      }
    } else if (i % 4 == 2) {
      for (int j = 0; j < n - 1; j++) {
        cout << ".";
      }
      cout << "#";
    } else if (i % 4 == 0) {
      cout << "#";
      for (int j = 0; j < n - 1; j++) {
        cout << ".";
      }
    }
    cout << "\n";
  }
}
