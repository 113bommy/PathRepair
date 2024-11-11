#include <bits/stdc++.h>
using namespace std;
int d[3005], t, r, e, n, m, k, f, i, j, a, b, res[100];
string s[3005];
int main() {
  cin >> n >> m;
  i = n - 1;
  m--;
  while (m > 0) {
    d[i] = m % 2;
    m /= 2;
    i--;
  }
  for (i = 1; i <= n; i++) {
    if (d[i] == 0)
      res[i - f] = i;
    else {
      res[n - f] = i;
      f++;
    }
  }
  for (i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}
