#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, maxn = 1e6 + 5;
int fa[maxn], rak[maxn];
int w, h;
void init(int n) {
  for (int i = 0; i < w; i++) {
    fa[i] = i;
    rak[i] = 0;
  }
}
int Find(int x) {
  if (x == fa[x])
    return x;
  else
    x = Find(fa[x]);
  return x;
}
bool same(int x, int y) {
  x = Find(x);
  y = Find(y);
  return x == y;
}
void unit(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (rak[x] < rak[y]) {
    fa[x] = y;
  } else if (rak[x] > rak[y]) {
    fa[y] = x;
  } else
    fa[x] = y, rak[y]++;
}
int solve(void) {
  if (h > w) swap(h, w);
  int res = 0;
  init(w);
  for (int i = 0; i < w; i++) {
    if (i <= h - 1) {
      int x1 = h - 1 - i, x2 = x1 + h - 1;
      if (x2 <= w - 1) {
        if (!same(i, x2)) {
          unit(i, x2);
        }
      } else {
        if (!same(i, ((w - 1) << 1) - x2)) unit(i, ((w - 1) << 1) - x2);
      }
    } else {
      int x1 = i - h + 1, x2 = (x1 << 1) - i;
      if (x2 >= 0 && !same(i, x2))
        unit(i, x2);
      else if (x2 < 0 && !same(i, -x2))
        unit(i, -x2);
    }
  }
  for (int i = 0; i < w; i++) {
    if (i + h < w) {
      int x1 = i + h - 1, x2 = x1 + h - 1;
      if (x2 < w - 1 && !same(i, x2))
        unit(i, x2);
      else if (x2 >= w && !same(i, ((w - 1) << 1) - x2))
        unit(i, ((w - 1) << 1) - x2);
    } else {
      int x1 = ((w - 1) << 1) - i - h + 1, x2 = x1 - h + 1;
      if (x2 >= 0 && !same(i, x2))
        unit(i, x2);
      else if (x2 < 0 && !same(i, -x2))
        unit(i, -x2);
    }
  }
  set<int> st;
  for (int i = 0; i < w; i++) st.insert(fa[i]);
  return (int)st.size();
}
int main(void) {
  while (~scanf("%d%d", &h, &w)) printf("%d\n", solve());
  return 0;
}
