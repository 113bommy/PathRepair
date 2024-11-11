#include <bits/stdc++.h>
using namespace std;
int nxt() {
  int a;
  scanf("%d", &a);
  return a;
}
const int N = 100000;
int t[N << 1];
int n, m;
struct Pt {
  int x, y;
  Pt() {}
  Pt(int x, int y) : x(x), y(y) {}
  bool operator<(const Pt &r) const { return y < r.y; }
};
struct Rect {
  int x1, y1, x2, y2;
  int id;
  Rect() {}
  Rect(int x1, int y1, int x2, int y2, int id)
      : x1(x1), y1(y2), x2(x2), y2(y2), id(id) {}
  bool operator<(const Rect &r) const { return y2 < r.y2; }
};
Rect Q[N];
Pt P[N];
char ans[N];
void upd(int i, int val) {
  i += n;
  t[i] = val;
  for (; i > 0; i >>= 1) {
    t[i >> 1] = min(t[i], t[i ^ 1]);
  }
}
int get(int l, int r) {
  int ret = INT_MAX;
  for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if (l & 1) ret = min(ret, t[l]);
    if (!(r & 1)) ret = min(ret, t[r]);
  }
  return ret;
}
int main() {
  int n = nxt();
  int m = nxt();
  int k = nxt();
  int q = nxt();
  for (int i = 0; i < k; ++i) {
    P[i].x = nxt() - 1;
    P[i].y = nxt() - 1;
  }
  for (int i = 0; i < q; ++i) {
    Q[i].x1 = nxt() - 1;
    Q[i].y1 = nxt() - 1;
    Q[i].x2 = nxt() - 1;
    Q[i].y2 = nxt() - 1;
    Q[i].id = i;
  }
  for (int qwer = 0; qwer < 2; ++qwer) {
    sort(P, P + k);
    sort(Q, Q + q);
    for (int i = 0; i < 2 * n; ++i) {
      t[i] = INT_MIN;
    }
    for (int y = 0, i = 0, j = 0; y < m; ++y) {
      while (i < k && P[i].y <= y) {
        upd(P[i].x, y);
        ++i;
      }
      while (j < q && Q[j].y2 <= y) {
        int l = Q[j].x1;
        int r = Q[j].x2;
        int mi = get(l, r);
        if (mi >= Q[j].y1) {
          ans[Q[j].id] = 1;
        }
        ++j;
      }
    }
    swap(n, m);
    for (int i = 0; i < k; ++i) {
      swap(P[i].x, P[i].y);
    }
    for (int i = 0; i < q; ++i) {
      swap(Q[i].x1, Q[i].y1);
      swap(Q[i].x2, Q[i].y2);
    }
  }
  for (int i = 0; i < q; ++i) {
    puts(ans[i] ? "YES" : "NO");
  }
  return 0;
}
