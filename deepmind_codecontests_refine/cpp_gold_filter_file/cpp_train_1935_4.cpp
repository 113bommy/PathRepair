#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12, pi = acosl(-1);
const int maxn = 400005;
struct node {
  long double x, y;
  void init() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    x = a, y = b;
  }
  node(void) {}
  node(long double a, long double b) : x(a), y(b) {}
};
node operator+(const node &a, const node &b) {
  return node(a.x + b.x, a.y + b.y);
}
node operator-(const node &a, const node &b) {
  return node(a.x - b.x, a.y - b.y);
}
node operator*(const node &a, const long double &b) {
  return node(a.x * b, a.y * b);
}
long double operator*(const node &a, const node &b) {
  return a.x * b.x + a.y * b.y;
}
long double operator^(const node &a, const node &b) {
  return a.x * b.y - a.y * b.x;
}
struct line {
  node p, v;
  long double ang;
  line(void) {}
  line(node a, node b) { p = a, v = b - a; }
};
node cross(const line &a, const line &b) {
  return b.p + b.v * ((a.v ^ (a.p - b.p)) / (a.v ^ b.v));
}
line L[maxn];
long double ang[maxn];
node p[maxn];
int n, cnt, ord[maxn];
bool cmp(int a, int b) { return ang[a] < ang[b]; }
bool cmp1(const line &a, const line &b) {
  if (fabsl(a.ang - b.ang) < eps) return ((a.p - b.p) ^ b.v) < -eps;
  return a.ang < b.ang;
}
bool cmp2(const line &a, const line &b, const line &c) {
  node p = cross(a, b);
  return ((p - c.p) ^ c.v) > eps;
}
node o;
void planar() {
  for (int i = 1; i <= cnt; i++) {
    if (((o - L[i].p) ^ L[i].v) == 0) {
      printf("0\n");
      return;
    }
    if (((o - L[i].p) ^ L[i].v) > 0)
      L[i].p = L[i].p + L[i].v, L[i].v = L[i].v * -1;
  }
  int s = 1e6;
  L[++cnt] = line(node(-s, s), node(-s, -s)),
  L[++cnt] = line(node(-s, -s), node(s, -s));
  L[++cnt] = line(node(s, -s), node(s, s)),
  L[++cnt] = line(node(s, s), node(-s, s));
  for (int i = 1; i <= cnt; i++) {
    L[i].ang = atan2l(L[i].v.y, L[i].v.x);
    if (fabsl(L[i].ang - pi) < eps) L[i].ang = -pi;
  }
  sort(L + 1, L + cnt + 1, cmp1);
  int co = 1;
  for (int i = 2; i <= cnt; i++)
    if (fabsl(L[i].v ^ L[co].v) > eps) L[++co] = L[i];
  cnt = co;
  static line stk[maxn];
  int top = 0, bot = 1;
  for (int i = 1; i <= cnt; i++) {
    for (; bot < top && cmp2(stk[top - 1], stk[top], L[i]); top--)
      ;
    for (; bot < top && cmp2(stk[bot], stk[bot + 1], L[i]); bot++)
      ;
    stk[++top] = L[i];
  }
  for (; bot < top && cmp2(stk[top - 1], stk[top], stk[bot]); top--)
    ;
  for (; bot < top && cmp2(stk[bot], stk[bot + 1], stk[top]); bot++)
    ;
  if (top - bot < 2)
    printf("0\n");
  else {
    long double area = 0;
    static node po[maxn];
    int co = 0;
    for (int i = bot; i <= top; i++)
      po[co++] = cross(stk[i], stk[i == top ? bot : i + 1]);
    for (int i = 0; i < co; i++) area += (po[i] ^ po[(i + 1) % co]);
    printf("%.10f\n", double((fabsl(area) / 2)));
  }
}
void work() {
  scanf("%d", &n);
  o.init();
  n--;
  for (int i = 0; i < n; i++) p[i].init(), ord[i] = i;
  for (int i = 0; i < n; i++) {
    ang[i] = atan2l(p[i].y - o.y, p[i].x - o.x);
    if (fabsl(ang[i] - pi) < eps) ang[i] = -pi;
  }
  sort(ord, ord + n, cmp);
  for (int i = 1; i < n; i++)
    if (fabsl(ang[ord[i]] - ang[ord[i - 1]]) < eps) {
      printf("0\n");
      return;
    }
  cnt = 0;
  for (int i = 0; i < n; i++) L[++cnt] = line(p[ord[i]], p[ord[(i + 1) % n]]);
  for (int i = 0, j = 1; i < n; i++) {
    for (; j != i && ((p[ord[j]] - p[ord[i]]) ^ (o - p[ord[i]])) > -eps;
         j = (j + 1) % n)
      ;
    if ((j + n - 1) % n != i)
      L[++cnt] = line(p[ord[i]], p[ord[(j + n - 1) % n]]);
  }
  planar();
}
int main() {
  int t;
  scanf("%d", &t);
  for (; t; t--) work();
  return 0;
}
