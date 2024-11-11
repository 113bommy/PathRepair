#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[0] == 1 && a[k - 1] == 1) {
    cout << "YES";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[0] == 1) {
      if (a[i] == 1 && b[i] == 1) {
        if (k - 1 <= i && b[k - 1] == 1) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
}
