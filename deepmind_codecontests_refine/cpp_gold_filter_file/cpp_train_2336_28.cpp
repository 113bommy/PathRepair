#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 5e5;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
long long n, m, b;
long long dp[(1 << 20)];
long long monitor[(1 << 20)];
struct frnd {
  long long prc, mntr;
  int tasks;
} fr[maxn];
bool cmp(frnd i, frnd j) { return (i.mntr < j.mntr); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> b;
  for (int i = 1; i <= n; i++) {
    cin >> fr[i].prc;
    cin >> fr[i].mntr;
    int x = 0;
    cin >> x;
    int val = 0;
    for (int j = 0; j < x; j++) {
      int inp;
      cin >> inp;
      inp--;
      val |= (1 << inp);
    }
    fr[i].tasks = val;
  }
  sort(fr + 1, fr + n + 1, cmp);
  memset(dp, 63, sizeof dp);
  ;
  dp[0] = 0;
  long long ans = dp[1];
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < (1 << m) - 1; i++) {
      long long boz = dp[i | fr[j].tasks];
      dp[i | fr[j].tasks] = min(dp[i | fr[j].tasks], dp[i] + fr[j].prc);
    }
    if (dp[(1 << m) - 1] != ans) {
      ans = min(ans, dp[(1 << m) - 1] + b * fr[j].mntr);
    }
  }
  dp[(1 << m) - 1] = ans;
  long long maxval[2];
  memset(maxval, 63, sizeof maxval);
  ;
  if (dp[(1 << m) - 1] == maxval[0]) {
    cout << -1;
    return (0);
    ;
  }
  cout << dp[(1 << m) - 1];
  return (0);
}
