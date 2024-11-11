#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int maxn = 1e6 + 5;
int a[maxn], b[maxn], l[maxn], r[maxn];
int bin(int x, int n) {
  int l = 1, r = n;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (b[m] == x) return m;
    if (b[m] > x)
      r = m - 1;
    else
      l = m + 1;
  }
}
int sum[maxn << 2];
void pushUp(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void update(int p, int l, int r, int rt) {
  if (l == r) {
    sum[rt]++;
    return;
  }
  int m = (l + r) >> 1;
  if (p <= m)
    update(p, l, m, rt << 1);
  else
    update(p, m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L <= l && R >= r) {
    return sum[rt];
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (L <= m) ret += query(L, R, l, m, rt << 1);
  if (R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    int x = bin(a[i], n);
    r[i] = query(1, x, 1, n, 1);
    update(x, 1, n, 1);
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    int x = bin(a[i], n);
    l[i] = query(x, n, 1, n, 1);
    update(x, 1, n, 1);
  }
  for (int i = 1; i <= n; i++) {
    ans += 1LL * l[i] * r[i];
  }
  cout << ans << endl;
}
