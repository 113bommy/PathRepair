#include <bits/stdc++.h>
using namespace std;
typedef long long arr[300100 * 6];
arr a, s, b;
long long F[300100];
int n, i, m;
inline int gi() {
  int s = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch <= '9' && ch >= '0') s = s * 10 + ch - '0', ch = getchar();
  return s;
}
void Get(int x, int l, int r, long long f1, long long f2) {
  a[x] = (a[x] + f1) % 1000000009, b[x] = (b[x] + f2) % 1000000009;
  s[x] = (s[x] + f1 * F[r - l + 1] + f2 * (F[r - l + 2] - 1)) % 1000000009;
}
void Down(int x, int l, int r) {
  if (l == r) return;
  if (!a[x] && !b[x]) return;
  if (r - l == 1) {
    s[(x << 1)] = (s[(x << 1)] + a[x]) % 1000000009;
    s[(x << 1 | 1)] = (s[(x << 1 | 1)] + b[x]) % 1000000009;
    a[x] = b[x] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  Get((x << 1), l, mid, a[x], b[x]);
  long long c =
      (F[mid - l] * a[x] % 1000000009 + F[mid - l + 1] * b[x] % 1000000009) %
      1000000009;
  long long d = (F[mid - l + 1] * a[x] % 1000000009 +
                 F[mid - l + 2] * b[x] % 1000000009) %
                1000000009;
  Get((x << 1 | 1), mid + 1, r, c, d);
  a[x] = b[x] = 0;
}
void Build(int x, int l, int r) {
  if (l == r) {
    s[x] = gi();
    return;
  }
  int mid = (l + r) >> 1;
  Build((x << 1), l, mid);
  Build((x << 1 | 1), mid + 1, r);
  s[x] = s[(x << 1)] + s[(x << 1 | 1)];
}
void Updata(int x, int l, int r, int xl, int xr) {
  Down(x, l, r);
  if (xl <= l && r <= xr) {
    Get(x, l, r, F[l - xl + 1], F[l - xl + 2]);
    return;
  }
  int mid = (l + r) >> 1;
  if (xl <= mid) Updata((x << 1), l, mid, xl, xr);
  if (xr > mid) Updata((x << 1 | 1), mid + 1, r, xl, xr);
  s[x] = (s[(x << 1)] + s[(x << 1 | 1)]) % 1000000009;
}
long long Query(int x, int l, int r, int xl, int xr) {
  Down(x, l, r);
  if (xl <= l && r <= xr) return s[x];
  int mid = (l + r) >> 1;
  long long s = 0;
  if (xl <= mid) s += Query((x << 1), l, mid, xl, xr);
  if (xr > mid) s += Query((x << 1 | 1), mid + 1, r, xl, xr);
  return s % 1000000009;
}
int main() {
  scanf("%d%d", &n, &m);
  F[1] = F[2] = 1;
  for (i = 3; i <= 2 * n; i++) F[i] = (F[i - 2] + F[i - 1]) % 1000000009;
  Build(1, 1, n);
  for (i = 1; i <= m; i++) {
    int t = gi(), l = gi(), r = gi();
    if (t == 1)
      Updata(1, 1, n, l, r);
    else
      printf("%I64d\n", (1000000009 + Query(1, 1, n, l, r)) % 1000000009);
  }
  return 0;
}
