#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long a, b, id;
  bool operator<(const Point& rhs) const {
    return b < rhs.b || (b == rhs.b && a < rhs.a);
  }
};
struct Block {
  int cnt, id;
  Point bk[400];
} Bk[400];
int n, q, bsize, bcnt;
Point tmp[400], arr[110000];
struct Query {
  int l, r, t, id;
  bool operator<(const Query& rhs) const { return t < rhs.t; }
} qr[110000];
int ans[110000];
bool comp(Point A, Point B, Point C) {
  return (B.a - C.a) * (B.b - A.b) > (A.a - B.a) * (C.b - B.b);
}
Point calc(int l, int r, int t) {
  Point ret;
  ret.b = 0;
  for (int j = l; j <= r; j++) {
    long long val = arr[j].a + arr[j].b * t;
    if (val > ret.b) {
      ret.b = val;
      ret.a = j;
    }
  }
  return ret;
}
bool better(Point A, Point B, int t) { return A.a + A.b * t < B.a + B.b * t; }
int main() {
  while (cin >> n >> q) {
    bsize = sqrt(n);
    bcnt = n / bsize;
    for (int i = 0, j; i < n;) {
      int cb = i / bsize, cnt = 0;
      for (j = 0; i < n && j < bsize; j++, i++) {
        scanf("%I64d %I64d", &tmp[j].a, &tmp[j].b);
        tmp[j].id = i;
        arr[i] = tmp[j];
      }
      sort(tmp, tmp + j);
      for (int k = 0; k < j; k++) {
        if (cnt > 0 && Bk[cb].bk[cnt - 1].b == tmp[k].b) continue;
        while (cnt > 0 && Bk[cb].bk[cnt - 1].a <= tmp[k].a) cnt--;
        while (cnt > 1 && !comp(Bk[cb].bk[cnt - 2], Bk[cb].bk[cnt - 1], tmp[k]))
          cnt--;
        Bk[cb].bk[cnt++] = tmp[k];
      }
      Bk[cb].cnt = cnt;
      Bk[cb].id = 0;
    }
    for (int i = 0; i < q; i++) {
      scanf("%d %d %d", &qr[i].l, &qr[i].r, &qr[i].t);
      qr[i].l--;
      qr[i].r--;
      qr[i].id = i;
    }
    sort(qr, qr + q);
    for (int i = 0; i < q; i++) {
      int l = qr[i].l, r = qr[i].r, t = qr[i].t;
      int lb = l / bsize, rb = r / bsize;
      Point tmpans;
      tmpans.b = 0;
      if (lb == rb) {
        tmpans = max(tmpans, calc(l, r, t));
      } else {
        tmpans = max(tmpans, calc(l, (lb + 1) * bsize - 1, t));
        for (int k = lb + 1; k < rb; k++) {
          Block& A = Bk[k];
          while (A.id < A.cnt - 1 && better(A.bk[A.id], A.bk[A.id + 1], t))
            A.id++;
          long long val = A.bk[A.id].a + A.bk[A.id].b * t;
          if (val > tmpans.b) {
            tmpans.b = val;
            tmpans.a = A.bk[A.id].id;
          }
        }
        tmpans = max(tmpans, calc(rb * bsize, r, t));
      }
      ans[qr[i].id] = tmpans.a;
    }
    for (int i = 0; i < q; i++) {
      printf("%d\n", ans[i] + 1);
    }
  }
}
