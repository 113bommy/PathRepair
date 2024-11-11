#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} A[40005], B[40005], CA[40005], CB[40005], S[40005];
int tot;
node operator+(node a, node b) { return node{a.x + b.x, a.y + b.y}; }
node operator-(node a, node b) { return node{a.x - b.x, a.y - b.y}; }
int operator*(node a, node b) { return a.x * b.x + a.y * b.y; }
int operator/(node a, node b) { return a.x * b.y - a.y * b.x; }
bool operator<(node a, node b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}
void convex_hull(node p[], node c[], int n, int &tp) {
  sort(p + 1, p + n + 1);
  tp = 0;
  for (int i = 1; i <= n; i++) {
    while (tp > 1 && (c[tp] - p[i]) * (c[tp - 1] - p[i]) >= 0) tp--;
    c[++tp] = p[i];
  }
  int k = tp--;
  for (int i = n; i >= 1; i--) {
    while (tp > k && (c[tp] - p[i]) * (c[tp - 1] - p[i]) >= 0) tp--;
    c[++tp] = p[i];
  }
  tp--;
}
void getedge(node a[], int l, int r) {
  S[++tot] = node{l, r};
  if (l + 1 == r) return;
  int i, j;
  double Max = -1e100;
  int mid = 0;
  for (int k = l + 1; k < r; ++k) {
    double d = (double)((a[k] - a[l]) * (a[k] - a[r])) /
               ((a[l] - a[k]) / (a[l] - a[r]));
    if (d > Max) mid = k, Max = d;
  }
  getedge(a, l, mid);
  getedge(a, mid, r);
}
bool solve(node a[], node b[], int na, int nb) {
  tot = 0;
  getedge(a, 1, na);
  for (int i = 1, j; i <= tot; i++) {
    node pa = a[S[i].x], pb = a[S[i].y];
    double lp = -1e100, rp = 1e100;
    for (j = 1; j <= na; j++) {
      if (j == S[i].x) continue;
      if (j == S[i].y) continue;
      int ta = (a[j] - pa) * (a[j] - pb);
      int tb = (pa - a[j]) / (pa - pb);
      double r = (double)ta / tb;
      if (tb < 0)
        rp = min(rp, r);
      else if (tb > 0)
        lp = max(lp, r);
    }
    for (j = 1; j <= nb; j++) {
      int ta = (b[j] - pa) * (b[j] - pb);
      int tb = (pa - b[j]) / (pa - pb);
      if (tb == 0) {
        if (ta <= 0)
          break;
        else
          continue;
      }
      double r = (double)ta / tb;
      if (tb > 0)
        rp = min(rp, r);
      else if (tb < 0)
        lp = max(lp, r);
      if (lp >= rp) break;
    }
    if (j > nb && lp < rp) return 1;
  }
  return 0;
}
int main() {
  int n, m, cn, cm;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &A[i].x, &A[i].y);
  for (int i = 1; i <= m; i++) scanf("%d%d", &B[i].x, &B[i].y);
  if (n == 1 || m == 1) return puts("YES"), 0;
  convex_hull(A, CA, n, cn);
  convex_hull(B, CB, m, cm);
  if (solve(CA, B, cn, m) || solve(CB, A, cm, n))
    puts("YES");
  else
    puts("NO");
}
