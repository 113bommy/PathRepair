#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int x[N], y[N], n;
pair<int, int> p[N], ch[N];
set<pair<int, int> > s;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
bool cross(pair<int, int> p1, pair<int, int> p2, pair<int, int> pi) {
  pair<double, double> tmp1 = {
      10000.0 * (p2.first - p1.first) / (p1.first * p2.first),
      10000.0 * (p2.second - p1.second) / (p1.second * p2.second)};
  pair<double, double> tmp2 = {
      10000.0 * (p2.first - pi.first) / (pi.first * p2.first),
      10000.0 * (p2.second - pi.second) / (pi.second * p2.second)};
  return (tmp1.first * tmp2.second - tmp1.second * tmp2.first) < 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
    p[i] = {x[i], y[i]};
  }
  sort(p, p + n, cmp);
  int tot = 1, top = 0;
  for (int i = 1; i < n; ++i)
    if (p[i].second > p[tot - 1].second) p[tot++] = p[i];
  for (int i = 0; i < tot; i++) {
    while (top > 1 && cross(ch[top - 1], ch[top - 2], p[i])) top--;
    ch[top++] = p[i];
  }
  for (int i = 0; i < top; i++) s.insert(ch[i]);
  for (int i = 0; i < n; i++)
    if (s.find({x[i], y[i]}) != s.end()) printf("%d ", i + 1);
}
