#include <bits/stdc++.h>
using namespace std;
int dirx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int diry[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int a[200];
int n, k, m;
int solve(int k) {
  int i = k - 1, j = k + 2, ans = 0;
  if (j == n) return 2;
  if (i == -1) return 2;
  while (1) {
    if (a[j] == a[i]) {
      if (j + 1 < n && i - 1 >= 0 && a[j + 1] == a[i - 1] && a[j + 1] == a[i]) {
        ans += 4;
        j += 2;
        i -= 2;
        continue;
      }
      if (j + 1 < n && a[j + 1] == a[i]) {
        ans += 3;
        j += 2;
        i -= 1;
        continue;
      }
      if (i > 0 && a[i - 1] == a[i]) {
        ans += 3;
        j += 1;
        i += 2;
        continue;
      }
      break;
    } else
      break;
  }
  return ans + 2;
}
int main() {
  int ans = 0;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == m && a[i + 1] == m) {
      ans = max(ans, solve(i));
    }
  }
  cout << ans << endl;
  return 0;
}
