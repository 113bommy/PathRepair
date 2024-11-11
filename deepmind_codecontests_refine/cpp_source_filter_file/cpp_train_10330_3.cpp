#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
string S, T;
int t;
int nxt[maxn][30];
int memo[maxn][maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> S >> T;
    int n = S.size(), m = T.size();
    int last[30];
    for (int i = 0; i < 30; ++i) last[i] = n;
    for (int i = S.size() - 1; i >= 0; --i) {
      last[S[i] - 'a'] = i;
      for (int j = 0; j < 30; ++j) {
        nxt[i][j] = last[j];
      }
    }
    bool fun = 0;
    for (int k = 0; k <= m; ++k) {
      string A = T.substr(0, k), B = T.substr(k, m - k);
      int p = k, q = m - k;
      for (int i = 0; i <= p; ++i) {
        for (int j = 0; j <= q; ++j) {
          memo[i][j] = 1e9;
        }
      }
      memo[0][0] = 0;
      for (int i = 0; i <= p; ++i) {
        for (int j = 0; j <= q; ++j) {
          if (i > 0 and memo[i - 1][j] < n) {
            memo[i][j] =
                min(memo[i][j], nxt[memo[i - 1][j]][A[i - 1] - 'a'] + 1);
          }
          if (j > 0 and memo[i][j - 1] < n) {
            memo[i][j] =
                min(memo[i][j], nxt[memo[i][j - 1]][B[j - 1] - 'a'] + 1);
          }
        }
      }
      if (memo[p][q] < n) {
        fun = 1;
        break;
      }
    }
    puts(fun ? "YES" : "NO");
  }
  return 0;
}
