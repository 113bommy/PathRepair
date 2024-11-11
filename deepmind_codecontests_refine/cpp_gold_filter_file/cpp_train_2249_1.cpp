#include <bits/stdc++.h>
using namespace std;
int n, m;
int ret = 1000000001;
int T[111][111];
string s;
int cnt;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'B') cnt++;
      T[i + 1][j + 1] = T[i + 1][j] + T[i][j + 1] - T[i][j] + (s[j] == 'B');
    }
  }
  for (int k = 1; k <= min(n, m); k++) {
    for (int i = 1; i <= n - k + 1; i++)
      for (int j = 1; j <= m - k + 1; j++) {
        int u = i + k - 1;
        int v = j + k - 1;
        int com = T[u][v] - T[i - 1][v] - T[u][j - 1] + T[i - 1][j - 1];
        if (com == cnt) {
          ret = min(ret, k * k - cnt);
        }
      }
  }
  if (ret == 1000000001)
    cout << -1;
  else
    cout << ret;
  return 0;
}
