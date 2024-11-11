#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000000001;
const double inf = 1e13;
struct W {
  long long y, x;
};
bool operator<(const W &a, const W &b) { return a.y * b.x < b.y * a.x; }
bool operator==(const W &a, const W &b) { return a.y * b.x == b.y * a.x; }
struct O {
  W l, r;
};
bool operator<(const O &a, const O &b) {
  return a.l == b.l ? a.r < b.r : a.l < b.l;
}
struct N {
  long long x, y;
};
bool operator<(const N &a, const N &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
N a[4005], d[4005];
vector<O> w;
vector<W> b;
int n, x[2005], yl[2005], yr[2005];
double ans, f[4000005];
void go(long long Y, long long X) {
  double l = inf, r = -inf;
  for (int i = 1; i <= n; ++i) {
    l = min(l, yl[i] + (double)x[i] * Y / X);
    r = max(r, yr[i] + (double)x[i] * Y / X);
  }
  ans = min(ans, r - l);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &yl[i], &yr[i], &x[i]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) {
        swap(yl[i], yl[j]);
        swap(yr[i], yr[j]);
        swap(x[i], x[j]);
      }
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (x[i] < x[j]) {
        w.push_back((O){(W){yl[i] - yr[j], x[j] - x[i]},
                        (W){yr[i] - yl[j], x[j] - x[i]}});
      }
  sort(w.begin(), w.end());
  int t = 0;
  for (unsigned i = 1; i < w.size(); ++i)
    if (w[t].r < w[i].l || w[t].r == w[i].l)
      w[++t] = w[i];
    else
      w[t].r = max(w[t].r, w[i].r);
  if (w.size() == 0) {
    int l = 100000000, r = -100000000;
    for (int i = 1; i <= n; ++i) l = min(l, yl[i]), r = max(r, yr[i]);
    printf("%d.0000000\n", r - l);
    return 0;
  }
  for (int i = 0; i <= t; ++i) {
    if (!(b.size() && b[b.size() - 1] == w[i].l)) b.push_back(w[i].l);
    b.push_back(w[i].r);
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = (N){x[i], yl[i]};
    a[i + n] = (N){x[i], yr[i]};
  }
  t = 0;
  for (int i = n + 1; i <= n + n; ++i) {
    if (t == 0) {
      d[++t] = a[i];
    } else if (a[i].x == d[t].x) {
      d[t].y = max(d[t].y, a[i].y);
    } else
      d[++t] = a[i];
    while (t >= 3) {
      if ((d[t].y - d[t - 1].y) * (d[t - 1].x - d[t - 2].x) >=
          (d[t - 1].y - d[t - 2].y) * (d[t].x - d[t - 1].x))
        d[t - 1] = d[t], --t;
      else
        break;
    }
  }
  int k = 1;
  for (unsigned I = 0; I < b.size(); ++I) {
    while (k < t && d[k].y + (double)d[k].x * b[I].y / b[I].x <=
                        d[k + 1].y + (double)d[k + 1].x * b[I].y / b[I].x)
      ++k;
    f[I] = d[k].y + (double)d[k].x * b[I].y / b[I].x;
  }
  t = 0;
  for (int i = 1; i <= n; ++i) {
    if (t == 0) {
      d[++t] = a[i];
    } else if (a[i].x == d[t].x) {
      d[t].y = min(d[t].y, a[i].y);
    } else
      d[++t] = a[i];
    while (t >= 3) {
      if ((d[t].y - d[t - 1].y) * (d[t - 1].x - d[t - 2].x) <=
          (d[t - 1].y - d[t - 2].y) * (d[t].x - d[t - 1].x))
        d[t - 1] = d[t], --t;
      else
        break;
    }
  }
  k = t;
  for (unsigned I = 0; I < b.size(); ++I) {
    while (k > 1 && d[k].y + (double)d[k].x * b[I].y / b[I].x >=
                        d[k - 1].y + (double)d[k - 1].x * b[I].y / b[I].x)
      --k;
    f[I] -= d[k].y + (double)d[k].x * b[I].y / b[I].x;
  }
  ans = inf;
  for (unsigned I = 0; I < b.size(); ++I) ans = min(ans, f[I]);
  printf("%.10lf\n", ans);
  return 0;
}
