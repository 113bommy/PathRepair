#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
long long res(vector<long long> &c, long long bit) {
  if (bit < 0 || a.size() == 0) return 0;
  vector<long long> l, r;
  for (long long i = 0; i < c.size(); i++) {
    if (((c[i] >> bit) & 1) == 0)
      l.push_back(c[i]);
    else
      r.push_back(c[i]);
  }
  if (l.size() == 0) return res(r, bit - 1);
  if (r.size() == 0) return res(l, bit - 1);
  return min(res(l, bit - 1), res(r, bit - 1)) + 1 << bit;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  cout << res(a, 30);
}
