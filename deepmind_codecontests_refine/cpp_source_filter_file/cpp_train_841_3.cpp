#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  Point() {}
  Point(int a, int b) : x(a), y(b) {}
  bool operator<(const Point& b) const {
    return (x != b.x) ? x < b.x : y < b.y;
  }
  Point operator-(Point b) { return Point(x - b.x, y - b.y); }
};
long long cross(Point a, Point b) {
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
Point p[200005];
int st[200005], top;
void insert(int x, bool on) {
  if (!on) {
    while (top > 1 &&
           cross(p[x] - p[st[top]], p[st[top]] - p[st[top - 1]]) <= 0)
      top--;
    st[++top] = x;
  } else {
    while (top > 1 &&
           cross(p[x] - p[st[top]], p[st[top]] - p[st[top - 1]]) >= 0)
      top--;
    st[++top] = x;
  }
}
int id[200005];
int main() {
  int n;
  scanf("%d", &n);
  bool ok = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = Point(x, y);
  }
  sort(p + 1, p + n + 1);
  top = 1;
  for (int i = 1; i <= n; i++) insert(i, 0);
  int tot = top - 1;
  for (int i = 1; i <= tot; i++) id[i] = st[i + 1];
  int cnt = 0;
  for (int i = 1; i <= tot; i++)
    if ((p[id[i]].x & 1) || (p[id[i]].y & 1)) cnt++;
  if (cnt) {
    puts("Ani");
    return 0;
  }
  id[tot + 1] = n + 1;
  for (int i = 1; i <= tot; i++) {
    top = 1;
    if (i > 1) insert(id[i - 1], 0);
    for (int j = id[i - 1] + 1; j < id[i + 1]; j++)
      if (j != id[i]) insert(j, 0);
    if (i < tot) insert(id[i + 1], 0);
    for (int j = 2; j <= tot; j++)
      if ((p[st[j]].x & 1) || (p[st[j]].y & 1)) {
        puts("Ani");
        return 0;
      }
  }
  top = 1;
  for (int i = 1; i <= n; i++) insert(i, 1);
  tot = top - 1;
  for (int i = 1; i <= tot; i++) id[i] = st[i + 1];
  cnt = 0;
  for (int i = 1; i <= tot; i++)
    if ((p[id[i]].x & 1) || (p[id[i]].y & 1)) cnt++;
  if (cnt) {
    puts("Ani");
    return 0;
  }
  id[tot + 1] = n + 1;
  for (int i = 1; i <= tot; i++) {
    top = 1;
    if (i > 1) insert(id[i - 1], 1);
    for (int j = id[i - 1] + 1; j < id[i + 1]; j++)
      if (j != id[i]) insert(j, 1);
    if (i < tot) insert(id[i + 1], 1);
    for (int j = 2; j <= top; j++) {
      if ((p[st[j]].x & 1) || (p[st[j]].y & 1)) {
        puts("Ani");
        return 0;
      }
    }
  }
  puts("Borna");
  return 0;
}
