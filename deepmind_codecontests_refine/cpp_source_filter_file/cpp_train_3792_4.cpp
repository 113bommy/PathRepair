#include <bits/stdc++.h>
using namespace std;
int a[1005];
long long int sump[1005][10005], sumn[1005][10005];
int main() {
  ios_base::sync_with_stdio(0);
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sump[0][a[0]] = 1;
  if (a[0] != 0) sumn[0][a[0]] = 1;
  long long int ans = sump[0][0];
  sump[0][0]++;
  for (i = 1; i < n; i++) {
    int x = a[i];
    for (j = 0; j <= 1000; j++) {
      if (sump[i - 1][j]) {
        if (j + x >= 0)
          sump[i][j + x] = (sump[i][j + x] + sump[i - 1][j]) % 1000000007;
        else
          sumn[i][-1 * (j + x)] =
              (sumn[i][-1 * (j + x)] + sump[i - 1][j]) % 1000000007;
        if (j - x >= 0)
          sump[i][j - x] = (sump[i][j - x] + sump[i - 1][j]) % 1000000007;
        else
          sumn[i][-1 * (j - x)] =
              (sumn[i][-1 * (j - x)] + sump[i - 1][j]) % 1000000007;
      }
    }
    for (j = 0; j <= 1000; j++) {
      if (sumn[i - 1][j]) {
        if ((-1 * j) + x >= 0)
          sump[i][(-1 * j) + x] =
              (sump[i][(-1 * j) + x] + sumn[i - 1][j]) % 1000000007;
        else
          sumn[i][-1 * ((-1 * j) + x)] =
              (sumn[i][-1 * ((-1 * j) + x)] + sumn[i - 1][j]) % 1000000007;
        if ((-1 * j) - x >= 0)
          sump[i][(-1 * j) - x] =
              (sump[i][(-1 * j) - x] + sumn[i - 1][j]) % 1000000007;
        else
          sumn[i][-1 * ((-1 * j) - x)] =
              (sumn[i][-1 * ((-1 * j) - x)] + sumn[i - 1][j]) % 1000000007;
      }
    }
    ans = (ans + sump[i][0]) % 1000000007;
    sump[i][0]++;
    sump[i][0] = sump[i][0] % 1000000007;
  }
  cout << ans;
  return 0;
}
