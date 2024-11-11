#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, k, n, s, m;
  long long ans, z = 1;
  cin >> n;
  map<pair<int, int>, int> a;
  vector<int> c1(n + 1, 0), c2(n + 1, 0);
  vector<long long> fact(n + 1);
  fact[0] = 1, fact[1] = 1;
  for (long long i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % (998244353);
  for (int i = 0; i < n; i++) {
    cin >> j >> k;
    a[{j, k}]++;
  }
  ans = fact[n];
  k = -1, m = 0;
  auto p = a.begin();
  while (p != a.end()) {
    c1[(p->first).first] += p->second;
    c2[(p->first).second] += p->second;
    if ((p->second) > 1) z = (z * (fact[p->second])) % 998244353;
    if (((p->first).second) >= k)
      k = (p->first).second;
    else
      m++;
    p++;
  }
  long long x = 1, y = 1;
  for (int i = 1; i < n + 1; i++) {
    if (c1[i]) x = (x * fact[c1[i]]) % 998244353;
    if (c2[i]) y = (y * fact[c2[i]]) % 998244353;
  }
  if (m)
    ans = (ans - x - y + 2 * 998244353) % 998244353;
  else
    ans = (ans - x - y + 2 * 998244353 + z) % 998244353;
  cout << ans;
  return 0;
}
