#include <bits/stdc++.h>
using namespace std;
const int Max = 5 * 100008;
int a[Max];
int main() {
  int n, m;
  cin >> n >> m;
  int k = n;
  int k1 = m;
  if (n == m) {
    while (n + m != 0) {
      cout << "01";
      n--;
      m--;
    }
  } else if (n > m) {
    int place = m + 1;
    if (n <= place)
      while (m + n > 0) {
        if (n > 0) {
          cout << 0;
          n--;
        }
        if (m > 0) {
          cout << 1;
          m--;
        }
      }
    else
      cout << -1;
  } else if (n < m) {
    int place = n + 1;
    int place2 = m + 1;
    if ((m / 2 + 1) <= place)
      while (m + n > 0) {
        if (m > 0) {
          m > 1 && n < m ? m--, cout << 11 : cout << 1;
          m--;
        }
        if (n > 0) {
          cout << 0;
          n--;
        }
      }
    else
      cout << -1;
  }
  return 0;
}
