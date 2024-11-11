#include <bits/stdc++.h>
using namespace std;
long long getll() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct Mat {
  long long a[2][2];
  Mat() { memset(a, 0, sizeof(a)); }
};
Mat getM(int i) {
  Mat res;
  res.a[0][0] = res.a[1][1] = 1;
  return res;
}
Mat operator*(Mat x, Mat y) {
  Mat res;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        res.a[i][j] = (res.a[i][j] + x.a[k][j] * y.a[i][k]) % 1000000007;
      }
  return res;
}
bool operator==(Mat x, Mat y) {
  return x.a[0][0] == y.a[0][0] && x.a[0][1] == y.a[0][1] &&
         x.a[1][0] == y.a[1][0] && x.a[1][1] == y.a[1][1];
}
Mat operator+(Mat x, Mat y) {
  Mat res;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      res.a[i][j] = x.a[i][j] + y.a[i][j];
      while (res.a[i][j] >= 1000000007) res.a[i][j] -= 1000000007;
    }
  return res;
}
Mat pow(Mat x, long long y) {
  Mat res = getM(1);
  while (y) {
    if (y & 1) res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
Mat A;
Mat f1;
struct node {
  Mat tag, w;
  void add(Mat x) {
    tag = tag * x;
    w = w * x;
  }
  int l, r;
} tr[112345 << 2];
void update(int i) {
  tr[i].w = tr[i << 1].w + tr[i << 1 | 1].w;
  return;
}
void pushdown(int i) {
  if (tr[i].l == tr[i].r || (tr[i].tag == getM(1))) return;
  Mat x = tr[i].tag;
  tr[i << 1].w = tr[i << 1].w * x;
  tr[i << 1].tag = tr[i << 1].tag * x;
  tr[i << 1 | 1].w = tr[i << 1 | 1].w * x;
  tr[i << 1 | 1].tag = tr[i << 1 | 1].tag * x;
  tr[i].tag = getM(1);
  return;
}
void build(int i, int l, int r) {
  tr[i].tag = getM(1);
  tr[i].l = l, tr[i].r = r;
  if (l == r) {
    int x = getll();
    tr[i].w = f1 * pow(A, x - 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  update(i);
  return;
}
long long query(int i, int fl, int fr) {
  int l = tr[i].l, r = tr[i].r;
  if (fl <= l && r <= fr) return tr[i].w.a[1][0];
  pushdown(i);
  int mid = (l + r) >> 1;
  long long res = 0;
  if (fl <= mid) res += query(i << 1, fl, fr);
  if (fr >= mid + 1) res += query(i << 1 | 1, fl, fr);
  return res;
}
void modify(int i, int fl, int fr, Mat x) {
  int l = tr[i].l, r = tr[i].r;
  pushdown(i);
  if (fl <= l && r <= fr) {
    tr[i].add(x);
    return;
  }
  int mid = (l + r) >> 1;
  if (fl <= mid) modify(i << 1, fl, fr, x);
  if (fr >= mid + 1) modify(i << 1 | 1, fl, fr, x);
  update(i);
  return;
}
int main() {
  A.a[0][0] = 1;
  A.a[0][1] = 1;
  A.a[1][0] = 1;
  A.a[1][1] = 0;
  f1.a[0][0] = 1;
  f1.a[1][0] = 1;
  int n = getll(), m = getll();
  build(1, 1, n);
  while (m--) {
    int op = getll();
    int l = getll(), r = getll();
    if (op == 1) {
      int x = getll();
      modify(1, l, r, pow(A, x));
    }
    if (op == 2) {
      long long ans = query(1, l, r);
      ans %= 1000000007;
      cout << ans << endl;
    }
  }
  return 0;
}
