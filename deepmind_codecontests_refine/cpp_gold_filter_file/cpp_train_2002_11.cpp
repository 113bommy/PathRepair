#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sum[502][502];
char ch[502][502];
int getsum(int left, int top, int right, int bot) {
  return sum[right][bot] - sum[left][bot] + sum[left][top] - sum[right][top];
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%s", ch[i]);
  }
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      if (ch[i][j] == '1' && ch[i - 1][j] == '1' && ch[i + 1][j] == '1' &&
          ch[i][j - 1] == '1' && ch[i][j + 1] == '1') {
        ++sum[i][j];
      }
    }
    if (m > 1) sum[i][m - 1] = sum[i][m - 2];
  }
  for (int i = 1; i < m; ++i)
    if (n > 1) sum[n - 1][i] = sum[n - 2][i];
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i; j < n - 1; ++j) {
      int r = 1;
      for (int l = 0; l < m - 1; ++l) {
        while (r < m && getsum(i, l, j, r) < k) ++r;
        if (r == m) break;
        ans += m - r - 1;
      }
    }
  cout << ans << endl;
  return 0;
}
