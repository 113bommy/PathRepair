#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 4e18;
const int inf = 2e9;
const int N = (1 << 20) + 10;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int a[N], b[N], tmp[N];
bool stat[22];
long long inv[22], des[22];
void merge(int l, int r, int lv) {
  if (lv == 0) return;
  int mid = (l + r) >> 1, i = l, j = mid + 1, cur = 0, t;
  merge(l, mid, lv - 1);
  merge(mid + 1, r, lv - 1);
  while (i <= mid && j <= r) {
    if (a[i] > a[j]) {
      inv[lv - 1] += mid - i + 1;
      tmp[cur++] = a[j++];
    } else
      tmp[cur++] = a[i++];
  }
  while (i <= mid) tmp[cur++] = a[i++];
  while (j <= r) tmp[cur++] = a[j++];
  for (t = r; t >= l; --t) a[t] = tmp[--cur];
}
void mergedes(int l, int r, int lv) {
  if (lv == 0) return;
  int mid = (l + r) >> 1, i = l, j = mid + 1, cur = 0, t;
  mergedes(l, mid, lv - 1);
  mergedes(mid + 1, r, lv - 1);
  while (i <= mid && j <= r) {
    if (b[i] < b[j]) {
      des[lv - 1] += mid - i + 1;
      tmp[cur++] = b[j++];
    } else
      tmp[cur++] = b[i++];
  }
  while (i <= mid) tmp[cur++] = b[i++];
  while (j <= r) tmp[cur++] = b[j++];
  for (t = r; t >= l; --t) a[t] = tmp[--cur];
}
int main(void) {
  int n, i, j, p, q, m;
  scanf("%d", &n);
  p = (1 << n);
  for (i = 0; i < p; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  merge(0, p - 1, n);
  mergedes(0, p - 1, n);
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &q);
    for (i = 0; i < q; ++i) stat[i] ^= 1;
    long long ans = 0;
    for (i = 0; i < n; ++i) ans += (stat[i] ? des[i] : inv[i]);
    printf("%I64d\n", ans);
  }
  return 0;
}
