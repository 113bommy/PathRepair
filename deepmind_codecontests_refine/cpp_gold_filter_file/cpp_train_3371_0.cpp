#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
const double eps = 1e-5;
struct _tree {
  int l, r, s, fa;
  double len, sl, a, b, adda, addb, addc;
  _tree(double L, double A, double B) : len(L), sl(L), a(A), b(B) {
    adda = addb = addc = l = r = fa = 0;
    s = 1;
  }
  _tree() {}
} t[N + N];
int n, q, a, b, root, tot;
int p[N];
double ans[N];
double Calc(double x, double a, double b) { return x * a + b; }
void Update(int x) {
  t[x].s = t[t[x].l].s + t[t[x].r].s + 1;
  t[x].sl = t[t[x].l].sl + t[t[x].r].sl + t[x].len;
}
void Pushc(int x, double c) {
  t[x].b -= t[x].a * c;
  t[x].addb -= t[x].adda * c;
  t[x].addc += c;
}
void Pushab(int x, double a, double b) {
  t[x].a += a;
  t[x].b += b;
  t[x].adda += a;
  t[x].addb += b;
}
void Push(int x) {
  if (((t[x].addc) > 0 ? (t[x].addc) : -(t[x].addc)) > eps) {
    Pushc(t[x].l, t[x].addc);
    Pushc(t[x].r, t[x].addc);
    t[x].addc = 0;
  }
  if (((t[x].adda) > 0 ? (t[x].adda) : -(t[x].adda)) > eps) {
    Pushab(t[x].l, t[x].adda, t[x].addb);
    Pushab(t[x].r, t[x].adda, t[x].addb);
    t[x].adda = t[x].addb = 0;
  }
}
int Find(int &x, double len) {
  double l1 = Calc(len + t[t[x].l].sl, t[x].a, t[x].b),
         l2 = Calc(len + t[t[x].l].sl + t[x].len, t[x].a, t[x].b);
  Push(x);
  if (l2 < eps)
    if (t[x].r) {
      return Find(t[x].r, len + t[t[x].l].sl + t[x].len);
    } else
      return x;
  if (l1 > -eps)
    if (t[x].l)
      return Find(t[x].l, len);
    else
      return x;
  return x;
}
void Ro(int x) {
  int y = t[x].fa, z = t[y].fa;
  if (z)
    if (t[z].l == y)
      t[z].l = x;
    else
      t[z].r = x;
  t[x].fa = z;
  t[y].fa = x;
  if (t[y].l == x) {
    t[y].l = t[x].r;
    t[t[x].r].fa = y;
    t[x].r = y;
  } else {
    t[y].r = t[x].l;
    t[t[x].l].fa = y;
    t[x].l = y;
  }
  t[x].sl = t[y].sl;
  t[x].s = t[y].s;
  Update(y);
}
void Splay(int x, int goal) {
  while (t[x].fa != goal) {
    int y = t[x].fa;
    if (t[y].fa == goal)
      Ro(x);
    else {
      int z = t[y].fa;
      if (t[z].l == y ^ t[y].l == x)
        Ro(x), Ro(x);
      else
        Ro(y), Ro(x);
    }
  }
  if (!goal) root = x;
}
int Findl(int x) {
  while (Push(x), t[x].l) x = t[x].l;
  return x;
}
int main() {
  scanf("%d%d%d%d", &n, &q, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  t[root = tot = 1] = _tree(q - 1, 2, -2 * p[1] + 2);
  for (int i = 2; i <= n + 1; i++) {
    int tlen = 1 + a * (i - 2), x = Find(root, 0), y;
    Splay(x, 0);
    double l1 = Calc(t[t[x].l].sl, t[x].a, t[x].b),
           l2 = Calc(t[t[x].l].sl + t[x].len, t[x].a, t[x].b);
    if (l2 < eps) {
      ans[i - 1] = t[t[x].l].sl + t[x].len + tlen;
      if (a == b)
        y = 0;
      else
        t[y = ++tot] = _tree(b - a, 0, 0);
    } else if (l1 > -eps) {
      ans[i - 1] = t[t[x].l].sl + tlen;
      if (a == b)
        y = 0;
      else {
        t[y = ++tot] = _tree(t[x].len, t[x].a, t[x].b);
        t[x].len = b - a;
        t[x].a = t[x].b = 0;
      }
    } else {
      ans[i - 1] = -t[x].b / t[x].a;
      double pos = ans[i - 1] - t[t[x].l].sl;
      ans[i - 1] += tlen;
      if (a == b)
        t[y = ++tot] = (_tree){t[x].len - pos, t[x].a, t[x].b};
      else {
        t[y = ++tot] = _tree(b - a, 0, 0);
        t[t[y].r = ++tot] = (_tree){t[x].len - pos, t[x].a, t[x].b};
        t[tot].fa = y;
        Update(y);
      }
      t[x].len = pos;
    }
    if (t[x].r) {
      int temp = Findl(t[x].r);
      Splay(temp, x);
      t[t[y].fa = temp].l = y;
      Update(temp);
    } else
      t[t[y].fa = x].r = y;
    Update(x);
    if (a != b) Pushc(t[x].r, b - a);
    Pushab(x, 2, -2 * p[i] + (tlen + a) * 2);
  }
  for (int i = 1; i <= n; i++)
    if (ans[i] > q) ans[i] = q;
  for (int i = n; i >= 2; i--)
    if (ans[i] - ans[i - 1] > b)
      ans[i - 1] = ans[i] - b;
    else if (ans[i] - ans[i - 1] < a)
      ans[i - 1] = ans[i] - a;
  double ret = 0;
  for (int i = 1; i <= n; i++) {
    if (i != 1) putchar(' ');
    printf("%.7lf", ans[i]);
    ret += ((ans[i] - p[i]) * (ans[i] - p[i]));
  }
  puts("");
  printf("%.7lf\n", ret);
  return 0;
}
