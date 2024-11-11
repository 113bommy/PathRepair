#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
int f[10][10], ans[10][10];
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= k; ++i)
    for (int j = 0; j <= 4; ++j) f[i][j] = -1000000000;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      f[x][0] = max(f[x][0], i + j);
      f[x][1] = max(f[x][1], i - j);
      f[x][2] = max(f[x][1], -i + j);
      f[x][3] = max(f[x][3], -i - j);
    }
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j) {
      ans[i][j] = max(ans[i][j], f[i][0] + f[j][3]);
      ans[i][j] = max(ans[i][j], f[i][1] + f[j][2]);
      ans[i][j] = max(ans[i][j], f[i][2] + f[j][1]);
      ans[i][j] = max(ans[i][j], f[i][3] + f[j][0]);
    }
  int p, answer = 0;
  cin >> p;
  for (int i = 2; i <= s; ++i) {
    int cur;
    cin >> cur;
    answer = max(answer, ans[p][cur]);
    p = cur;
  }
  cout << answer;
  return 0;
}
