#include <bits/stdc++.h>
using namespace std;
const long long int LINF = 1e18, mod = 1e9 + 7;
void Bl0ck_M0mb0() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
pair<string, long long int> DP1[1001][1001];
signed main() {
  Bl0ck_M0mb0();
  long long int t = 1, ans = 0;
  while (t--) {
    for (long long int i = 1; i <= 1000; i++) {
      for (long long int j = 0; j <= 1000; j++)
        DP1[i][j] = make_pair("", (long long int)0);
    }
    long long int r, c;
    cin >> r >> c;
    string ip[r + 1];
    for (long long int i = 1; i <= r; i++) cin >> ip[i];
    long long int DP[r + 2][c];
    for (long long int i = 1; i <= r + 1; i++) {
      for (long long int j = 0; j <= c - 1; j++) DP[i][j] = 1;
    }
    for (long long int j = 0; j <= c - 1; j++) {
      for (long long int i = r - 1; i >= 1; i--)
        DP[i][j] = (ip[i][j] == ip[i + 1][j]) ? DP[i + 1][j] + 1 : 1;
    }
    for (long long int j = 0; j <= c - 1; j++) {
      for (long long int i = r - 1; i >= 2; i--) {
        if (ip[i][j] == ip[i - 1][j]) continue;
        long long int sz = DP[i][j];
        if (i > sz && DP[i + sz][j] >= sz && DP[i - sz][j] == sz) {
          ans++;
          string seq;
          seq += ip[i - sz][j];
          seq += ip[i][j];
          seq += ip[i + sz][j];
          DP1[i][j] = make_pair(seq, sz);
        }
      }
    }
    long long int len = 1;
    for (long long int i = 2; i <= r - 1; i++) {
      for (long long int j = 1; j <= c - 1; j++) {
        if (DP1[i][j].second != 0 && DP1[i][j] == DP1[i][j - 1]) len++;
        if (j == c - 1 ||
            !(DP1[i][j].second != 0 && DP1[i][j] == DP1[i][j - 1])) {
          ans += (len) * (len - 1) / 2;
          len = 1;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
