#include <bits/stdc++.h>
using namespace std;
;
long long read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const double eps = 1e-8;
const int MOD = 1e9 + 7;
const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
struct Mat {
  int a[2][2];
  void clear() { memset(a, 0, sizeof(a)); }
  void one() {
    a[0][0] = a[1][1] = 1;
    a[0][1] = a[1][0] = 0;
  }
  Mat operator+(const Mat &b) const {
    Mat tmp;
    tmp.clear();
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        tmp.a[i][j] = a[i][j] + b.a[i][j];
        if (tmp.a[i][j] >= MOD) {
          tmp.a[i][j] -= MOD;
        }
      }
    }
    return tmp;
  }
  Mat operator*(const Mat &b) const {
    Mat tmp;
    tmp.clear();
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          tmp.a[i][k] += (long long)a[i][j] * b.a[j][k] % MOD;
          if (tmp.a[i][k] >= MOD) {
            tmp.a[i][k] -= MOD;
          }
        }
      }
    }
    return tmp;
  }
  Mat pw(int x) {
    Mat ans, num = *this;
    ans.one();
    while (x > 0) {
      if (x & 1) {
        ans = ans * num;
      }
      num = num * num;
      x >>= 1;
    }
    return ans;
  }
};
int a[maxn];
Mat sum[maxn << 2];
Mat lazy[maxn << 2];
Mat fibo, val;
void push_up(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void push_down(int rt) {
  lazy[rt << 1] = lazy[rt << 1] * lazy[rt];
  lazy[rt << 1 | 1] = lazy[rt << 1 | 1] * lazy[rt];
  sum[rt << 1] = sum[rt << 1] * lazy[rt];
  sum[rt << 1 | 1] = sum[rt << 1 | 1] * lazy[rt];
  lazy[rt].one();
}
void build(int l, int r, int rt) {
  sum[rt].clear();
  lazy[rt].one();
  if (l == r) {
    sum[rt] = fibo.pw(a[l] - 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
void update(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    sum[rt] = sum[rt] * val;
    lazy[rt] = lazy[rt] * val;
    return;
  }
  int mid = (l + r) >> 1;
  push_down(rt);
  if (L <= mid) update(L, R, l, mid, rt << 1);
  if (R > mid) update(L, R, mid + 1, r, rt << 1 | 1);
  push_up(rt);
}
Mat query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return sum[rt];
  }
  int mid = (l + r) >> 1;
  push_down(rt);
  Mat ans;
  ans.clear();
  if (L <= mid) ans = ans + query(L, R, l, mid, rt << 1);
  if (R > mid) ans = ans + query(L, R, mid + 1, r, rt << 1 | 1);
  return ans;
}
int main() {
  fibo.a[0][0] = fibo.a[0][1] = fibo.a[1][0] = 1;
  fibo.a[1][1] = 0;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      val = fibo;
      val.pw(x);
      update(l, r, 1, n, 1);
    } else {
      Mat ans;
      ans = query(l, r, 1, n, 1);
      printf("%d\n", (ans.a[1][0] + ans.a[1][1]) % MOD);
    }
  }
  return 0;
}
