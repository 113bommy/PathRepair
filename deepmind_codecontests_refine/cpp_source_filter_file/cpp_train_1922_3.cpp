#include <bits/stdc++.h>
using namespace std;
long long res[5005][5005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long *p = new long long[n + 1];
  for (int i = 1; i <= n; i++) cin >> p[i];
  long long *s = new long long[n + 1];
  s[0] = p[0] = 0;
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + p[i];
  for (int i = 1; i <= n; i++) {
    res[i][0] = 0;
    for (int j = 1; j < i / m; j++) {
      res[i][j] = max(res[i - 1][j], res[i - m][j - 1] + s[i] - s[i - m]);
    }
  }
  cout << res[n - 1][k];
  return 0;
}
