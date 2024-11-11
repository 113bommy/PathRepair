#include <bits/stdc++.h>
using namespace std;
struct pt {
  long long x, y;
};
struct seg {
  pt s, f;
};
seg a[3];
inline bool eq(pt a, pt b) { return a.x == b.x && a.y == b.y; }
long long cp(seg a1, seg b1) {
  pt a = {a1.f.x - a1.s.x, a1.f.y - a1.s.y};
  pt b = {b1.f.x - b1.s.x, b1.f.y - b1.s.y};
  return (long long)a.x * b.x + (long long)a.y * b.y;
}
long long dp(seg a1, seg b1) {
  pt a = {a1.f.x - a1.s.x, a1.f.y - a1.s.y};
  pt b = {b1.f.x - b1.s.x, b1.f.y - b1.s.y};
  return (long long)a.x * b.y - (long long)a.y * b.x;
}
double len(pt a, pt b) {
  return sqrt((double)(a.x - b.x) * (a.x - b.x) +
              (double)(a.y - b.y) * (a.y - b.y));
}
bool in(pt a1, seg b1) {
  seg a, b;
  b.s = a.s = a1;
  a.f = b1.s, b.f = b1.f;
  if (dp(a, b) == 0 && cp(a, b) < 0)
    return 1;
  else
    return 0;
}
bool check(seg a, seg b, seg c) {
  if (eq(a.s, b.f)) swap(b.f, b.s);
  if (eq(a.f, b.s)) swap(a.f, a.s);
  if (eq(a.f, b.f)) swap(a.f, a.s), swap(b.f, b.s);
  if (!eq(a.s, b.s)) return 0;
  if (cp(a, b) < 0 || dp(a, b) == 0) return 0;
  if (in(c.f, a) && in(c.s, b)) swap(c.f, c.s);
  if (!in(c.s, a) || !in(c.f, b)) return 0;
  if ((double)abs(len(c.s, a.s)) / abs(len(a.s, a.f)) < 0.2 - 1E-10) return 0;
  if ((double)abs(len(c.s, a.f)) / abs(len(a.s, a.f)) < 0.2 - 1E-10) return 0;
  if ((double)abs(len(c.f, b.s)) / abs(len(b.s, b.f)) < 0.2 - 1E-10) return 0;
  if ((double)abs(len(c.f, b.f)) / abs(len(b.s, b.f)) < 0.2 - 1E-10) return 0;
  return 1;
}
int main(void) {
  int t;
  cin >> t;
  for (int curt = 0; curt < t; curt++) {
    bool ans = 0;
    for (int i = 0; i < 3; i++)
      scanf("%I64d%I64d%I64d%I64d", &a[i].s.x, &a[i].s.y, &a[i].f.x, &a[i].f.y);
    for (int i = 0; i < 3; i++)
      for (int j = i + 1; j < 3; j++)
        if (3 - i - j != i && 3 - i - j != j)
          if (check(a[i], a[j], a[3 - i - j])) ans = 1;
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
