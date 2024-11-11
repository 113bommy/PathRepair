#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000010;
const int P = 1000000007;
struct matrix {
  int num[2][2];
  matrix operator*(matrix a) {
    matrix ans;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++) {
        ans.num[i][j] = 0;
        for (int k = 0; k <= 1; k++) {
          long long temp = (long long)num[i][k] * a.num[k][j] % P;
          ans.num[i][j] = (ans.num[i][j] + temp) % P;
        }
      }
    return ans;
  }
  matrix operator+(matrix a) {
    matrix ans;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++)
        ans.num[i][j] = (num[i][j] + a.num[i][j]) % P;
    return ans;
  }
} sum[maxn], add[maxn], t, e, z;
void init() {
  e.num[0][0] = 1;
  e.num[1][1] = 1;
  e.num[0][1] = 0;
  e.num[1][0] = 0;
  t.num[0][0] = 1;
  t.num[0][1] = 1;
  t.num[1][0] = 1;
  t.num[1][1] = 0;
  z.num[0][0] = 0;
  z.num[0][1] = 0;
  z.num[1][0] = 0;
  z.num[1][1] = 0;
}
int n, m, val[maxn];
matrix qpow(matrix a, int b) {
  matrix ans = e;
  for (; b; a = a * a, b = b / 2)
    if (b & 1) ans = ans * a;
  return ans;
}
void build_tree(int o, int l, int r) {
  if (l == r) {
    sum[o] = qpow(t, val[(l + r) / 2] - 1);
    add[o] = e;
    return;
  }
  int mid = (l + r) / 2;
  build_tree(2 * o, l, mid);
  build_tree(2 * o + 1, mid + 1, r);
  sum[o] = sum[2 * o] + sum[2 * o + 1];
  add[o] = e;
  return;
}
void add_tree(int o, int l, int r, int L, int R, matrix x) {
  if (l >= L && r <= R) {
    add[o] = add[o] * x;
    sum[o] = sum[o] * x;
    return;
  }
  int mid = (l + r) / 2;
  if (L <= mid) add_tree(2 * o, l, mid, L, R, x);
  if (R >= mid + 1) add_tree(2 * o + 1, mid + 1, r, L, R, x);
  sum[o] = sum[2 * o] + sum[2 * o + 1];
  sum[o] = sum[o] * add[o];
  return;
}
matrix query_tree(int o, int l, int r, int L, int R, matrix x) {
  if (l >= L && r <= R) {
    return sum[o] * x;
  }
  int mid = (l + r) / 2;
  matrix ans = z;
  if (L <= mid) ans = ans + query_tree(2 * o, l, mid, L, R, x * add[o]);
  if (R >= mid + 1)
    ans = ans + query_tree(2 * o + 1, mid + 1, r, L, R, x * add[o]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m), init();
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  build_tree(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      add_tree(1, 1, n, l, r, qpow(t, x));
    }
    if (ty == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      matrix ans = query_tree(1, 1, n, l, r, e);
      printf("%d\n", ans.num[0][0]);
    }
  }
  return 0;
}
