#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> v;
char a[2000][2000];
int ans[1000];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (1 + i - 1 <= j && a[i][j + i - 1] == 'L') ans[j]++;
      if (j - i + 1 >= 1 && a[i][j - i + 1] == 'R') ans[j]++;
      if (1 + (i - 1) <= n && a[i + i - 1][j] == 'U') ans[j]++;
    }
  for (int i = 1; i <= m; i++) cout << ans[i] << " ";
}
