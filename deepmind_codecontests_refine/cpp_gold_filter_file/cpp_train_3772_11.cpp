#include <bits/stdc++.h>
using namespace std;
long m, n, x[1 << 20], y[1 << 20], l[1 << 20][5], r[1 << 20][5];
long calc;
long ans[200];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= m * 4; i++)
    for (int j = 0; j < 4; j++) l[i][j] = 1e9, r[i][j] = -1e9;
  for (int i = 1; i <= n; i++) {
    l[x[i]][0] = min(l[x[i]][0], y[i]);
    r[x[i]][0] = max(r[x[i]][0], y[i]);
    l[y[i]][1] = min(l[y[i]][1], x[i]);
    r[y[i]][1] = max(r[y[i]][1], x[i]);
    l[x[i] + y[i]][2] = min(l[x[i] + y[i]][2], x[i]);
    r[x[i] + y[i]][2] = max(r[x[i] + y[i]][2], x[i]);
    l[x[i] - y[i] + m][3] = min(l[x[i] - y[i] + m][3], x[i]);
    r[x[i] - y[i] + m][3] = max(r[x[i] - y[i] + m][3], x[i]);
  }
  for (int i = 1; i <= n; i++) {
    calc = 0;
    if (l[x[i]][0] < y[i]) ++calc;
    if (r[x[i]][0] > y[i]) ++calc;
    if (l[y[i]][1] < x[i]) ++calc;
    if (r[y[i]][1] > x[i]) ++calc;
    if (l[x[i] + y[i]][2] < x[i]) ++calc;
    if (r[x[i] + y[i]][2] > x[i]) ++calc;
    if (l[x[i] - y[i] + m][3] < x[i]) ++calc;
    if (r[x[i] - y[i] + m][3] > x[i]) ++calc;
    ans[calc]++;
  }
  for (int i = 0; i < 9; i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  cin.get();
  cin.get();
  return 0;
}
