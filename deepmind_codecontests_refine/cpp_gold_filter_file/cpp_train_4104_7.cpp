#include <bits/stdc++.h>
using namespace std;
int f[5005][5005];
int g[5005][5005];
int n;
int a[5005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++)
      f[i][j] = f[i][j - 1] + ((a[i] > a[j]) ? -1 : 1);
  }
  for (int j = 1; j <= n; j++) {
    for (int i = j - 1; i > 0; i--)
      g[i][j] = g[i + 1][j] + ((a[i] > a[j]) ? -1 : 1);
  }
  int Min = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      Min = min(Min, f[i][j] + g[i][j] + ((a[i] > a[j]) ? 1 : -1));
  int tot = 0, all = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (f[i][j] + g[i][j] + ((a[i] > a[j]) ? 1 : -1) == Min) tot++;
      all += (a[i] > a[j]);
    }
  cout << all + Min << " " << tot;
  return 0;
}
