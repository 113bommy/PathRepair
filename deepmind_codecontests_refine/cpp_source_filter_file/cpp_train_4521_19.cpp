#include <bits/stdc++.h>
using namespace std;
const double ef = 0.000000001;
double S, ans;
struct node {
  double x, y;
} p[305][1005], pp[305][1005], P[305][1005];
int q[1005], qq[1005], Last, A, n, k, i;
bool v[1005], V[1005];
int cmp(node i, node j) { return i.x < j.x; }
double work(double l, double r, double x) { return l + x * (r - l); }
double Find(double L, double R, double l, double r) {
  double mid = (l + r) / 2.0;
  while (l <= r) {
    if (work(Last, A, mid) > work(L, R, mid)) {
      l = mid + 0.0000001;
      mid = (l + r) / 2.0;
    } else {
      r = mid - 0.0000001;
      mid = (l + r) / 2.0;
    }
  }
  return mid;
}
double Find1(double L, double R, double l, double r) {
  double mid = (l + r) / 2.0;
  while (l <= r) {
    if (work(Last, A, mid) < work(L, R, mid)) {
      l = mid + 0.0000001;
      mid = (l + r) / 2.0;
    } else {
      r = mid - 0.0000001;
      mid = (l + r) / 2.0;
    }
  }
  return mid;
}
void add(int t, int l, int r) {
  int i;
  for (i = 1; i <= q[t]; i++) v[i] = V[i] = true;
  qq[t] = 0;
  for (i = 2; i <= q[t]; i++) {
    if (p[t][i - 1].y - ef < work(l, r, p[t][i - 1].x) &&
        p[t][i].y - ef < work(l, r, p[t][i].x))
      v[i] = v[i - 1] = false;
    else if (p[t][i - 1].y - ef < work(l, r, p[t][i - 1].x) &&
             p[t][i].y - ef > work(l, r, p[t][i].x)) {
      v[i - 1] = false;
      V[i - 1] = false;
      pp[t][++qq[t]].x =
          Find(p[t][i - 1].y - (p[t][i].y - p[t][i - 1].y) /
                                   (p[t][i].x - p[t][i - 1].x) * p[t][i - 1].x,
               p[t][i].y + (p[t][i].y - p[t][i - 1].y) /
                               (p[t][i].x - p[t][i - 1].x) * (1 - p[t][i].x),
               p[t][i - 1].x, p[t][i].x);
      pp[t][qq[t]].y = work(l, r, pp[t][qq[t]].x);
    } else if (p[t][i - 1].y - ef > work(l, r, p[t][i - 1].x) &&
               p[t][i].y - ef < work(l, r, p[t][i].x)) {
      v[i] = false;
      V[i] = false;
      pp[t][++qq[t]].x =
          Find1(p[t][i - 1].y - (p[t][i].y - p[t][i - 1].y) /
                                    (p[t][i].x - p[t][i - 1].x) * p[t][i - 1].x,
                p[t][i].y + (p[t][i].y - p[t][i - 1].y) /
                                (p[t][i].x - p[t][i - 1].x) * (1 - p[t][i].x),
                p[t][i - 1].x, p[t][i].x);
      pp[t][qq[t]].y = work(l, r, pp[t][qq[t]].x);
    }
  }
  double Last = 0;
  for (i = 1; i <= q[t]; i++)
    if (v[i]) pp[t][++qq[t]] = p[t][i];
  sort(pp[t] + 1, pp[t] + qq[t] + 1, cmp);
  q[t] = 0;
  if (pp[t][1].x > ef || !qq[t]) {
    p[t][++q[t]].y = l;
    p[t][q[t]].x = 0;
  }
  for (i = 1; i <= qq[t]; i++) p[t][++q[t]] = pp[t][i];
  if (pp[t][qq[t]].x - 1 < -ef || !qq[t]) {
    p[t][++q[t]].x = 1;
    p[t][q[t]].y = r;
  }
}
double WORK(int t) {
  double ans = 0;
  int i;
  for (i = 2; i <= q[t]; i++)
    ans += (p[t][i].y + p[t][i - 1].y) * (p[t][i].x - p[t][i - 1].x) / 2.0;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= k; i++) {
    q[i] = 2;
    p[i][2].x = 1;
  }
  while (n--) {
    scanf("%d", &Last);
    S = 0;
    for (i = 1; i <= k; i++) {
      scanf("%d", &A);
      add(i, Last, A);
      Last = A;
    }
    for (i = 1; i <= k; i++) S += WORK(i);
    printf("%.6f\n", S - ans);
    ans = S;
  }
  return 0;
}
