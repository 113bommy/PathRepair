#include <bits/stdc++.h>
using namespace std;
long long fun(long long u, long long d, long long l, long long r, long long mi,
              long long xx, long long yy) {
  long long t = 0, tt = 0;
  t += r;
  t -= l;
  tt += u;
  tt -= d;
  if (llabs(xx - t) + llabs(yy - tt) <= mi) {
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long x1, y1, y2, x2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long xx, yy;
  xx = x2 - x1;
  yy = y2 - y1;
  long long f[n + 1][4];
  memset(f, 0, sizeof(f));
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'U') f[i + 1][0]++;
    if (s[i] == 'D') f[i + 1][1]++;
    if (s[i] == 'L') f[i + 1][2]++;
    if (s[i] == 'R') f[i + 1][3]++;
    f[i + 1][0] += f[i][0];
    f[i + 1][1] += f[i][1];
    f[i + 1][2] += f[i][2];
    f[i + 1][3] += f[i][3];
  }
  long long hi, lo, mi;
  hi = 100000000000000000;
  lo = 1;
  long long ans = -1;
  while (hi >= lo) {
    mi = (lo + hi) / 2;
    long long u, d, l, r;
    u = (f[n][0] * (mi / n)) + (f[mi % n][0]);
    d = (f[n][1] * (mi / n)) + (f[mi % n][1]);
    l = (f[n][2] * (mi / n)) + (f[mi % n][2]);
    r = (f[n][3] * (mi / n)) + (f[mi % n][3]);
    if (fun(u, d, l, r, mi, xx, yy) == true) {
      ans = mi;
      hi = mi - 1;
    } else {
      lo = mi + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
