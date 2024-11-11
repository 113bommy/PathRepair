#include <bits/stdc++.h>
using namespace std;
int n, tow[100001], d[2][100001], ans = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> tow[i];
  d[0][0] = d[1][n - 1] = 1;
  for (int i = 1; i < n; i++) d[0][i] = min(tow[i], d[0][i - 1] + 1);
  for (int i = n - 2; i > -1; i--) d[1][i] = min(tow[i], d[1][i + 1] + 1);
  for (int i = 0; i < n; i++) ans = max(ans, min(d[0][i], d[1][i]));
  cout << ans << endl;
}
