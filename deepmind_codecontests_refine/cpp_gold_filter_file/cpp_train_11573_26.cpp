#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int MOD = 1000003;
string s[N];
int n, m;
int row[N][2], col[N][2];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') continue;
      row[i][(j & 1) ^ (s[i][j] < '3')] = 1;
      col[j][(i & 1) ^ (s[i][j] == '1' || s[i][j] == '4')] = 1;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) ans = (ans * (2 - row[i][0] - row[i][1])) % MOD;
  for (int i = 0; i < m; i++) ans = (ans * (2 - col[i][0] - col[i][1])) % MOD;
  printf("%d\n", ans);
  return 0;
}
