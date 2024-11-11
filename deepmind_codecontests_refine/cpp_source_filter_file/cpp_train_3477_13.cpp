#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;
int g[N][4];
int mark[N];
pair<int, int> p[N];
int main() {
  ios::sync_with_stdio(false);
  int r, n;
  cin >> r >> n;
  int cnt = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 0; j < 4; j++) {
      cnt++;
      if (j == 0)
        for (int k = 0; k < i; k++) mark[g[k][2] ^ g[i - k - 1][2]] = cnt;
      if (j == 1)
        for (int k = 0; k < i; k++) mark[g[k][3] ^ g[i - k - 1][1]] = cnt;
      if (j == 2) {
        for (int k = 0; k < i; k++) mark[g[k][2] ^ g[i - k - 1][3]] = cnt;
        for (int k = 0; k < i - 1; k++)
          mark[g[k][2] ^ g[i - 1 - k - 1][1]] = cnt;
      }
      if (j == 3) {
        for (int k = 0; k < i; k++) mark[g[k][3] ^ g[i - k - 1][3]] = cnt;
        for (int k = 0; k < i - 2; k++)
          mark[g[k][1] ^ g[i - 2 - k - 1][1]] = cnt;
      }
      while (mark[g[i][j]] == cnt) g[i][j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].first--, p[i].second--;
  }
  sort(p, p + n);
  if (n == 0) {
    cout << (g[r][0] == 0 ? "LOSE" : "WIN") << "\n";
    return 0;
  }
  int ans = 0;
  ans ^= g[p[0].first][2];
  for (int i = 1; i < n; i++)
    if (p[i].second == p[i - 1].second)
      ans ^= g[p[i].first - p[i - 1].first - 1][3];
    else
      ans ^= g[p[i].first - p[i - 1].first - 1][1];
  ans ^= g[r - p[n - 1].first - 1][2];
  cout << (ans == 0 ? "LOSE\n" : "WIN\n");
  return 0;
}
