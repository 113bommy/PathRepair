#include <bits/stdc++.h>
using namespace std;
long long f[3] = {0};
long long nb, ns, nc, push_back, ps, pc, r, ans;
long long cost(long long m) {
  long long rb = 0, rs = 0, rc = 0, tc;
  if (f[0] != 0) {
    rb = m * f[0];
    if (rb > nb)
      rb -= nb;
    else
      rb = 0;
    rb *= push_back;
  }
  if (f[1] != 0) {
    rs = m * f[1];
    if (rs > ns)
      rs -= ns;
    else
      rs = 0;
    rs *= ps;
  }
  if (f[2] != 0) {
    rc = m * f[2];
    if (rc > nc)
      rc -= nc;
    else
      rc = 0;
    rc *= pc;
  }
  tc = rb + rs + rc;
  return (tc);
}
long long binarySearch(long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (cost(mid) <= x && cost(mid + 1) > x) return mid;
    if (cost(mid) > x) return binarySearch(l, mid - 1, x);
    return binarySearch(mid + 1, r, x);
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  cin >> nb >> ns >> nc;
  cin >> push_back >> ps >> pc;
  cin >> r;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'B')
      f[0]++;
    else if (s[i] == 'S')
      f[1]++;
    else if (s[i] == 'C')
      f[2]++;
  }
  ans = binarySearch(0, 1000000000200, r);
  cout << ans;
  return (0);
}
