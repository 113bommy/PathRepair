#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 50;
const double eps = 5e-8;
int n;
pair<int, int> t[N];
long long spe[N];
int loc[N], tmp[N];
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (long long)a.first * b.second > (long long)b.first * a.second ||
         (long long)a.first * b.second == (long long)b.first * a.second &&
             a.first < b.first;
}
double tr[N];
double query(int x) {
  double ret = 0;
  for (; x; x -= ((x) & -(x))) ret = max(ret, tr[x]);
  return ret;
}
void change(int x, double v) {
  for (; x <= tmp[0]; x += ((x) & -(x))) tr[x] = max(tr[x], v);
}
long long SUMT;
bool ok(double c) {
  c /= SUMT;
  memset(tr, 0, sizeof tr);
  double pret = 0;
  for (int l = 1; l <= n; l++) {
    int r = l;
    double sumt = 0;
    while (spe[r] == 0) {
      sumt += t[r].second;
      r++;
    }
    sumt += t[r].second;
    double pre_mx = 0;
    for (int i = l, g = i; i <= r; i++) {
      double front = t[i].first * (1 - c * (pret + t[i].second));
      double back = t[i].first * (1 - c * (pret + sumt));
      while (t[i].first != t[g].first) {
        pre_mx = max(pre_mx, t[g].first * (1 - c * (pret + t[g].second)));
        g++;
      }
      if (query(loc[i] - 1) > back || pre_mx > back) {
        return 0;
      }
      change(loc[i], front);
    }
    pret += sumt;
    l = r;
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &t[i].first);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i].second);
    SUMT += t[i].second;
  }
  sort(t + 1, t + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    spe[i] = (i == n) ||
             (t[i].first * t[i + 1].second != t[i + 1].first * t[i].second);
  }
  for (int i = 1; i <= n; i++) {
    tmp[++tmp[0]] = t[i].first;
  }
  sort(tmp + 1, tmp + 1 + n);
  tmp[0] = unique(tmp + 1, tmp + 1 + tmp[0]) - tmp - 1;
  for (int i = 1; i <= n; i++) {
    loc[i] = lower_bound(tmp + 1, tmp + 1 + tmp[0], t[i].first) - tmp;
  }
  double l = 0, r = 1, ans = 0;
  while (l + eps < r) {
    if (ok((l + r) * 0.5)) {
      l = ans = (l + r) * 0.5;
      l += eps;
    } else {
      r = (l + r) * 0.5;
    }
  }
  printf("%.5lf\n", ans);
}
