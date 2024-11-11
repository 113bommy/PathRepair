#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const long long maxn = 2e6 + 10;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 100;
bool ok[2][26][52][52];
vector<pair<long long, long long> > vc[30];
inline void calc(string &s, long long id) {
  for (long long i = 0; i < s.size(); i++) ok[id][s[i] - 'a'][i][i + 1] = true;
  for (long long sz = 2; sz <= s.size(); sz++) {
    for (long long l = 0; l + sz <= s.size(); l++) {
      long long r = l + sz;
      for (long long k = l + 1; k < r; k++) {
        for (long long theChar = 0; theChar < 26; theChar++) {
          for (long long pt = 0; pt < vc[theChar].size(); pt++) {
            ok[id][theChar][l][r] |= ok[id][vc[theChar][pt].first][l][k] &&
                                     ok[id][vc[theChar][pt].second][k][r];
          }
        }
      }
    }
  }
}
long long dp[100][100];
int32_t main() {
  string s = get(), t = get();
  long long n = s.size(), m = t.size();
  long long q = in();
  for (long long i = 0; i < q; i++) {
    string op = get();
    vc[op[0] - 'a'].push_back({op[3] - 'a', op[4] - 'a'});
  }
  calc(s, 0);
  calc(t, 1);
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= m; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (long long r1 = 1; r1 <= n; r1++) {
    for (long long r2 = 1; r2 <= m; r2++) {
      for (long long l1 = 0; l1 < r1; l1++) {
        for (long long l2 = 0; l2 < r2; l2++) {
          for (long long theChar = 0; theChar < 26; theChar++) {
            if (ok[0][theChar][l1][r1] && ok[1][theChar][l2][r2]) {
              dp[r1][r2] = min(dp[r1][r2], dp[l1][l2] + 1);
            }
          }
        }
      }
    }
  }
  if (dp[n][m] == INF)
    cout << -1;
  else
    cout << dp[n][m] << "\n";
}
