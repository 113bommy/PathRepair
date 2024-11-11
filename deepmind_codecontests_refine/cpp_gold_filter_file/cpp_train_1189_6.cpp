#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n2, m2, m;
  cin >> n >> m;
  if (m > (2 * n) + 2 || n >= m + 2) {
    cout << -1 << endl;
  } else {
    string out = "";
    if (m >= n) {
      m2 = 0;
      int x = m - n - 1;
      for (int i = 1; i <= n; i++) {
        if (x > 0) {
          out += "110";
          x--;
          m2 += 2;
        } else {
          out += "10";
          m2 += 1;
        }
      }
      for (int i = 1; i <= m - m2; i++) out += "1";
    } else {
      n2 = 0;
      int x = n - m - 1;
      for (int i = 1; i <= m; i++) {
        if (x > 0) {
          out += "110";
          x--;
          n2 += 2;
        } else {
          out += "01";
          n2 += 1;
        }
      }
      for (int i = 1; i <= n - n2; i++) out += "0";
    }
    cout << out << endl;
  }
}
