#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const int maxn = (int)1e4 + 10;
int sum[maxn];
int v[maxn];
bitset<maxn> w;
int a[maxn], b[maxn];
int go(int rm, int x) {
  if (rm == -1) {
    return 0;
  }
  int l = 0;
  int r = rm + 1;
  while (l != r) {
    int m = (l + r) >> 1;
    if (sum[m] <= x) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
}
int main() {
  w[0] = 1;
  int n, l, r;
  cin >> n >> l >> r;
  int ps = 0;
  int sums = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sums += a[i];
  }
  if (r > sums) {
    r = sums;
  }
  l = sums - l;
  r = sums - r;
  swap(l, r);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) {
      v[ps++] = a[i];
    } else {
      w |= w << a[i];
    }
  }
  n = ps;
  sort(v, v + n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    now += v[i];
    sum[i] = now;
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = max(0, l - v[i]); j <= r - v[i]; j++) {
      if (w[j] == 1) {
        ans = max(ans, 1 + go(i - 1, r - (l + v[i])));
        break;
      }
    }
    w |= w << v[i];
  }
  cout << ans << endl;
}
