#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
struct point {
  long long x, y;
} p[N];
bool cmp(point a, point b) {
  if (a.x < b.x) return true;
  if (a.x == b.x && a.y < b.y) return true;
  return false;
}
int st[N], top = 0;
long long det(point a, point b, point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x * a.x) * (b.y - a.y);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    p[i].y -= p[i].x * p[i].x;
  }
  sort(p + 1, p + n + 1, cmp);
  st[++top] = n;
  for (int i = n - 1; i >= 1; i--) {
    while (top > 1 && det(p[st[top - 1]], p[st[top]], p[i]) <= 0) top--;
    st[++top] = i;
  }
  int ans = 1;
  for (int i = 2; i <= top; i++) {
    if (p[st[i]].x != p[st[i - 1]].x) ++ans;
  }
  printf("%d\n", ans - 1);
  return 0;
}
