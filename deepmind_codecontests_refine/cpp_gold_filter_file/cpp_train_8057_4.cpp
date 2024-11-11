#include <bits/stdc++.h>
using namespace std;
int n, m;
long long h[100002];
long long p[100002];
int check(long long t) {
  int r = 0;
  long long d;
  for (int i = 0; i < n; i++) {
    if (p[r] < h[i]) {
      long long tmp = h[i] - p[r];
      if (t < tmp) return 0;
      d = h[i];
      if (t > 2 * tmp) d += t - 2 * tmp;
      if ((t - tmp) / 2 + h[i] > d) d = h[i] + (t - tmp) / 2;
    } else {
      d = h[i] + t;
    }
    while (r < m && d >= p[r]) r++;
    if (r == m) return 1;
  }
  return 0;
}
long long search(long long l, long long h) {
  if (l == h) return l;
  long long mid = (l + h) / 2;
  if (check(mid)) {
    return search(l, mid);
  } else {
    return search(mid + 1, h);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &h[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%I64d", &p[i]);
  }
  printf("%I64d\n", search(0, 16000000000));
}
