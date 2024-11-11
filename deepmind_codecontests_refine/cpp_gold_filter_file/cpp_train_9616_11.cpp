#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if ((a[i] % 2) != (a[i + 1] % 2)) {
      if (i > 0) {
        if (a[i - 1] % 2 == a[i] % 2) {
          cout << i + 2;
          return 0;
        } else {
          cout << i + 1;
          return 0;
        }
      } else {
        if (a[i + 1] % 2 == a[i + 2] % 2) {
          cout << i + 1;
          return 0;
        } else {
          cout << i + 2;
          return 0;
        }
      }
    }
  }
  return 0;
}
