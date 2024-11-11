#include <bits/stdc++.h>
using namespace std;
int n;
long long ts, tf, t, ans, tc, x, pos;
int main() {
  scanf("%lld %lld %lld", &ts, &tf, &t);
  scanf("%d", &n);
  tc = ts;
  ans = 1e13;
  pos = 0;
  for (int i = 0; i < (int)n; i++) {
    scanf("%lld", &x);
    if (tc - (x - 1) < ans && tc + t <= tf) {
      ans = tc - (x - 1);
      pos = min(tc, x - 1);
    }
    tc = max(x, tc) + t;
  }
  if (tc + t <= tf) pos = tc;
  printf("%lld\n", pos);
}
