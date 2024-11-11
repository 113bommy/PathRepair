#include <bits/stdc++.h>
using namespace std;
int n, p1[100005], p2[100005], p3[100005];
struct hh {
  int x, v, p, p1, p2;
  bool operator<(hh a) const { return 1ll * x * a.v < 1ll * a.x * v; }
} sk[100005 * 3];
int pw(int x, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = 1ll * ans * x % 998244353;
    x = 1ll * x * x % 998244353;
    p >>= 1;
  }
  return ans;
}
int tr[100005 << 2][2][2];
void xc(int a[2][2], int b[2][2]) {
  int c[2][2];
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) c[i][j] = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        c[i][k] = (c[i][k] + 1ll * a[i][j] * b[j][k]) % 998244353;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) a[i][j] = c[i][j];
}
void build(int p, int l, int r) {
  if (l == r) {
    for (int i = 0; i < 2; ++i) {
      tr[p][i][0] = 1 - p3[l + 1];
      tr[p][i][1] = p3[l + 1];
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) tr[p][i][j] = tr[p << 1][i][j];
  xc(tr[p], tr[p << 1 | 1]);
}
int a[2];
void Xc(int a[2], int b[2][2]) {
  int c[2];
  for (int i = 0; i < 2; ++i) c[i] = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      c[j] = (c[j] + 1ll * a[i] * b[i][j]) % 998244353;
  for (int i = 0; i < 2; ++i) a[i] = c[i];
}
void query(int p, int l, int r, int L, int R) {
  if (l == L && r == R) {
    Xc(a, tr[p]);
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    query(p << 1, l, mid, L, R);
  else if (L > mid)
    query(p << 1 | 1, mid + 1, r, L, R);
  else
    query(p << 1, l, mid, L, mid), query(p << 1 | 1, mid + 1, r, mid + 1, R);
}
void update(int p, int l, int r, int x, int w1, int w2) {
  if (l == r) {
    tr[p][w1][w2] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(p << 1, l, mid, x, w1, w2);
  else if (x > mid)
    update(p << 1 | 1, mid + 1, r, x, w1, w2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) tr[p][i][j] = tr[p << 1][i][j];
  xc(tr[p], tr[p << 1 | 1]);
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d", &p1[i], &p2[i], &p3[i]),
        p3[i] = 1ll * p3[i] * pw(100, 998244353 - 2) % 998244353;
  int tot = 0;
  for (int i = 1; i < n; ++i) {
    sk[++tot] = (hh){p1[i + 1] - p1[i], p2[i] + p2[i + 1], i, 1, 0};
    if (p2[i + 1] > p2[i])
      sk[++tot] = (hh){p1[i + 1] - p1[i], p2[i + 1] - p2[i], i, 0, 0};
    else if (p2[i] > p2[i + 1])
      sk[++tot] = (hh){p1[i + 1] - p1[i], p2[i] - p2[i + 1], i, 1, 1};
  }
  sort(sk + 1, sk + tot + 1);
  build(1, 1, n - 1);
  int sum = 0;
  for (int i = 1; i <= tot; ++i) {
    int x = sk[i].p;
    a[0] = 1 - p3[1];
    a[1] = p3[1];
    if (x > 1) query(1, 1, n - 1, 1, x - 1);
    a[sk[i].p1 ^ 1] = 0;
    query(1, 1, n - 1, x, x);
    a[sk[i].p2 ^ 1] = 0;
    if (x + 1 < n) query(1, 1, n - 1, x + 1, n - 1);
    sum = (sum + 1ll * (a[0] + a[1]) % 998244353 * sk[i].x % 998244353 *
                     pw(sk[i].v, 998244353 - 2)) %
          998244353;
    update(1, 1, n - 1, x, sk[i].p1, sk[i].p2);
  }
  printf("%d", (sum + 998244353) % 998244353);
}
