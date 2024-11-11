#include <bits/stdc++.h>
using namespace std;
int a[10050][6];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 5; j++) {
        cin >> a[i][j];
      }
    }
    bool f = false;
    for (int i = 1; i <= 5; i++) {
      if (f) break;
      for (int j = 1; j <= 5; j++) {
        if (f) break;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for (int k = 1; k <= n; k++) {
          if (a[k][i] && !a[k][j]) c1++;
          if (!a[k][i] && a[k][j]) c2++;
          if (a[k][i] && a[k][j]) c3++;
          if (!a[k][i] && !a[k][j]) c4++;
        }
        if (c4 != 0) continue;
        if (c1 + c3 >= (n / 2) && c2 + c3 >= (n / 2)) f = true;
      }
    }
    if (f) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
