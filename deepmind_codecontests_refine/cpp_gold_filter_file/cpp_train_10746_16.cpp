#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 7;
int n, a[N], b[N], ans;
inline bool calc(int L, int R) {
  if (L > R) return 0;
  long long ret = 0;
  for (int i = n, l = 1, r = 1; i; i--) {
    while (l <= n && b[i] + b[l] < L) ++l;
    while (r <= n && b[i] + b[r] <= R) ++r;
    ret += r - l - (l <= i && i < r);
  }
  return (ret >> 1) & 1;
}
inline bool solve(int k) {
  for (int i = 1; i <= n; i++) b[i] = a[i] & ((1 << (k + 1)) - 1);
  sort(b + 1, b + n + 1);
  return calc(1 << k, (1 << (k + 1)) - 1) ^ calc(3 << k, (1 << (k + 2)) - 2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < 26; i++) ans |= solve(i) << i;
  printf("%d", ans);
  return 0;
}
