#include <bits/stdc++.h>
using namespace std;
long long h[300000];
long long p[300000];
long long n, m;
bool judge(long long mid) {
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] + mid < p[tmp]) {
      continue;
    }
    if (h[i] - mid > p[tmp]) {
      return false;
    }
    long long pp = max(p[tmp] + mid - abs(h[i] - p[tmp]),
                       h[i] + (mid - abs(h[i] - p[tmp])) / 2);
    while (p[tmp] <= pp && tmp < m) {
      tmp++;
    }
    if (tmp == m) {
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &h[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%I64d", &p[i]);
  }
  sort(h, h + n);
  sort(p, p + n);
  long long l = 0, r;
  if (h[0] < p[0]) {
    r = p[m - 1] - h[0];
  } else {
    r = h[0] - p[0];
    if (h[0] < p[m - 1])
      r = min(r * 2 + p[m - 1] - h[0], r + 2 * (p[m - 1] - h[0]));
  }
  while (l < r) {
    long long mid = (l + r) / 2;
    if (judge(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%I64d\n", r);
  return 0;
}
