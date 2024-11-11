#include <bits/stdc++.h>
using namespace std;
long long fac[11];
map<long long, bool> lc;
int32_t main() {
  vector<long long> all;
  for (long long i = 1; i <= 10; ++i) {
    for (long long j = 0; j <= i; ++j) {
      vector<long long> v;
      for (long long k = 0; k < j; ++k) v.push_back(4);
      for (long long k = 0; k < i - j; ++k) v.push_back(7);
      do {
        long long t = 0, c = 1;
        for (long long k : v) t += c * k, c *= 10;
        all.push_back(t);
      } while (next_permutation(v.begin(), v.end()));
    }
  }
  sort(all.begin(), all.end());
  fac[0] = 1;
  for (long long i = 1; i <= 10; ++i) fac[i] = fac[i - 1] * i;
  vector<long long> v;
  long long n, k;
  cin >> n >> k;
  if (n <= 10 && fac[n] < k) return cout << "-1" << endl, 0;
  --k;
  for (long long i : all)
    if (i <= n) v.push_back(i);
  long long z = -1;
  for (long long i = n; i >= 1; --i) {
    long long c = n - i;
    if (c * fac[c] >= k) {
      z = i;
      break;
    }
  }
  if (z == -1) z = 1;
  long long ans = 0;
  for (long long i : v)
    if (i < z) ++ans;
  for (long long i : v) lc[i] = true;
  long long cur = 0;
  vector<long long> ch;
  for (long long i = z; i <= n; ++i) ch.push_back(i);
  for (long long i = z; i <= n; ++i) {
    long long d = 31, p = 0;
    while (d--) {
      if (p + (1 << d) < ch.size()) {
        long long u = ch[p + (1 << d)];
        long long c = p + (1 << d);
        if (cur + c * fac[n - i] <= k) p += (1 << d);
      }
    }
    cur += p * fac[n - i];
    if (lc[i] && lc[ch[p]]) ++ans;
    vector<long long> nch;
    for (long long j : ch)
      if (j != ch[p]) nch.push_back(j);
    ch = nch;
  }
  cout << ans << endl;
}
