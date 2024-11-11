#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int LG = 20;
long long n, a[maxn], dp[LG + 10][maxn], loog[maxn], pd[maxn];
long long ans;
int answer(int l, int r) {
  int ind, ind1;
  ind = dp[loog[r - l + 1]][l];
  ind1 = dp[loog[r - l + 1]][r - (1 << (loog[r - l + 1])) + 1];
  return (a[ind] > a[ind1]) ? ind : ind1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  loog[1] = 0;
  for (int i = 2; i < maxn; i++) loog[i] = loog[i / 2] + 1;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> a[i], a[i]--, dp[0][i] = i;
  for (int i = 1; i < LG; i++)
    for (int j = 0; j < n - 1; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j + (1 << (i - 1)) < n - 1) {
        int ind = dp[i - 1][j + (1 << (i - 1))];
        if (a[ind] > a[dp[i][j]]) dp[i][j] = ind;
      }
    }
  for (int i = n - 2; i >= 0; i--)
    if (a[i] != n - 1) {
      int x = answer(i, a[i]);
      pd[i] = pd[x] - (a[i] - x) + ((n - 1) - i);
      ans = ans + pd[i];
    } else {
      pd[i] = (n - 1) - i;
      ans = ans + pd[i];
    }
  cout << ans << '\n';
  return 0;
}
