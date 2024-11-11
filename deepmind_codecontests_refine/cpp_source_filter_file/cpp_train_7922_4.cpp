#include <bits/stdc++.h>
struct Element {
  int p;
  long long x, y;
  Element() {}
  Element(int p, long long x, long long y) : p(p), x(x), y(y) {}
};
int cycle[10000005];
Element map[10000005];
int main() {
  long long n, m, s, t;
  scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
  m--, s--;
  long long upper = 1000000;
  if (upper > t) upper = t;
  long long p = s, left = t % n;
  for (int i = 1; i <= upper; i++) {
    if (p <= m)
      p += left;
    else
      p -= left;
    if (p >= n) p -= n;
    if (p < 0) p += n;
    left--;
    if (left < 0) left += n;
    map[i] = Element(i, p, left);
    cycle[i] = p;
  }
  if (t <= upper)
    printf("%d\n", cycle[t] + 1);
  else {
    std::sort(map + 1, map + 1 + upper, [&](Element& u, Element& v) {
      if (u.x != v.x)
        return u.x < v.x;
      else if (u.y != v.y)
        return u.y < v.y;
      else
        return u.p < v.p;
    });
    long long fst = -1, sec = -1;
    int p = 1;
    while (p <= upper) {
      int np = p;
      while (np + 1 <= upper &&
             (map[np + 1].x == map[p].x && map[np + 1].y == map[p].y))
        np++;
      if (np - p + 1 >= 2) {
        fst = map[p].p;
        sec = map[p + 1].p;
        break;
      }
      p = np + 1;
    }
    if (fst == -1 || sec == -1)
      printf("-1\n");
    else {
      long long left = (t - fst);
      long long size = sec - fst;
      left %= size;
      printf("%d\n", cycle[fst + left] + 1);
    }
  }
  return 0;
}
