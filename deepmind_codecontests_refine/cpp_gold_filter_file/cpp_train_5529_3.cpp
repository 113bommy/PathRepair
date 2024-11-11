#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
struct P {
  int x, y, c, id;
  P() {}
  P(int _x, int _y) {
    x = _x;
    y = _y;
  }
  P operator+(const P &a) const { return P(x + a.x, y + a.y); }
  P operator-(const P &a) const { return P(x - a.x, y - a.y); }
  long long operator*(const P &a) const {
    return 1ll * x * a.y - 1ll * y * a.x;
  }
  bool operator<(const P &a) const { return x == a.x ? y < a.y : x < a.x; }
  bool operator==(const P &a) const { return x == a.x && y == a.y; }
} a[N], b[N];
pair<int, int> ans[N];
int top;
bool cmp(P x, P y) { return x * y > 0; }
void Convex_Hull() {
  sort(a + 1, a + n + 1);
  P bas = a[1];
  for (int i = (int)(1); i <= (int)(n); i++) {
    a[i].x -= bas.x;
    a[i].y -= bas.y;
  }
  sort(a + 2, a + n + 1, cmp);
  int top = 1;
  b[1] = a[1];
  for (int i = (int)(2); i <= (int)(n); i++) {
    for (; top >= 2 && (b[top] - b[top - 1]) * (a[i] - b[top]) <= 0; --top)
      ;
    b[++top] = a[i];
  }
  m = top;
}
bool In(P x, P y, P z, P p) {
  return ((y - x) * (p - x) > 0 && (z - y) * (p - y) > 0 &&
          (x - z) * (p - z) > 0) ||
         ((y - x) * (p - x) < 0 && (z - y) * (p - y) < 0 &&
          (x - z) * (p - z) < 0);
}
void solve(P a, P b, P c, vector<P> v) {
  assert(a.c == b.c);
  assert(a.c != c.c);
  bool flag = 0;
  for (auto i : v)
    if (i.c != a.c) flag = 1;
  if (!flag) {
    for (auto i : v) ans[++top] = pair<int, int>(i.id, a.id);
    return;
  }
  P mid;
  for (auto i : v)
    if (i.c != a.c) mid = i;
  ans[++top] = pair<int, int>(c.id, mid.id);
  vector<P> d1, d2, d3;
  for (auto i : v) {
    if (In(a, b, mid, i)) d1.push_back(i);
    if (In(a, c, mid, i)) d2.push_back(i);
    if (In(b, c, mid, i)) d3.push_back(i);
  }
  solve(a, b, mid, d1);
  solve(c, mid, a, d2);
  solve(c, mid, b, d3);
}
void TRYITRY1() {
  int p1 = 0, p2 = 0;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (b[i].c == b[i % m + 1].c)
      ans[++top] = pair<int, int>(b[i].id, b[i % m + 1].id);
    else
      p1 ? p2 = i : p1 = i;
  for (int x = p1 % m + 1; x != p2; x = x % m + 1) {
    vector<P> tmp;
    tmp.resize(0);
    for (int j = (int)(1); j <= (int)(n); j++)
      if (In(b[x], b[x % m + 1], b[p2 % m + 1], a[j])) tmp.push_back(a[j]);
    solve(b[x], b[x % m + 1], b[p2 % m + 1], tmp);
  }
  for (int x = p2 % m + 1; x != p1; x = x % m + 1) {
    vector<P> tmp;
    tmp.resize(0);
    for (int j = (int)(1); j <= (int)(n); j++)
      if (In(b[x], b[x % m + 1], b[p1 % m + 1], a[j])) tmp.push_back(a[j]);
    solve(b[x], b[x % m + 1], b[p1 % m + 1], tmp);
  }
}
void TRYITRY2() {
  P mid;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (a[i].c != b[1].c) mid = a[i];
  for (int i = (int)(1); i <= (int)(m - 1); i++)
    ans[++top] = pair<int, int>(b[i].id, b[i + 1].id);
  for (int i = (int)(1); i <= (int)(m); i++) {
    vector<P> tmp;
    tmp.resize(0);
    for (int j = (int)(1); j <= (int)(n); j++)
      if (In(b[i], b[i % m + 1], mid, a[j])) tmp.push_back(a[j]);
    solve(b[i], b[i % m + 1], mid, tmp);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
    a[i].id = i - 1;
  }
  bool flag = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (a[i].c != a[1].c) flag = 1;
  if (!flag) {
    printf("%d\n", n - 1);
    for (int i = (int)(1); i <= (int)(n - 1); i++) printf("0 %d\n", i);
    return 0;
  }
  if (n == 2) {
    puts("0");
    return 0;
  }
  Convex_Hull();
  int cnt = 0;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (b[i].c != b[i % m + 1].c) ++cnt;
  if (cnt >= 4) return puts("Impossible"), 0;
  if (cnt == 2)
    TRYITRY1();
  else
    TRYITRY2();
  printf("%d\n", top);
  for (int i = (int)(1); i <= (int)(top); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
