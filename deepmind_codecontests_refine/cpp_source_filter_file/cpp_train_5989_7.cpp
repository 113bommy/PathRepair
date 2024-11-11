#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
char a[100][100];
long long ans;
long long ncr(int n, int r) {
  long long ans = 1;
  r = min(r, n - r);
  n++;
  for (int f = 1; f <= r; f++) {
    ans *= n - f;
    ans /= f;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> a[i][j];
  for (i = 0; i < n; i++) {
    int cr = 0, cc = 0;
    for (j = 0; j < n; j++) {
      if (a[i][j] == 'c') cr++;
      if (a[j][i] == 'c') cc++;
    }
    if (cr > 1) ans += ncr(cr, 2);
    if (cc > 1) ans += ncr(cc, 2);
  }
  cout << ans;
  return 0;
}
