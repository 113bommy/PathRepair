#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, LOG = 70;
int n, power[LOG], between[LOG], extra[LOG], ende[LOG];
bool check(int x) {
  int cur = x;
  for (int i = 0; i < LOG; i++) {
    extra[i] = power[i] - cur;
    int newCur = min(cur, power[i + 1]);
    ende[i] = cur - newCur;
    cur = newCur;
  }
  int res = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    res += ende[i];
    res -= between[i];
    res -= extra[i + 1];
    if (res < 0) return false;
  }
  return res - extra[0] >= 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    int cur = 0;
    bool good = true;
    while (x > 1) {
      if (x & 1) good = false;
      x >>= 1;
      cur++;
    }
    if (good)
      power[cur]++;
    else
      between[cur]++;
  }
  int l = 1, r = power[0];
  while (l <= r) {
    int m = (l + r) >> 1;
    if (check(m))
      r = m - 1;
    else
      l = m + 1;
  }
  if (l <= r && check(l)) {
    for (int i = l; i <= power[0]; i++) printf("%d ", i);
  } else {
    printf("-1\n");
  }
  return 0;
}
