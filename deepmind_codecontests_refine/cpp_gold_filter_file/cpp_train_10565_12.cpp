#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} a[10001], b[10001], d[10001], A[10001], B[10001];
struct xl {
  ;
  double X1, Y1, X2, Y2;
};
int n, m, N, M, i, j, k, l, mn2, t;
double mn, Mn, s, s1, s2, S1, S2, ss;
void swap(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}
double cj(xl a, xl b) {
  return (b.X2 - b.X1) * (a.Y2 - a.Y1) - (a.X2 - a.X1) * (b.Y2 - b.Y1);
}
double dj(xl a, xl b) {
  return (a.X2 - a.X1) * (b.X2 - b.X1) + (a.Y2 - a.Y1) * (b.Y2 - b.Y1);
}
bool cmp(point a, point b) {
  double s = cj({0, 0, a.x, a.y}, {0, 0, b.x, b.y});
  return s < -0.00000001 ||
         ((s) > 0 ? (s) : -(s)) <= 0.00000001 &&
             (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}
void pd(int t1, int t2) {
  int i, j, k, l;
  s1 = 2133333333;
  s2 = 2133333333;
  for (i = 1; i <= t; i++)
    if (i != t1 && i != t2) {
      s = cj({d[i].x, d[i].y, d[t1].x, d[t1].y},
             {d[i].x, d[i].y, d[t2].x, d[t2].y});
      ss = s;
      if (((ss) > 0 ? (ss) : -(ss)) > 0.00000001) {
        s = dj({d[i].x, d[i].y, d[t1].x, d[t1].y},
               {d[i].x, d[i].y, d[t2].x, d[t2].y}) /
            s;
        if (ss > 0)
          s2 = min(s2, -s);
        else
          s1 = min(s1, s);
      } else if (dj({d[i].x, d[i].y, d[t1].x, d[t1].y},
                    {d[i].x, d[i].y, d[t2].x, d[t2].y}) > 0.00000001)
        return;
      if (s1 + s2 < 0.00000001) return;
    }
  for (i = 1; i <= m; i++) {
    s = cj({b[i].x, b[i].y, d[t1].x, d[t1].y},
           {b[i].x, b[i].y, d[t2].x, d[t2].y});
    ss = s;
    if (((ss) > 0 ? (ss) : -(ss)) > 0.00000001) {
      s = dj({b[i].x, b[i].y, d[t1].x, d[t1].y},
             {b[i].x, b[i].y, d[t2].x, d[t2].y}) /
          s;
      if (ss > 0)
        s1 = min(s1, s);
      else
        s2 = min(s2, -s);
    } else if (dj({b[i].x, b[i].y, d[t1].x, d[t1].y},
                  {b[i].x, b[i].y, d[t2].x, d[t2].y}) < -0.00000001)
      return;
    if (s1 + s2 < 0.00000001) return;
  }
  printf("YES\n");
  exit(0);
}
void dg(int x, int y) {
  int i, j, k, l, mx, bz = 1;
  if (x + 1 >= y) return;
  if (x == 1 && y == t) {
    if (cj({d[2].x, d[2].y, d[1].x, d[1].y}, {d[2].x, d[2].y, d[t].x, d[t].y}) <
        0)
      bz = -1;
    s1 = -2133333333;
    for (i = 2; i <= t - 1; i++) {
      s = dj({d[i].x, d[i].y, d[1].x, d[1].y},
             {d[i].x, d[i].y, d[t].x, d[t].y}) /
          cj({d[i].x, d[i].y, d[1].x, d[1].y},
             {d[i].x, d[i].y, d[t].x, d[t].y}) *
          bz;
      if (s > s1) s1 = s, mx = i;
    }
    pd(1, mx);
    pd(t, mx);
    dg(1, mx);
    dg(mx, t);
  } else {
    if (cj({d[x + 2].x, d[x + 2].y, d[x].x, d[x].y},
           {d[x + 2].x, d[x + 2].y, d[x + 1].x, d[x + 1].y}) < 0)
      bz = -1;
    s1 = -2133333333;
    for (i = x + 2; i <= y; i++) {
      s = dj({d[i].x, d[i].y, d[x].x, d[x].y},
             {d[i].x, d[i].y, d[x + 1].x, d[x + 1].y}) /
          cj({d[i].x, d[i].y, d[x].x, d[x].y},
             {d[i].x, d[i].y, d[x + 1].x, d[x + 1].y}) *
          bz;
      if (s > s1) s1 = s, mx = i;
    }
    pd(x, mx);
    pd(x + 1, mx);
    dg(x + 1, mx);
    dg(mx, y);
  }
}
void work() {
  int i, j, k, l;
  mn = 2133333333;
  for (i = 1; i <= n; i++)
    if (a[i].y < mn) mn = a[i].y, Mn = a[i].x, mn2 = i;
  j = 0;
  for (i = 1; i <= n; i++)
    if (i != mn2) a[++j] = {a[i].x - Mn, a[i].y - mn};
  --n;
  for (i = 1; i <= m; i++) b[i] = {b[i].x - Mn, b[i].y - mn};
  sort(a + 1, a + n + 1, cmp);
  t = 1;
  d[1] = {0, 0};
  for (i = 1; i <= n; i++) {
    while (t > 1 && cj({d[t - 1].x, d[t - 1].y, d[t].x, d[t].y},
                       {d[t - 1].x, d[t - 1].y, a[i].x, a[i].y}) >= -0.00000001)
      --t;
    d[++t] = a[i];
  }
  for (i = 1; i <= t - 1; i++) pd(i, i + 1);
  pd(t, 1);
  if (t == 2)
    pd(1, 2);
  else if (t == 3)
    pd(1, 2), pd(2, 3), pd(3, 1);
  else
    dg(1, t);
}
int main() {
  scanf("%d%d", &N, &M);
  if (N == 1 || M == 1) {
    printf("YES\n");
    return 0;
  }
  for (i = 1; i <= N; i++) scanf("%lf%lf", &A[i].x, &A[i].y);
  for (i = 1; i <= M; i++) scanf("%lf%lf", &B[i].x, &B[i].y);
  memcpy(a, A, sizeof(A));
  memcpy(b, B, sizeof(B));
  n = N, m = M;
  work();
  memcpy(a, B, sizeof(B));
  memcpy(b, A, sizeof(A));
  n = M, m = N;
  work();
  printf("NO\n");
  fclose(stdin);
  fclose(stdout);
  return 0;
}
