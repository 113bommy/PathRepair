#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ans[200010];
long long cns[200010];
pair<long long, long long> ins[200010];
long long kq(long long a, int n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    n >>= 1;
  }
  return res % mod;
}
long long C(long long n, long long m) {
  long long a = (ans[n] * cns[n - m]) % mod;
  a = (a * cns[m]) % mod;
  return a;
}
long long dp[3000];
int n, m, k;
int main() {
  ans[0] = 1;
  cns[0] = 1;
  for (int i = 1; i < 101120; i++) {
    ans[i] = (ans[i - 1] * i) % mod;
    cns[i] = kq(ans[i], mod - 2);
  }
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> ins[i].first >> ins[i].second;
    ins[i].first--;
    ins[i].second--;
  }
  sort(ins, ins + k);
  ins[k].first = n - 1;
  ins[k].second = m - 1;
  for (int i = 0; i <= k; i++) {
    long long x = ins[i].first;
    long long y = ins[i].second;
    dp[i] = C(x + y, x);
    for (int j = 0; j < i; j++) {
      long long xx = ins[j].first;
      long long yy = ins[j].second;
      if (x < xx || y < yy) continue;
      long long a = (C(x + y - xx - yy, x - xx) * dp[j]) % mod;
      dp[i] = ((dp[i] - a) % mod + mod) % mod;
    }
  }
  cout << (dp[k] + mod) % mod << endl;
  return 0;
}
