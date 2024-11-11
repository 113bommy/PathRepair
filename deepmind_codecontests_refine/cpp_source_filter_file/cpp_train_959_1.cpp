#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
int a[N], b[N], n;
int get(int l, int x) {
  if (b[n] < x) return 0;
  int r = n, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (b[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return n - l + 1;
}
int main() {
  int i, j, m, sum, ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (j = 0; j <= 26; j++) {
    for (i = 1; i <= n; i++) b[i] = a[i] & ((1 << j + 1) - 1);
    sort(b + 1, b + i);
    sum = 0;
    for (i = 1; i < n; i++) {
      sum = (sum + get(i + 1, (1 << j) - b[i])) % 2;
      sum = (sum - get(i + 1, (1 << j + 1) - b[i])) % 2;
      sum = (sum + get(i + 1, (1 << j) + (1 << i + 1) - b[i])) % 2;
    }
    if (sum % 2) ans |= (1 << j);
  }
  printf("%d", ans);
  return 0;
}
