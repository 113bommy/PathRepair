#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
struct P {
  double x, y;
  P() {}
  P(int x, int y) : x(double(x)), y(double(y)) {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  double operator^(const P &a) const { return x * a.x + y * a.y; }
  void in() { scanf("%lf%lf", &x, &y); }
  void out() { printf("REQUIRED %.7f %.7f\n", x, y); }
  double dist(P a, P b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
  double sqdist(P a, P b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }
};
struct dd {
  int v;
  int id, ty, c;
  dd() {}
  dd(int v, int id, int ty, int c) : v(v), id(id), ty(ty), c(c) {}
} a[200001];
bool operator<(dd u, dd w) {
  if (u.v == w.v) return u.ty > w.ty;
  return u.v > w.v;
}
priority_queue<dd> Q;
int cnt;
int n, m, tt, a2, b, c;
int arr = 0;
int ans[200001];
multiset<int> S;
set<int> S2;
int main() {
  scanf("%d%d%d", &n, &m, &tt);
  for (int i = (1); i <= (n); i++) {
    scanf("%d:%d:%d", &a2, &b, &c);
    a[i].v = c + b * 60 + a2 * 60 * 60;
    a[i].ty = 0;
    a[i].id = i;
  }
  for (int i = (1); i <= (n); i++) {
    Q.push(a[i]);
  }
  int s = 0;
  while (Q.size()) {
    dd t = Q.top();
    Q.pop();
    if (t.ty) {
      S.erase(S.find(t.c));
      if (S.find(t.c) == S.end()) S2.erase(S2.find(t.c));
    } else {
      if (S2.size() == m) {
        ans[t.id] = *S.begin();
        Q.push(dd(t.v + tt - 1, t.id, 1, ans[t.id]));
      } else {
        cnt++;
        ans[t.id] = cnt;
        Q.push(dd(t.v + tt - 1, t.id, 1, cnt));
      }
      S.insert(ans[t.id]);
      S2.insert(ans[t.id]);
      if (S2.size() == m) arr = 1;
    }
  }
  int res = cnt;
  if (arr == 0) res = -1;
  if (res == -1) {
    printf("No solution\n");
    return 0;
  }
  printf("%d\n", res);
  if (res > 0)
    for (int i = (1); i <= (n); i++) printf("%d\n", ans[i]);
  return 0;
}
