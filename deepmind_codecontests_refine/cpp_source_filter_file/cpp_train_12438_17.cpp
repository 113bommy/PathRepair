#include <bits/stdc++.h>
using namespace std;
int n;
long long cs[200000];
bool check(long long mid) {
  int nxt = 0;
  nxt = upper_bound(cs, cs + n, cs[nxt] + 2 * mid) - cs;
  if (nxt == n) return 1;
  nxt = upper_bound(cs, cs + n, cs[nxt] + 2 * mid) - cs;
  if (nxt == n) return 1;
  nxt = upper_bound(cs, cs + n, cs[nxt] + 2 * mid) - cs;
  if (nxt == n) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &cs[i]);
    cs[i] <<= 1;
  }
  long long l = 0, r = 4e9, mid;
  sort(cs, cs + n);
  while (r - l > 0) {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else
      l = mid + 1;
  }
  printf("%lf\n", l / 2.0);
  int nxt = 0;
  printf("%lf", (cs[nxt] + l) / 2.0);
  nxt = upper_bound(cs, cs + n, cs[nxt] + 2 * l) - cs;
  printf("%lf", (cs[nxt] + l) / 2.0);
  nxt = upper_bound(cs, cs + n, cs[nxt] + 2 * l) - cs;
  printf("%lf\n", (cs[nxt] + l) / 2.0);
  return 0;
}
