#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, x;
  cin >> n >> m;
  int b[m], d[m], debt[n + 1];
  long result = 0;
  memset(debt, 0, sizeof debt);
  for (i = 0; i < m; i++) {
    cin >> b[i] >> d[i] >> x;
    debt[b[i]] += -1 * x;
    debt[d[i]] += x;
  }
  for (i = 0; i <= n; i++)
    if (debt[i] < 0) result += debt[i];
  cout << result * -1;
  return 0;
}
