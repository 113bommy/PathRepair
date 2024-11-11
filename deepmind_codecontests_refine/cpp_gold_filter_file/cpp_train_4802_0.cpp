#include <bits/stdc++.h>
using namespace std;
const long long M = 3162280;
const long long maxs = 10000000000000LL;
vector<long long> s, v;
vector<pair<long long, long long> > ans;
long long sz, n, m, pos;
bool fnd(long long x) {
  long long p = pos;
  long long q = p + 1;
  while (true) {
    if (s[q] - s[p] < x)
      q++;
    else if (s[q] - s[p] == x) {
      ans.push_back({p, q});
      pos = q + 1;
      return true;
    } else
      p++;
    if (p == q) q++;
    if (q > sz) return false;
  }
}
int32_t main() {
  cin >> n;
  m = n / 2;
  for (long long i = 1; i <= m; i++) {
    long long x;
    scanf("%lld", &x);
    v.push_back(x);
  }
  s.push_back(0);
  for (long long i = 1; i * i <= maxs; i++) {
    s.push_back(i * i);
    sz = i;
  }
  pos = 1;
  for (auto x : v)
    if (!fnd(x)) return cout << "No" << endl, 0;
  long long bef = 0;
  cout << "Yes" << endl;
  for (auto p : ans) {
    printf("%lld %lld ", s[p.first] - s[bef], s[p.second] - s[p.first]);
    bef = p.second;
  }
  return 0;
}
