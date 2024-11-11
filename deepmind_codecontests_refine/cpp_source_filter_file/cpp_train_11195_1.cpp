#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
struct Data {
  long long x, y;
} bottle[N];
double dist(long long x1, long long y1, long long x2, long long y2) {
  return sqrt(((double)x1 - (double)x2) * ((double)x1 - (double)x2) +
              ((double)y1 - (double)y2) * ((double)y1 - (double)y2));
}
double dista[N], distb[N], distt[N];
signed main() {
  long long n, ax, ay, bx, by, tx, ty;
  scanf("%lld %lld %lld %lld %lld %lld", &ax, &ay, &bx, &by, &tx, &ty);
  scanf("%lld", &n);
  double sum = 0;
  for (long long i = 0; i < n; i++) {
    scanf("%lld %lld", &bottle[i].x, &bottle[i].y);
    sum = sum + 2.0 * dist(bottle[i].x, bottle[i].y, tx, ty);
    dista[i] = dist(ax, ay, bottle[i].x, bottle[i].y);
    distb[i] = dist(bx, by, bottle[i].x, bottle[i].y);
    distt[i] = dist(tx, ty, bottle[i].x, bottle[i].y);
  }
  if (n == 1) {
    return !printf("%.12f", min(dist(ax, ay, bottle[1].x, bottle[1].y),
                                dist(bx, by, bottle[1].x, bottle[1].y)) +
                                dist(bottle[1].x, bottle[1].y, tx, ty));
  }
  long long pos1, pos2;
  bool ok = false;
  vector<pair<double, long long> > can1, can2;
  for (long long i = 0; i < n; i++) {
    if (dista[i] - distt[i] < 0) {
      can1.push_back(make_pair(dista[i] - distt[i], i));
      ok = true;
    } else {
      can1.push_back(make_pair(0.0, i));
    }
  }
  sort(can1.begin(), can1.end());
  for (long long i = 0; i < n; i++) {
    if (distb[i] - distt[i] < 0) {
      can2.push_back(make_pair(distb[i] - distt[i], i));
      ok = true;
    } else {
      can2.push_back(make_pair(0.0, i));
    }
  }
  sort(can2.begin(), can2.end());
  long long era1 = n, era2 = n;
  double res = 0;
  if (!ok) goto br;
  if (can1[0].second != can2[0].second) {
    res += can1[0].first + can2[0].first;
    era1 = can1[0].second;
    era2 = can2[0].second;
    res += 2 * distt[era1] + 2 * distt[era2];
  } else {
    if (can1[0].first + can2[1].first < can1[1].first + can2[0].first) {
      res += can1[0].first + can2[1].first;
      era1 = can1[0].second;
      era2 = can2[1].second;
      res += 2 * distt[era1] + 2 * distt[era2];
    } else {
      res += can1[1].first + can2[0].first;
      era1 = can1[1].second;
      era2 = can2[0].second;
      res += 2 * distt[era1] + 2 * distt[era2];
    }
  }
br:;
  if (!ok) {
    res = 1e18;
    for (long long i = 0; i < n; i++) {
      res = min(res, dista[i] - distt[i]);
      res = min(res, distb[i] - distt[i]);
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == era1 || i == era2) continue;
    res += 2 * distt[i];
  }
  printf("%.12f", res);
  return 0;
}
