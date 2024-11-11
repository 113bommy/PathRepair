#include <bits/stdc++.h>
using namespace std;
inline long long minOf(long long x, long long y) { return (x < y ? x : y); }
inline long long maxOf(long long x, long long y) { return (x > y ? x : y); }
inline long long mabs(long long x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int xc[100005], yc[100005], zc[100005];
  for (int i = 0; i < s.length(); i++) {
    xc[i] = 0;
    yc[i] = 0;
    zc[i] = 0;
  }
  for (int i = 0; i < s.length(); i++) {
    if (i > 0) {
      xc[i] = xc[i - 1];
      yc[i] = yc[i - 1];
      zc[i] = zc[i - 1];
    }
    if (s[i] == 'x')
      xc[i]++;
    else if (s[i] == 'y')
      yc[i]++;
    else
      zc[i]++;
  }
  int m;
  cin >> m;
  int l, r;
  int x, y, z;
  int dxy, dxz, dyz;
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    l--;
    r--;
    if (r - l < 2) {
      cout << "YES" << endl;
      continue;
    }
    x = xc[r] - (l == 0 ? 0 : xc[l - 1]);
    y = yc[r] - (l == 0 ? 0 : yc[l - 1]);
    z = zc[r] - (l == 0 ? 0 : zc[l - 1]);
    dxy = int(mabs(x - y));
    dxz = int(mabs(x - z));
    dyz = int(mabs(y - z));
    if (dxy > 1 || dxz > 1 || dyz > 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
