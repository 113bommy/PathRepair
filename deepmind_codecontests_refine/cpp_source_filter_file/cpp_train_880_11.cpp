#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 100000, NN = 131072, Q = 200000;
pair<int, int> a[Q];
struct S {
  int id, x, y, xx, yy;
  bool ans;
  bool operator<(const S &o) const { return xx < o.xx; }
} b[Q];
int mx[NN * 2];
void change(int x, int y) {
  mx[x += NN - 1] = y;
  while (x) {
    x = (x - 1) / 2;
    mx[x] = min(mx[2 * x + 1], mx[2 * x + 2]);
  }
}
int getMin(int l, int h) {
  int ret = INT_MAX;
  l += NN - 1;
  h += NN - 1;
  for (; l < h; l >>= 1, h >>= 1) {
    if (l % 2 == 0) ret = min(ret, mx[l++]);
    if (h % 2 == 0) ret = min(ret, mx[--h]);
  }
  return ret;
}
int main() {
  int n = ri(), m = ri(), k = ri(), q = ri();
  for (int i = 0; i < (k); i++) {
    a[i].first = ri() - 1;
    a[i].second = ri() - 1;
  }
  for (int i = 0; i < (q); i++) {
    b[i].id = i;
    b[i].x = ri() - 1;
    b[i].y = ri() - 1;
    b[i].xx = ri() - 1;
    b[i].yy = ri() - 1;
    if (b[i].x > b[i].xx) swap(b[i].x, b[i].xx);
    if (b[i].y > b[i].yy) swap(b[i].y, b[i].yy);
  }
  for (int p = 1; p <= (2); p++) {
    fill_n(mx, 2 * NN, -1);
    sort(a, a + k);
    sort(b, b + q);
    int j = 0;
    for (int i = 0; i < (q); i++) {
      for (; j < k && a[j].first <= b[i].xx; j++)
        change(a[j].second, a[j].first);
      if (getMin(b[i].y, b[i].yy + 1) >= b[i].x) b[i].ans = true;
    }
    for (int i = 0; i < (k); i++) swap(a[i].first, a[i].second);
    for (int i = 0; i < (q); i++) {
      swap(b[i].x, b[i].y);
      swap(b[i].xx, b[i].yy);
    }
  }
  sort(b, b + k, [](const S &x, const S &y) { return x.id < y.id; });
  for (int i = 0; i < (q); i++) puts(b[i].ans ? "YES" : "NO");
}
