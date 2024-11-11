#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005];
int l[1005], r[1005];
int dd[1005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) a[i][j] = ((s[j - 1] == 'W') ? 1 : 0);
  }
  for (int i = 1; i <= n; i++) {
    l[i] = m + 1;
    r[i] = 0;
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        l[i] = min(l[i], j);
        r[i] = max(r[i], j);
      }
  }
  while (!r[n] && n > 0) n--;
  l[0] = r[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (r[i] == 0) {
      dd[i] = 1;
      r[i] = l[i - 1];
      l[i] = r[i - 1];
    }
  }
  int ans = max(n - 1, 0);
  for (int i = 1; i <= n; i++) {
    if (dd[i]) continue;
    if (i % 2)
      ans += abs(l[i] - l[i - 1]);
    else
      ans += abs(r[i] - r[i - 1]);
    ans += r[i] - l[i];
  }
  cout << ans;
}
