#include <bits/stdc++.h>
using namespace std;
long long fact[1000006];
long long ifact[1000006];
long long pwr(long long base, long long p, long long mod = 1000000007) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
void init() {
  fact[0] = 1;
  ifact[0] = 1;
  for (long long i = 1; i < 1000006; ++i) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    ifact[i] = pwr(fact[i], 1000000007 - 2);
  }
}
long long S(long long a) {
  a %= 1000000007;
  while (a < 0) a += 1000000007;
  return a;
}
map<long long, long long> mp;
int main() {
  init();
  long long i, j, n, a, ans = 0;
  vector<pair<long long, long long> > v;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a);
    mp[a]++;
  }
  for (auto el : mp) v.push_back(el);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long long tot = v[0].second;
  for (i = 1; i < v.size(); i++) {
    long long num = v[i].first;
    long long freq = v[i].second;
    long long curr =
        fact[n] * ifact[tot + freq] * (freq * fact[tot + freq - 1]);
    ans = S(ans + S(num * curr));
    tot = S(tot + freq);
  }
  printf("%lld\n", ans);
  return 0;
}
