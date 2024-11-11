#include <bits/stdc++.h>
using namespace std;
const int L = 500005;
long long a[L], tmp[L], n, r, k;
inline long long rd() {
  long long ret = 0, c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
  return ret;
}
bool check(long long x) {
  for (int s = 0; s < n; s++) tmp[s] = a[s];
  long long cur = 0, cnt = 0;
  for (int s = 0; s < n; s++) {
    cur += tmp[s];
    if (cur < x) {
      cnt += x - cur;
      tmp[s] += x - cur;
      tmp[min(s + r * 2 + 1, n)] -= x - cur;
      cur = x;
      if (cur > k) return 0;
    }
  }
  return cnt <= k;
}
int main() {
  n = rd(), r = rd(), k = rd();
  for (int s = 0; s < n; s++) {
    long long x;
    x = rd();
    a[max(0LL, s - r)] += x;
    a[min(s + r + 1, n)] -= x;
  }
  long long l = 0, r = 2e18;
  while (l != r) {
    long long m = (l + r) >> 1;
    if (check(m))
      l = m + 1;
    else
      r = m;
  }
  if (!check(l)) l--;
  printf("%lld\n", l);
}
