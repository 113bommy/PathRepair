#include <bits/stdc++.h>
using namespace std;
long long int a[1001], b[1001], n, m, i;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[0] == 0) {
    cout << "NO" << endl;
  } else {
    if (a[m] == 1) {
      cout << "YES" << endl;
    } else {
      if (b[m] == 0) {
        cout << "NO" << endl;
      } else {
        for (i = m + 1; i < n; i++) {
          if (a[i] == 1 && b[i] == 1) {
            cout << "YES" << endl;
            break;
          } else {
            if (i == n - 1) {
              cout << "NO" << endl;
            }
          }
        }
      }
    }
  }
  return 0;
}
