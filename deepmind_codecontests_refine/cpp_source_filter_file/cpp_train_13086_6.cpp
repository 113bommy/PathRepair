#include <bits/stdc++.h>
using namespace std;
long long n;
string p, ans;
map<long long, string> ma;
signed main() {
  scanf("%lld", &n);
  for (long long i = 2; i * i <= n; i++)
    for (long long j = i * i, k = 2; j <= n; j *= i, ++k) {
      p = to_string(i) + '^' + to_string(k);
      if (!ma[j].size()) ma[j] = to_string(j);
      if (ma[j].size() > p.size()) ma[j] = p;
    }
  ans = to_string(n);
  for (map<long long, string>::iterator it = ma.begin(); it != ma.end(); ++it) {
    p = it->second;
    long long a = it->first, b = n / a, c = n - a * b;
    if (!ma[b].size()) ma[b] = to_string(b);
    if (!ma[c].size()) ma[c] = to_string(c);
    if (b > 1) p += '^' + ma[b];
    if (c) p += '+' + ma[c];
    if (ans.size() > p.size()) ans = p;
  }
  cout << ans;
  return 0;
}
