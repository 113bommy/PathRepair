#include <bits/stdc++.h>
#pragma optimize("TKACHENKO-GORYACHENKO")
using namespace std;
const int maxn = 4e6 + 10;
const int shift = 2e6;
const int inf = 1e9 + 1;
int n, m, k, r;
struct point {
  int x;
  int y;
};
point A[maxn];
int V[4 * maxn];
int T[4 * maxn];
void push(int v, int tl, int tr) {
  if (T[v] == 0) {
    return;
  }
  V[v] += T[v];
  if (tl != tr) {
    T[2 * v] += T[v];
    T[2 * v + 1] += T[v];
  }
  T[v] = 0;
}
void update(int v, int tl, int tr, int l, int r, int color) {
  push(v, tl, tr);
  if (tl > r || l > tr || l > r) {
    return;
  }
  if (tl == l && tr == r) {
    T[v] += color;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, min(r, tm), color);
  update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, color);
  V[v] = max(V[2 * v], V[2 * v + 1]);
}
bool cmp(point a, point b) { return a.x < b.x; }
void add(int y) {
  y += shift;
  update(1, 0, maxn - 1, y, min(y + r, maxn - 1), 1);
}
void del(int y) {
  y += shift;
  update(1, 0, maxn - 1, y, min(y + r, maxn - 1), -1);
}
int main() {
  int q, w, e, a, b, c;
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> r;
  r = 2 * r;
  for (q = 0; q < n; q++) {
    cin >> a >> b;
    A[q].x = a + b;
    A[q].y = a - b;
  }
  sort(&A[0], &A[n], cmp);
  int i = 0;
  int ans = 0;
  for (q = 0; q < n; q++) {
    for (; i < n; i++) {
      if (A[i].x - A[q].x > r) {
        break;
      } else {
        add(A[i].y);
      }
    }
    push(1, 0, maxn - 1);
    ans = max(ans, V[1]);
    del(A[q].y);
  }
  cout << ans;
  return 0;
}
