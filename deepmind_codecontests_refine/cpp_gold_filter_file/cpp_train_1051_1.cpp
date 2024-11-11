#include <bits/stdc++.h>
using namespace std;
int c[5010], n, x[5010], y[5010], top, d[5010], sta[5010], t;
struct DOT {
  int x, y;
  DOT(int _x = 0, int _y = 0) { x = _x, y = _y; }
} a[5010];
DOT operator-(DOT a, DOT b) { return DOT(a.x - b.x, a.y - b.y); }
int ctime(DOT a, DOT b) { return a.x * b.y - a.y * b.x; }
bool cmp(int x, int y) {
  return a[x].x < a[y].x || (a[x].x == a[y].x && a[x].y < a[y].y);
}
void convexhull() {
  for (int i = 1, _E_ = n; i <= _E_; ++i) d[i] = i;
  sort(d + 1, d + n + 1, cmp);
  for (int i = 1, _E_ = n; i <= _E_; ++i) {
    while (top > 1 &&
           ctime(a[sta[top]] - a[sta[top - 1]], a[d[i]] - a[sta[top]]) < 0)
      --top;
    sta[++top] = d[i];
  }
  int k = top;
  for (int i = n - 1, _E_ = 1; i >= _E_; --i) {
    while (top > k &&
           ctime(a[sta[top]] - a[sta[top - 1]], a[d[i]] - a[sta[top]]) < 0)
      --top;
    sta[++top] = d[i];
  }
  --top;
}
void solve(int d, int e, int f) {
  for (int i = 1, _E_ = n; i <= _E_; ++i)
    if (c[i] != c[e])
      if (ctime(a[i] - a[d], a[i] - a[e]) > 0)
        if (ctime(a[i] - a[e], a[i] - a[f]) > 0)
          if (ctime(a[i] - a[f], a[i] - a[d]) > 0) {
            ++t;
            x[t] = i;
            y[t] = f;
            solve(d, e, i);
            solve(f, i, e);
            solve(i, f, d);
            return;
          }
  for (int i = 1, _E_ = n; i <= _E_; ++i)
    if (ctime(a[i] - a[d], a[i] - a[e]) > 0)
      if (ctime(a[i] - a[e], a[i] - a[f]) > 0)
        if (ctime(a[i] - a[f], a[i] - a[d]) > 0) {
          ++t;
          x[t] = i;
          y[t] = d;
        }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, _E_ = n; i <= _E_; ++i)
    scanf("%d %d %d", &a[i].x, &a[i].y, c + i);
  convexhull();
  int cnt = 0;
  for (int i = 1, _E_ = top; i <= _E_; ++i) d[i] = sta[i];
  for (int i = 2, _E_ = top; i <= _E_; ++i)
    if (c[d[i]] ^ c[d[i - 1]]) ++cnt;
  if (cnt == 0) {
    for (int i = 2, _E_ = top; i <= _E_; ++i) ++t, x[t] = d[i - 1], y[t] = d[i];
    for (int i = 1, _E_ = n; i <= _E_; ++i)
      if (c[i] ^ c[d[1]]) {
        for (int j = 2, _E_ = top; j <= _E_; ++j) solve(d[j - 1], d[j], i);
        solve(d[top], d[1], i);
        printf("%d\n", t);
        for (int j = 1, _E_ = t; j <= _E_; ++j)
          printf("%d %d\n", x[j] - 1, y[j] - 1);
        return 0;
      }
    printf("%d\n", n - 1);
    for (int j = 1, _E_ = n - 1; j <= _E_; ++j) printf("0 %d\n", j);
  } else if (cnt > 2)
    printf("Impossible\n");
  else {
    int k = 1, j;
    while (c[d[k]] == c[d[k + 1]]) {
      d[k + top] = d[k];
      ++k;
    }
    d[k + top] = d[k];
    for (int i = 1, _E_ = top; i <= _E_; ++i) d[i] = d[i + k];
    for (int i = 2, _E_ = top; i <= _E_; ++i)
      if (c[d[i]] ^ c[d[i - 1]]) {
        j = i;
        break;
      }
    for (int i = 2, _E_ = j - 1; i <= _E_; ++i)
      ++t, x[t] = d[i - 1], y[t] = d[i];
    for (int i = j + 1, _E_ = top; i <= _E_; ++i)
      ++t, x[t] = d[i - 1], y[t] = d[i];
    for (int i = 2, _E_ = j - 1; i <= _E_; ++i) solve(d[i - 1], d[i], d[j]);
    for (int i = j, _E_ = top - 1; i <= _E_; ++i) solve(d[i], d[i + 1], d[1]);
    printf("%d\n", t);
    for (int i = 1, _E_ = t; i <= _E_; ++i)
      printf("%d %d\n", x[i] - 1, y[i] - 1);
  }
  return 0;
}
