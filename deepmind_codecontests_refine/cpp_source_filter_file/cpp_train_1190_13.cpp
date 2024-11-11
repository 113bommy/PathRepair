#include <bits/stdc++.h>
using namespace std;
const double inf = 1e100;
const int MAXN = (int)1e6 + 10;
struct point {
  long long x, y;
  int ind;
  void read() { scanf("%lf%lf", &x, &y); }
  double sqr_dist_to(point& r) {
    return ((x - r.x) * (x - r.x)) + ((y - r.y) * (y - r.y));
  }
  bool operator<(const point& r) const {
    return x < r.x || (x == r.x && y < r.y);
  }
};
point aux[MAXN], P[MAXN], v[MAXN];
int vn = 0;
int e[MAXN];
long long s[MAXN];
int a, b, N;
long long ans = 1ll << 60;
long long closest_pair(point p[], int n) {
  if (n <= 1) return 1ll << 60;
  if (n == 2) {
    if (p[0].y > p[1].y) swap(p[0], p[1]);
    long long d = p[0].sqr_dist_to(p[1]);
    if (d < ans) ans = d, a = p[0].ind, b = p[1].ind;
    return d;
  }
  int m = n / 2;
  long long x = p[m].x;
  long long dl = closest_pair(p, m);
  long long dr = closest_pair(p + m, n - m);
  long long d = min(dl, dr);
  int il = 0, ir = m, i = 0;
  while (il < m && ir < n) {
    if (p[il].y < p[ir].y)
      aux[i++] = p[il++];
    else
      aux[i++] = p[ir++];
  }
  while (il < m) aux[i++] = p[il++];
  while (ir < n) aux[i++] = p[ir++];
  vn = 0;
  for (int j = 0; j < n; j++) {
    p[j] = aux[j];
    if (((p[j].x - x) * (p[j].x - x)) <= ans) v[vn++] = p[j];
  }
  for (int j = 0; j < vn; j++) {
    for (int k = j + 1;
         k < vn && ((v[j].y - v[k].y) * (v[j].y - v[k].y)) <= ans; k++) {
      if (ans > p[j].sqr_dist_to(p[k])) {
        d = p[j].sqr_dist_to(p[k]);
        if (ans > d) {
          ans = d;
          a = p[k].ind, b = p[j].ind;
        }
      }
    }
  }
  return d;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &e[i]);
    s[i] = s[i - 1] + e[i];
    P[i] = {i, s[i], i};
  }
  long long d = closest_pair(P + 1, N);
  cout << d << endl;
  return 0;
}
