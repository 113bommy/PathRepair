#include <bits/stdc++.h>
using namespace std;
int v[110];
int d[110];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; ++j) d[i] += v[j];
  }
  sort(d, d + m);
  reverse(d, d + m);
  int ans = 0;
  int i = 0;
  while (d[i] > 0) {
    ans += d[i];
    i++;
  }
  cout << ans << endl;
  return 0;
}
