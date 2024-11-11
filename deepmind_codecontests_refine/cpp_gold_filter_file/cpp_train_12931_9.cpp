#include <bits/stdc++.h>
using namespace std;
int main() {
  const int N = 20;
  int n, m, tc, year, indexS, indexT, mult;
  cin >> n >> m;
  mult = n * m;
  string s[N], t[N];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < m; i++) cin >> t[i];
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cin >> year;
    if (year > mult) {
      year = (year - mult * (year / mult));
      if (!year) {
        year = mult;
      }
    }
    indexS = year - 1;
    indexT = year - 1;
    if (year > n) {
      indexS = (year - n * (year / n)) - 1;
      if (indexS == -1) {
        indexS = n - 1;
      }
    }
    if (year > m) {
      indexT = (year - m * (year / m)) - 1;
      if (indexT == -1) {
        indexT = m - 1;
      }
    }
    cout << s[indexS] << t[indexT] << endl;
  }
  return 0;
}
