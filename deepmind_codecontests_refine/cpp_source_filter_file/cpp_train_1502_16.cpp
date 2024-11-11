#include <bits/stdc++.h>
using namespace std;
string st;
int nb, ns, nc, pb, ps, pc;
long long l, r;
int b, s, c;
bool can(long long mi, long long cost) {
  long long x = b * mi, y = s * mi, z = c * mi, k = cost;
  x -= nb;
  y -= ns;
  z -= nc;
  if (x > 0) {
    if (k - x * pb >= 0) {
      k -= x * pb;
      x = 0;
    }
  }
  if (y > 0) {
    if (k - y * ps >= 0) {
      k -= y * ps;
      y = 0;
    }
  }
  if (z > 0) {
    if (k - z * pc >= 0) {
      k -= z * pc;
      z = 0;
    }
  }
  if (x > 0 || y > 0 || z > 0) return false;
  return true;
}
long long binary(long long val) {
  l = 0, r = val;
  long long mid, ans = 0;
  while (l < r) {
    mid = l + (r - l + 1) / 2;
    if (can(mid, val)) {
      ans = mid;
      l = mid;
    } else
      r = mid - 1;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long m;
  cin >> st;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> m;
  for (int i = 0; i < st.length(); ++i) {
    switch (st[i]) {
      case 'B':
        ++b;
        break;
      case 'S':
        ++s;
        break;
      case 'C':
        ++c;
        break;
    }
  }
  cout << binary(m) << endl;
  return 0;
}
