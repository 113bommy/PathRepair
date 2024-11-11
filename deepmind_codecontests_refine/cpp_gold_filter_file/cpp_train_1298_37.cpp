#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, m, k, p;
int a[N], h[N];
long long l[N];
int t[10010];
bool check(long long x) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += max(0ll, (l[i] - x + p - 1) / p);
  }
  if (sum > m * k) return 0;
  memset(t, 0, sizeof t);
  for (int i = 0; i < n; i++) {
    int d = 0;
    if (l[i] <= x) continue;
    for (long long target = (l[i] - x) % p ? (l[i] - x) % p : p;
         target <= l[i] - x; target += p) {
      if (target <= h[i]) {
        t[0]++;
      } else if (target > l[i] - a[i]) {
        return 0;
      } else {
        t[(target + a[i] - h[i] - 1) / a[i]]++;
      }
    }
  }
  int rest = 0;
  for (int i = 0; i < m; i++) {
    rest += t[i];
    rest = max(0, rest - k);
  }
  return rest == 0;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &p);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &h[i], &a[i]);
    l[i] = h[i] + 1ll * a[i] * m;
  }
  long long l = 0, r = 1e13;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
