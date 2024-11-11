#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  if (n - 1 > m)
    cout << -1 << '\n';
  else if (m > n * 2 + 2)
    cout << -1 << '\n';
  else {
    while (n || m) {
      if (m && n) {
        if (m > n) {
          cout << "110";
          m -= 2;
          n--;
        } else if (m == n) {
          cout << "10";
          m--;
          n--;
        } else if (m < n) {
          cout << "010";
          n -= 2;
          m--;
        }
      } else if (m) {
        cout << 1;
        m--;
      } else if (n) {
        cout << 0;
        n--;
      }
    }
    cout << '\n';
  }
  return 0;
}
