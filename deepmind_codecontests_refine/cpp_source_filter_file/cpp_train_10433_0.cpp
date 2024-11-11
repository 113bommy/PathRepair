#include <bits/stdc++.h>
using namespace std;
const long long N = 200, mx = 9e17;
long long xz, yz, ax, ay, bx, by;
long long xs, ys, t;
long long x[N], y[N];
long long ans;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> xz >> yz >> ax >> ay >> bx >> by >> xs >> ys >> t;
  x[0] = xz;
  y[0] = yz;
  long long j;
  for (j = 1; j < N; ++j) {
    x[j] = x[j - 1] * ax + bx;
    y[j] = y[j - 1] * ay + by;
    if (x[j] > mx || y[j] > mx) break;
  }
  for (long long i = 0; i <= j; ++i) {
    long long cand = 0;
    long long rem = t;
    long long prevx = xs, prevy = ys;
    for (long long id = i; id >= 0; --id) {
      if (x[id] > prevx)
        rem -= x[id] - prevx;
      else
        rem -= prevx - x[id];
      if (rem < 0) break;
      if (y[id] > prevy)
        rem -= y[id] - prevy;
      else
        rem -= prevy - y[id];
      if (rem < 0) break;
      cand++;
      prevx = x[id];
      prevy = y[id];
    }
    ans = max(ans, cand);
    cand = 0;
    rem = t;
    prevx = xs, prevy = ys;
    for (long long id = i; id <= j; ++id) {
      if (x[id] > prevx)
        rem -= x[id] - prevx;
      else
        rem -= prevx - x[id];
      if (rem < 0) break;
      if (y[id] > prevy)
        rem -= y[id] - prevy;
      else
        rem -= prevy - y[id];
      if (rem < 0) break;
      cand++;
      prevx = x[id];
      prevy = y[id];
    }
    ans = max(ans, cand);
  }
  cout << ans << endl;
  return 0;
}
