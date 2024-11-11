#include <bits/stdc++.h>
const int MAXN = 1005;
const int MAXK = 2005;
using namespace std;
long long p[MAXN], d[MAXK];
int n, k;
long long pos;
bool check(long long x) {
  int id = 1;
  int cnt = 0;
  for (int i = 1; i <= k && id <= n; i++) {
    long long tmp = abs(p[id] - d[i]) + abs(pos - d[i]);
    if (tmp <= x) {
      id++;
      cnt++;
    }
  }
  if (cnt == n) {
    return true;
  } else {
    return false;
  }
}
int main() {
  scanf("%d %d %lld", &n, &k, &pos);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &d[i]);
  }
  sort(p + 1, p + 1 + n);
  sort(d + 1, d + 1 + k);
  long long low = 0, up = 1e9, ans;
  while (low <= up) {
    long long mid = (low + up) >> 1;
    if (check(mid)) {
      ans = mid;
      up = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
