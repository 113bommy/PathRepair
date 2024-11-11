#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[20009][11];
int ans[11];
int x, y, msg[11];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    msg[y - 1]++;
    ans[x - 1]--;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] > 0) ans[j] += msg[i];
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
