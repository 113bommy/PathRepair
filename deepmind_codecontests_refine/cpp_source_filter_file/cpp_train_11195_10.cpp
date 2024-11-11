#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ps[100005];
pair<long long, long long> cla[2];
pair<long long, long long> clb[2];
int ox, oy;
double inline dist(long long x, long long y, long long a, long long b) {
  return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
bool inline cmp(long long x, long long y, pair<long long, long long> pl,
                pair<long long, long long> pr) {
  double a = dist(x, y, pl.first, pl.second);
  double b = dist(x, y, pr.first, pr.second);
  return dist(x, y, pl.first, pl.second) - dist(ox, oy, pl.first, pl.second) >
         dist(x, y, pr.first, pr.second) - dist(ox, oy, pr.first, pr.second);
}
int main() {
  int ax, ay, bx, by;
  int n, tmx, tmy;
  scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &ox, &oy);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &tmx, &tmy);
    ps[i] = make_pair(tmx, tmy);
  }
  cla[0] = clb[0] = ps[0];
  cla[1] = clb[1] = ps[1];
  if (cmp(ax, ay, ps[0], ps[1])) {
    swap(cla[0], cla[1]);
  }
  if (cmp(bx, by, ps[0], ps[1])) {
    swap(clb[0], clb[1]);
  }
  double tot = 0;
  for (int i = 0; i < n; i++) {
    tot += sqrt((ps[i].first - ox) * (ps[i].first - ox) +
                (ps[i].second - oy) * (ps[i].second - oy));
  }
  if (n == 1) {
    tot = tot * 2 + min(dist(ps[0].first, ps[0].second, ax, ay) -
                            dist(ox, oy, ps[0].first, ps[0].second),
                        dist(ps[0].first, ps[0].second, bx, by) -
                            dist(ox, oy, ps[0].first, ps[0].second));
    printf("%.10lf\n", tot);
    return 0;
  }
  for (int i = 2; i < n; i++) {
    if (cmp(ax, ay, cla[1], ps[i])) {
      cla[1] = ps[i];
    }
    if (cmp(ax, ay, cla[0], cla[1])) {
      swap(cla[0], cla[1]);
    }
    if (cmp(bx, by, clb[1], ps[i])) {
      clb[1] = ps[i];
    }
    if (cmp(bx, by, clb[0], clb[1])) {
      swap(clb[0], clb[1]);
    }
  }
  double tmp = tot;
  if (cla[0].first == clb[0].first && cla[0].second == clb[0].second) {
    tot = min(-dist(cla[0].first, cla[0].second, ox, oy) -
                  dist(clb[1].first, clb[1].second, ox, oy) +
                  dist(cla[0].first, cla[0].second, ax, ay) +
                  dist(clb[1].first, clb[1].second, bx, by),
              -dist(cla[1].first, cla[1].second, ox, oy) -
                  dist(clb[0].first, clb[0].second, ox, oy) +
                  dist(cla[1].first, cla[1].second, ax, ay) +
                  dist(clb[0].first, clb[0].second, bx, by)) +
          tot * 2;
  } else {
    tot = tot * 2 - dist(cla[0].first, cla[0].second, ox, oy) -
          dist(clb[0].first, clb[0].second, ox, oy) +
          dist(cla[0].first, cla[0].second, ax, ay) +
          dist(clb[0].first, clb[0].second, bx, by);
  }
  tot = min(tot, min(tmp * 2 - dist(cla[0].first, cla[0].second, ox, oy) +
                         dist(cla[0].first, cla[0].second, ax, ay),
                     tmp * 2 - dist(clb[0].first, clb[0].second, ox, oy) +
                         dist(clb[0].first, clb[0].second, ox, oy)));
  printf("%.10lf\n", tot);
}
