#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  long long mx = (1 << m);
  long long cnt[20][20];
  for (long long i = 0; i < 20; i++) {
    for (long long j = 0; j < 20; j++) {
      cnt[i][j] = 0;
    }
  }
  for (long long i = 1; i < n; i++) {
    long long c1 = s[i] - 'a';
    long long c2 = s[i - 1] - 'a';
    cnt[c1][c2]++;
    cnt[c2][c1]++;
  }
  vector<long long> dp(mx, 10000000000000000);
  long long sub[mx][m];
  for (long long i = 0; i < mx; i++) {
    for (long long j = 0; j < m; j++) {
      sub[i][j] = 0;
    }
  }
  dp[0] = 0;
  for (long long mask = 1; mask < mx; mask++) {
    long long ind = -1;
    for (long long i = 0; i < m; i++) {
      long long pw = 1 << i;
      if (mask & pw) {
        ind = i;
        break;
      }
    }
    long long prev = mask ^ (1LL << ind);
    for (long long i = 0; i < m; i++) {
      sub[mask][i] = sub[prev][i] + cnt[i][ind];
    }
  }
  for (long long mask = 0; mask < mx; mask++) {
    for (long long i = 0; i < m; i++) {
      long long pw = 1 << i;
      if (mask & pw) {
        continue;
      } else {
        long long bits = 0;
        for (long long x = 0; x < m; x++) {
          long long now = 1 << x;
          if (mask & now) {
            bits++;
          }
        }
        long long next = mask + pw;
        long long curr = sub[mask][i] - sub[(mx - 1) ^ next][i];
        dp[next] = min(dp[next], dp[mask] + (bits * curr));
      }
    }
  }
  cout << dp[mx - 1];
}
