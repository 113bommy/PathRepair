#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e15;
const int gox[4] = {0, 0, 1, -1};
const int goy[4] = {1, -1, 0, 0};
long long x[4], y[4], ansx[4], ansy[4], tmpx[4], tmpy[4];
long long xlow[2], xhigh[2], ylow[2], yhigh[2];
void update(long long& low, long long& high, long long cur, long long sign,
            long long range) {
  low = max(low, cur + min(sign, 0ll) * range);
  high = min(high, cur + max(sign, 0ll) * range);
}
pair<long long, long long> getlen(long long* low, long long* high) {
  return {max(1ll, low[1] - high[0]), high[1] - low[0]};
}
bool check(long long range) {
  int dir[4];
  for (dir[0] = 0; dir[0] < 4; dir[0]++)
    for (dir[1] = 0; dir[1] < 4; dir[1]++)
      for (dir[2] = 0; dir[2] < 4; dir[2]++)
        for (dir[3] = 0; dir[3] < 4; dir[3]++) {
          vector<int> pos(4);
          iota(pos.begin(), pos.end(), 0);
          do {
            xlow[0] = xlow[1] = ylow[0] = ylow[1] = -(long long)1e18;
            xhigh[0] = xhigh[1] = yhigh[0] = yhigh[1] = (long long)1e18;
            for (int i = 0; i < 4; i++) {
              int xid = pos[i] >> 1;
              int yid = pos[i] & 1;
              update(xlow[xid], xhigh[xid], x[i], gox[dir[i]], range);
              update(ylow[yid], yhigh[yid], y[i], goy[dir[i]], range);
            }
            if (xlow[0] > xhigh[0]) continue;
            if (xlow[1] > xhigh[1]) continue;
            if (ylow[0] > yhigh[0]) continue;
            if (ylow[1] > yhigh[1]) continue;
            auto xlen = getlen(xlow, xhigh);
            auto ylen = getlen(ylow, yhigh);
            if (max(xlen.first, ylen.first) <= min(xlen.second, ylen.second)) {
              long long len = max(xlen.first, ylen.first);
              tmpx[0] = max(xlow[0], xlow[1] - len);
              tmpy[0] = max(ylow[0], ylow[1] - len);
              tmpx[1] = tmpx[0] + len;
              tmpy[1] = tmpy[0] + len;
              for (int i = 0; i < 4; i++) {
                int xid = pos[i] >> 1;
                int yid = pos[i] & 1;
                ansx[i] = tmpx[xid];
                ansy[i] = tmpy[yid];
              }
              return true;
            }
          } while (next_permutation(pos.begin(), pos.end()));
        }
  return false;
}
void solve() {
  for (int i = 0; i < 4; i++) {
    scanf("%I64d%I64d", &x[i], &y[i]);
  }
  long long l = 0, r = inf;
  while (l <= r) {
    long long md = (l + r) >> 1;
    if (check(md)) {
      r = md - 1;
    } else {
      l = md + 1;
    }
  }
  if (check(r + 1)) {
    printf("%I64d\n", r + 1);
    for (int i = 0; i < 4; i++) {
      printf("%I64d %I64d\n", ansx[i], ansy[i]);
    }
  } else {
    printf("-1\n");
  }
}
int main() {
  int tst;
  scanf("%d", &tst);
  for (int t = 1; t <= tst; t++) {
    solve();
  }
  return 0;
}
