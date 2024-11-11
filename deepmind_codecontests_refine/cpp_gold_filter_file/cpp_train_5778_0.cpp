#include <bits/stdc++.h>
template <typename A, typename B>
inline bool mins(A &x, B y) {
  return (x > y) ? (x = y, 1) : 0;
}
template <typename A, typename B>
inline bool maxs(A &x, B y) {
  return (x < y) ? (x = y, 1) : 0;
}
using namespace std;
int s, p1, p2, m1, m2, t;
int a, b, c, ans;
int main() {
  scanf("%d%d%d", &m1, &p1, &s);
  scanf("%d%d%d", &p2, &m2, &t);
  ans = 0;
  a = min(p1, p2);
  b = max(p1, p2);
  c = p1 + m1;
  ans += (2 * s + a) * a;
  ans += (2 * s + 2 * a) * (b - a);
  ans += (2 * t + c - b) * (c - b);
  printf("%d ", ans);
  return 0;
}
