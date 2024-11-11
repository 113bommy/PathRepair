#include <bits/stdc++.h>
using namespace std;
vector<long long> s1, s2, v;
vector<long long> bld(vector<long long> &a) {
  int n = a.size(), m = 1;
  while ((m) < (n)) (m) <<= 1;
  ;
  vector<long long> b(m << 1);
  for (int i = 0; i < n; i++) b[i + m] = a[i];
  for (int i = m - 1; i > 0; i--) b[i] = b[i << 1] + b[(i << 1) + 1];
  return b;
}
long long find(vector<long long> &a, long long l, long long r) {
  long long res = 0;
  if (l == r) res = a[l];
  while (l < r) {
    if (l & 1) res += a[l];
    if (!(r & 1)) res += a[r];
    l = (l + 1) >> 1;
    r = (r - 1) >> 1;
    if (l == r) res += a[l];
  }
  return res;
}
int main() {
  int n, m = 1;
  cin >> n;
  while ((m) < (n)) (m) <<= 1;
  ;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  s1 = bld(v);
  sort(v.begin(), v.end());
  s2 = bld(v);
  int eprst;
  cin >> eprst;
  while (eprst-- > 0) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    --r;
    l += m;
    r += m;
    if (t == 1)
      cout << find(s1, l, r) << endl;
    else
      cout << find(s2, l, r) << endl;
  }
  return 0;
}
