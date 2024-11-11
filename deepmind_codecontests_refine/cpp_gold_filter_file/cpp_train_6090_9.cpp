#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, V = 1e5;
inline int read() {
  register int x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return f ? -x : x;
}
int n, tot, top;
struct point {
  int x, y;
} p[N * 10], s[N * 10];
point operator-(const point &A, const point &B) {
  return (point){A.x - B.x, A.y - B.y};
}
inline void add(int x, int y) {
  p[++tot].x = x;
  p[tot].y = y;
}
inline double accross(point A, point B) {
  return (double)A.x * B.y - (double)A.y * B.x;
}
inline double dis(point A, point B) {
  return (double)(A.x - B.x) * (A.x - B.x) + (double)(A.y - B.y) * (A.y - B.y);
}
inline bool cmp1(const point &A, const point &B) {
  return A.x == B.x ? A.y < B.y : A.x < B.x;
}
inline bool cmp2(const point &A, const point &B) {
  return A.x == B.x && A.y == B.y;
}
inline bool cmp3(const point &A, const point &B) {
  double res = accross(A - p[1], B - p[1]);
  if (res > 0)
    return true;
  else if (res == 0 && dis(A, p[1]) < dis(B, p[1]))
    return true;
  return false;
}
void Get_TB() {
  for (int i = 2; i <= tot; ++i)
    if (p[1].y > p[i].y || (p[1].y == p[i].y && p[1].x > p[i].x))
      swap(p[i], p[1]);
  sort(p + 2, p + tot + 1, cmp3);
  s[1] = p[1];
  s[2] = p[2];
  top = 2;
  for (int i = 3; i <= tot; ++i) {
    while (top > 1 && accross(p[i] - s[top - 1], s[top] - s[top - 1]) >= 0)
      top--;
    s[++top] = p[i];
  }
  return;
}
inline double len(point &A) {
  return sqrt((double)A.x * A.x + (double)A.y * A.y);
}
double calc(point A, point B, point C) {
  point x = A - B, y = C - B, z = C - A;
  double res = len(x) * len(y) * len(z) / (accross(y, x) * 2);
  return res;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read(), y = read(), v = read();
    if (x < v)
      add(0, min(V, y + v - x)), add(0, max(0, y - v + x));
    else
      add(x - v, y);
    if (y < v)
      add(max(0, x - v + y), 0), add(min(V, x + v - y), 0);
    else
      add(x, y - v);
    if (x + v > V)
      add(V, min(V, y + x + v - V)), add(V, max(0, y - x - v + V));
    else
      add(x + v, y);
    if (y + v > V)
      add(min(V, x + y + v - V), V), add(max(0, x - y - v + V), V);
    else
      add(x, y + v);
  }
  sort(p + 1, p + 1 + tot, cmp1);
  tot = unique(p + 1, p + 1 + tot, cmp2) - p - 1;
  Get_TB();
  int id = 0;
  double ans = -1e9, tmp;
  s[0] = s[top];
  s[top + 1] = s[1];
  for (int i = 1; i <= top; ++i) {
    point a = s[i - 1], b = s[i], c = s[i + 1];
    if ((tmp = calc(a, b, c)) > ans) ans = tmp, id = i;
  }
  cout << s[id - 1].x << ' ' << s[id - 1].y << '\n';
  cout << s[id].x << ' ' << s[id].y << '\n';
  cout << s[id + 1].x << ' ' << s[id + 1].y << '\n';
  return 0;
}
