#include <bits/stdc++.h>
using namespace std;
int n;
struct Djs {
  int par[1039];
  int high[1039];
  int kuai;
  void renew() {
    kuai = n;
    for (int i = (1); i < 1039; i++) {
      par[i] = i;
      high[i] = 0;
    }
  }
  int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    kuai--;
    if (high[x] < high[y])
      par[x] = y;
    else {
      par[y] = x;
      if (high[x] == high[y]) high[x]++;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
} djs;
struct point {
  long long x;
  long long y;
} p[1039];
struct seg {
  long long a;
  long long b;
} s[1039];
bool judge(long long x) {
  djs.renew();
  for (int i = (1); i < n + 1; i++)
    for (int j = (i + 1); j < n + 1; j++)
      if ((p[i].x == p[j].x || p[i].y == p[j].y) &&
          abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= x)
        djs.unite(i, j);
  int s_index = 0;
  for (int i = (1); i < n + 1; i++) {
    long long right = 0x3f3f3f3f3f3f3f3f, left = 0x3f3f3f3f3f3f3f3f,
              up = 0x3f3f3f3f3f3f3f3f, down = 0x3f3f3f3f3f3f3f3f;
    int rightp, leftp, upp, downp;
    for (int j = (i + 1); j < n + 1; j++) {
      if (djs.same(i, j)) continue;
      if (p[i].x == p[j].x) {
        if (p[j].y < p[i].y && abs(p[j].y - p[i].y) < left) {
          left = abs(p[j].y - p[i].y);
          leftp = j;
        } else if (p[j].y > p[i].y && abs(p[j].y - p[i].y) < right) {
          right = abs(p[j].y - p[i].y);
          rightp = j;
        }
      } else if (p[i].y == p[j].y) {
        if (p[j].x < p[i].x && abs(p[j].x - p[i].x) < down) {
          down = abs(p[j].x - p[i].x);
          downp = j;
        } else if (p[j].x > p[i].x && abs(p[j].x - p[i].x) < up) {
          up = abs(p[j].x - p[i].x);
          upp = j;
        }
      }
    }
    if (right <= 2 * x) s[++s_index] = {i, rightp};
    if (left <= 2 * x) s[++s_index] = {i, leftp};
    if (up <= 2 * x) s[++s_index] = {i, upp};
    if (down <= 2 * x) s[++s_index] = {i, downp};
  }
  int m = s_index;
  if (djs.kuai == 1)
    return true;
  else if (djs.kuai > 4)
    return false;
  else if (djs.kuai == 2) {
    for (int i = (1); i < n + 1; i++)
      for (int j = (i + 1); j < n + 1; j++) {
        if (djs.same(i, j)) continue;
        if (p[i].x == p[j].x && abs(p[i].y - p[j].y) <= 2 * x)
          return true;
        else if (p[i].y == p[j].y && abs(p[i].x - p[j].x) <= 2 * x)
          return true;
        else if (abs(p[i].x - p[j].x) <= x && abs(p[i].y - p[j].y) <= x)
          return true;
      }
    return false;
  } else if (djs.kuai == 3) {
    for (int i = (1); i < m + 1; i++) {
      for (int j = (1); j < n + 1; j++) {
        if (djs.same(s[i].a, j) || djs.same(s[i].b, j)) continue;
        if (p[s[i].a].x == p[s[i].b].x) {
          int jiaox = p[s[i].a].x, jiaoy = p[j].y;
          if (abs(jiaoy - p[s[i].a].y) <= x && abs(jiaoy - p[s[i].b].y) <= x &&
              abs(jiaox - p[j].x) <= x)
            return true;
        } else {
          int jiaoy = p[s[i].a].y, jiaox = p[j].x;
          if (abs(jiaox - p[s[i].a].x) <= x && abs(jiaox - p[s[i].b].x) <= x &&
              abs(jiaoy - p[j].y) <= x)
            return true;
        }
      }
    }
    return false;
  } else {
    for (int i = (1); i < m + 1; i++)
      for (int j = (i + 1); j < m + 1; j++) {
        if (djs.same(s[i].a, s[j].a) || djs.same(s[i].b, s[j].b) ||
            djs.same(s[i].a, s[j].b) || djs.same(s[i].b, s[j].a))
          continue;
        if (p[s[i].a].x == p[s[i].b].x && p[s[j].a].x == p[s[j].b].x ||
            p[s[i].a].y == p[s[i].b].y && p[s[j].a].y == p[s[j].b].y)
          continue;
        if (p[s[i].a].x == p[s[i].b].x) {
          int jiaox = p[s[i].a].x, jiaoy = p[s[j].a].y;
          if (abs(jiaox - p[s[j].a].x) <= x && abs(jiaox - p[s[j].b].x) <= x &&
              abs(jiaoy - p[s[i].a].y) <= x && abs(jiaoy - p[s[i].b].y) <= x)
            return true;
        } else {
          int jiaox = p[s[j].a].x, jiaoy = p[s[i].a].y;
          if (abs(jiaox - p[s[i].a].x) <= x && abs(jiaox - p[s[i].b].x) <= x &&
              abs(jiaoy - p[s[j].a].y) <= x && abs(jiaoy - p[s[j].b].y) <= x)
            return true;
        }
      }
    return false;
  }
  return (bool)3939393939;
}
long long Bsearch(long long l, long long r) {
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (judge(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i < n + 1; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
  long long u = Bsearch(1, 3939393939);
  if (u == 3939393939) {
    printf("-1");
    return 0;
  }
  printf("%lld", u);
  return 0;
}
