#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 12;
const int MOD = 1e9 + 7;
int a[MAXN];
vector<int> xsldf[MAXN];
int pref[MAXN];
long long pw(long long a, int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    long long x = pw(a, n / 2);
    return (x * x) % MOD;
  } else {
    long long x = pw(a, n - 1);
    return (x * a) % MOD;
  }
}
int get(int l, int r) { return pref[r] - pref[l - 1]; }
bool debug = 0;
int main() {
  int n;
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    pref[a[i]]++;
  }
  for (int i = 1; i <= mx; ++i) {
    pref[i] += pref[i - 1];
  }
  for (int i = 1; i <= mx; ++i) {
    for (int e = i; e <= mx; e = e + i) {
      xsldf[e].push_back(i);
    }
  }
  long long ans = 0;
  for (int val = 1; val <= mx; ++val) {
    long long res = 1;
    for (int i = 0; i < ((int)xsldf[val].size()); ++i) {
      int sum;
      if (i == ((int)xsldf[val].size()) - 1) {
        sum = get(val, mx);
        if (debug) cerr << " $ " << val << " " << sum << endl;
        res = res * ((pw(i + 1, sum) - pw(i, sum) + MOD));
        res %= MOD;
      } else {
        int v1 = xsldf[val][i], v2 = xsldf[val][i + 1];
        sum = get(v1, v2 - 1);
        res = res * pw(i + 1, sum);
        res %= MOD;
      }
    }
    if (debug) cerr << " $ " << val << ": " << res << endl;
    ans += res;
  }
  cout << ans % MOD << endl;
  return 0;
}
