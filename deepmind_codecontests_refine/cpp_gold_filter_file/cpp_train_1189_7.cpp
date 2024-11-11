#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m >= (n - 1) && m <= 2 * (n + 1)) {
    if (m == n - 1) {
      while (m) {
        cout << "01";
        m--;
      }
      cout << "0";
    } else if (m == n) {
      while (m && n) {
        cout << "10";
        m--;
        n--;
      }
    } else {
      while (m != n && m != 0 && n != 0) {
        cout << "110";
        m -= 2;
        n--;
      }
      while (m != 0 && n != 0) {
        cout << "10";
        m--;
        n--;
      }
      while (m != 0) {
        cout << "1";
        m--;
      }
      while (n != 0) {
        cout << "0";
        n--;
      }
    }
  } else
    cout << "-1";
  return 0;
}
