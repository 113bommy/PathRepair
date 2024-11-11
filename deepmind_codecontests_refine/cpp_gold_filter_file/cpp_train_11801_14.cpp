#include <bits/stdc++.h>
using namespace std;
map<string, int> M;
int n, T, m, cnt, x[500005], dp[32768][115], pre[500005][15], tr[32768][15],
    ans = 106, pos, Min;
int label(string s) {
  map<string, int>::iterator it = M.find(s);
  if (it == M.end()) {
    M[s] = cnt;
    return cnt++;
  } else
    return it->second;
}
int main() {
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s, label(s);
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        tr[i][j] = -1;
      else
        for (int k = j + 1; k < n; k++)
          if (i & (1 << k)) tr[i][j]++;
  cin >> T;
  for (int q = 1; q <= T; q++) {
    cin >> m;
    for (int i = 0; i <= m + 1; i++)
      for (int j = 0; j < n; j++) pre[i][j] = m + 1;
    for (int i = 1; i <= m; i++) {
      cin >> s, x[i] = label(s);
      if (x[i] < n) pre[i][x[i]] = i;
    }
    for (int i = m - 1; i; i--)
      for (int j = 0; j < n; j++) pre[i][j] = min(pre[i][j], pre[i + 1][j]);
    memset(dp, 127, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
      Min = m + 1;
      for (int j = 0; j <= n * (n - 1) / 2; j++)
        if (dp[i][j] < m && (j == 0 || dp[i][j] < Min)) {
          Min = dp[i][j];
          for (int k = 0; k < n; k++)
            if (!(i & (1 << k)))
              dp[i | (1 << k)][j + tr[i][k]] =
                  min(dp[i | (1 << k)][j + tr[i][k]], pre[dp[i][j] + 1][k]);
        }
    }
    for (int j = 0; j <= n * (n + 1) / 2; j++)
      if (dp[(1 << n) - 1][j] <= m) {
        if (j < ans) ans = j, pos = q;
      }
  }
  if (!pos)
    puts("Brand new problem!");
  else {
    printf("%d\n[:", pos);
    for (int i = 0; i < n * (n - 1) / 2 - ans + 1; i++) putchar('|');
    puts(":]");
  }
  return 0;
}
