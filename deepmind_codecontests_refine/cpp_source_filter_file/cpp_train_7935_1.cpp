#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], x[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt = 1, temp = 0;
    int prim[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int j = 0; j < 11; j++) {
      for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
          if (a[i] % prim[j] == 0) {
            a[i] = 0;
            x[i] = cnt;
            temp = 2;
          }
        }
      }
      if (temp == 2) cnt++;
      temp = 0;
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
      cout << x[i] << " ";
    }
    cout << endl;
  }
}
