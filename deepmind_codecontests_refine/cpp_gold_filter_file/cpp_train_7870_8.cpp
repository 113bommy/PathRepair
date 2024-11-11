#include <bits/stdc++.h>
using namespace std;
int n, q, a[200005], son[5000005][2], sz[5000005], len;
long long ans;
void modify(int t, int c, int l, int r, int s) {
  int mid = (l + r) >> 1, k = (s > mid);
  sz[t] = sz[c] + 1;
  if (l == r) return;
  son[t][k ^ 1] = son[c][k ^ 1];
  son[t][k] = ++len;
  if (!k)
    modify((son[t][0]), (son[c][0]), l, mid, s);
  else
    modify((son[t][1]), (son[c][1]), mid + 1, r, s);
}
long long Q(int t, int c, int l, int r, int l1, int r1) {
  int mid = (l + r) >> 1;
  if (l > r1 || r < l1) return 0;
  if (l >= l1 && r <= r1) return sz[c] - sz[t];
  return Q((son[t][0]), (son[c][0]), l, mid, l1, r1) +
         Q((son[t][1]), (son[c][1]), mid + 1, r, l1, r1);
}
int main() {
  int i, l, r, u, d, p;
  scanf("%d %d", &n, &q), len = n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    modify(i, i - 1, 1, n, a[i]);
  }
  while (q--) {
    scanf("%d %d %d %d", &l, &u, &r, &d);
    ans = 1LL * n * (n - 1) / 2 - 1LL * (l - 1) * (l - 2) / 2 -
          1LL * (n - r) * (n - r - 1) / 2;
    p = Q(0, n, 1, n, 1, u - 1), ans -= 1LL * p * (p - 1) / 2;
    p = Q(0, n, 1, n, d + 1, n), ans -= 1LL * p * (p - 1) / 2;
    p = Q(0, l - 1, 1, n, 1, u - 1), ans += 1LL * p * (p - 1) / 2,
    p = Q(r, n, 1, n, 1, u - 1), ans += 1LL * p * (p - 1) / 2;
    p = Q(0, l - 1, 1, n, d + 1, n), ans += 1LL * p * (p - 1) / 2,
    p = Q(r, n, 1, n, d + 1, n), ans += 1LL * p * (p - 1) / 2;
    printf("%I64d\n", ans);
  }
  return 0;
}
