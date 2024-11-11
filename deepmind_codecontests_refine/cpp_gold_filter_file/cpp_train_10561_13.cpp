#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
long long k, n[3], t[3], cum[4], ans = -1;
multiset<long long> s[3];
int main() {
  FastIO();
  cin >> k;
  for (int i = 0; i < 3; i++) cin >> n[i];
  cum[0] = 0;
  for (int i = 0; i < 3; i++) {
    cin >> t[i];
    cum[i + 1] = cum[i] + t[i];
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < n[i]; j++) s[i].insert(0);
  for (int i = 0; i < k; i++) {
    long long tot = 0;
    for (int j = 0; j < 3; j++) {
      long long val = *(s[j].begin());
      tot = max(tot, val - cum[j]);
    }
    for (int j = 0; j < 3; j++) {
      tot += t[j];
      s[j].erase(s[j].begin());
      s[j].insert(tot);
    }
  }
  long long ans = *(s[2].rbegin());
  cout << ans << '\n';
  return 0;
}
