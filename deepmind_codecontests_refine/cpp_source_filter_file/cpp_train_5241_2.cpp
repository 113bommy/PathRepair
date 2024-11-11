#include <bits/stdc++.h>
using namespace std;
long n, ar[2100][2100], arp[2100][2100], mx, ans1, ans2;
void dfs(long a, long b) {
  if (b < mx) mx = b;
  arp[a][b] = 1;
  if (ar[a - 1][b] == 1 && arp[a - 1][b] == 0) dfs(a - 1, b);
  if (ar[a + 1][b] == 1 && arp[a + 1][b] == 0) dfs(a + 1, b);
  if (ar[a][b - 1] == 1 && arp[a][b - 1] == 0) dfs(a, b - 1);
  if (ar[a][b + 1] == 1 && arp[a][b + 1] == 0) dfs(a, b + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> ar[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (arp[i][j] == 0 && ar[i][j] == 1) {
        mx = j;
        dfs(i, j);
        if (mx == j)
          ans1++;
        else
          ans2++;
      }
  cout << ans1 << " " << ans2 << endl;
  cin.get();
  cin.get();
  return 0;
}
