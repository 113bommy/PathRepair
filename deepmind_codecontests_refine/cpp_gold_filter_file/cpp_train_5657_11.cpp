#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  int operator<(const node &o) const {
    if (y != o.y) return y < o.y;
    return x < o.x;
  }
} s[200000], t[200000];
set<pair<int, int> > u;
int n, m;
long long cross(long long x0, long long y0, long long x1, long long y1,
                long long x2, long long y2) {
  x1 -= x0;
  x2 -= x0;
  y1 -= y0;
  y2 -= y0;
  return x1 * y2 - x2 * y1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s[i].x, &s[i].y);
    u.insert(make_pair(s[i].x, s[i].y));
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &s[n + i].x, &s[n + i].y);
  m = n + m;
  swap(n, m);
  sort(s + 1, s + 1 + n);
  t[1] = s[1];
  int top = 1;
  for (int i = 2; i <= n; i++) {
    while (top > 1 && cross(t[top].x, t[top].y, t[top - 1].x, t[top - 1].y,
                            s[i].x, s[i].y) < 0)
      top--;
    t[++top] = s[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    while (top > 1 && cross(t[top].x, t[top].y, t[top - 1].x, t[top - 1].y,
                            s[i].x, s[i].y) < 0)
      top--;
    t[++top] = s[i];
  }
  if (top - 1 != m) {
    printf("NO\n");
    return 0;
  }
  for (int i = 1; i <= top - 1; i++)
    if (u.count(make_pair(t[i].x, t[i].y)) == 0) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
  return 0;
}
