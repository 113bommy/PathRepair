#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 3e5 + 10;
int n, a[N], l[N][17], r[N][17];
pair<int, int> v[17][N << 2];
inline pair<int, int> operator+(const pair<int, int> &a,
                                const pair<int, int> &b) {
  return make_pair(min(a.first, b.first), max(a.second, b.second));
}
inline void Build(int k, int u, int l, int r) {
  if (l == r) return v[k][u] = make_pair(::l[l][k], ::r[l][k]), void(0);
  int mid = l + r >> 1;
  Build(k, u << 1, l, mid), Build(k, u << 1 ^ 1, mid + 1, r);
  v[k][u] = v[k][u << 1] + v[k][u << 1 ^ 1];
}
inline pair<int, int> Query(int k, int u, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return v[k][u];
  int mid = l + r >> 1;
  if (qr <= mid) return Query(k, u << 1, l, mid, ql, qr);
  if (ql > mid) return Query(k, u << 1 ^ 1, mid + 1, r, ql, qr);
  return Query(k, u << 1, l, mid, ql, qr) +
         Query(k, u << 1 ^ 1, mid + 1, r, ql, qr);
}
int main() {
  n = read();
  for (register int i = (1); i <= (n); i++) a[i] = read();
  for (register int i = (n + 1); i <= (3 * n); i++) a[i] = a[i - n];
  for (register int i = (1); i <= (3 * n); i++)
    l[i][0] = max(1, i - a[i]), r[i][0] = min(3 * n, i + a[i]);
  Build(0, 1, 1, 3 * n);
  for (register int j = (1); j <= (16); j++) {
    for (register int i = (1); i <= (3 * n); i++) {
      pair<int, int> tmp = Query(j - 1, 1, 1, 3 * n, l[i][j - 1], r[i][j - 1]);
      l[i][j] = tmp.first, r[i][j] = tmp.second;
    }
    Build(j, 1, 1, 3 * n);
  }
  if (n == 1) return puts("0"), 0;
  for (register int i = (n + 1); i <= (2 * n); i++) {
    int l = i, r = i, ans = 0;
    for (register int j = (16); j >= (0); j--) {
      pair<int, int> tmp = Query(j, 1, 1, 3 * n, l, r);
      if (tmp.second - tmp.first + 1 < n)
        l = tmp.first, r = tmp.second, ans += 1 << j;
    }
    printf("%d ", ans + 1);
  }
}
