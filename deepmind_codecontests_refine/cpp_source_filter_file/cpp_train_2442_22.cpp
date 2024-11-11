#include <bits/stdc++.h>
using namespace std;
int n, a[7][1003], pos[7][1003], ans[1003], k;
int maxi(int a, int b) { return (a > b) ? a : b; }
bool posi(int j, int i) {
  for (int x = 1; x <= k; x++)
    if (pos[x][j] < pos[x][i])
      continue;
    else
      return 0;
  return 1;
}
int main() {
  int i, j, l, m, out;
  cin >> n >> k;
  for (i = 1; i <= k; i++)
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      pos[i][a[i][j]] = j;
    }
  for (i = 1; i <= n; i++) {
    ans[a[1][i]] = 1;
    for (j = 1; j <= n; j++)
      if (posi(j, i)) ans[a[1][i]] = maxi(ans[a[1][i]], ans[j] + 1);
  }
  out = ans[1];
  for (i = 2; i <= n; i++) out = maxi(out, ans[i]);
  cout << out << endl;
  return 0;
}
