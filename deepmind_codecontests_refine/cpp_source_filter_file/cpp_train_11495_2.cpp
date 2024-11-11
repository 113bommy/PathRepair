#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000];
int main() {
  int n;
  cin >> n;
  int a25 = 0, a50 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 25) {
      a25++;
    }
    if (a[i] == 50) {
      a50++;
      if (a25 == 0) {
        cout << "NO\n";
        return 0;
      }
      a25--;
    }
    if (a[i] == 100) {
      if (a25 < 3 || (a25 < 1 || a50 < 1)) {
        cout << "NO\n";
        return 0;
      }
      if (a25 >= 1 && a50 >= 1) {
        a25 -= 1;
        a50--;
      } else {
        a25 -= 3;
      }
    }
  }
  cout << "YES\n";
}
