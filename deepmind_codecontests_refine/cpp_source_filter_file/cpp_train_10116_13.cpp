#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
const int M = 100;
long long dp[M + 2][100001];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    a[i] = a[n - 1] - a[i];
  }
  for (int i = 0; i < n; i++) {
    long long kl = 0;
    long long aa = a[i];
    while (aa) {
      dp[kl][i] = aa % 2;
      kl++;
      aa /= 2;
    }
  }
  long long cur = 1;
  for (int i = 0; i <= 60; i++) {
    cur *= 2;
  }
  cur /= 2;
  for (int i = M; i > -1; i--) {
    vector<pair<long long, long long> > b;
    for (int j = 0; j < n; j++) {
      b.push_back({a[j] % cur, j});
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long a1 = 0, a2 = 0;
    for (int j = 0; j < n; j++) {
      a1 += dp[i][j];
      a2 += 1 - dp[i][j];
    }
    vector<long long> dp_(n + 1);
    dp_[0] = min(a1 + dp[i + 1][0], a2 + dp[i + 1][a1]);
    long long gv = 0;
    for (int j = 0; j < n; j++) {
      if (!dp[i][b[j].second]) {
        a1++;
        a2--;
        dp_[j + 1] = min(a1 + dp[i + 1][gv], a2 + dp[i + 1][a1 + gv]);
      } else {
        gv++;
        a1--;
        a2++;
        dp_[j + 1] = min(a1 + dp[i + 1][gv], a2 + dp[i + 1][a1 + gv]);
      }
    }
    for (int j = 0; j < n + 1; j++) {
      dp[i][j] = dp_[j];
    }
    if (i <= 60) cur /= 2;
  }
  cout << dp[0][0];
}
