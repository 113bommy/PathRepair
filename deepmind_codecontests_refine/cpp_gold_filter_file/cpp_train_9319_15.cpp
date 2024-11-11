#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
int a[1010];
int b[1010];
int s1[1010][1010];
int s2[1010][1010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      if (j == i)
        s1[i][j] = a[i];
      else
        s1[i][j] = s1[i][j - 1] | a[j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
      if (j == i)
        s2[i][j] = b[i];
      else
        s2[i][j] = s2[i][j - 1] | b[j];
    }
  int ans = 0;
  for (int l = 1; l <= n; l++)
    for (int r = l; r <= n; r++) ans = max(ans, s1[l][r] + s2[l][r]);
  cout << ans << endl;
  return 0;
}
