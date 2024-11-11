#include <bits/stdc++.h>
using namespace std;
long long s[200005], e[200005];
long long win(long long s, long long e) {
  if (e & 1) {
    if (s & 1) return 0;
    return 1;
  }
  if (s > e / 2) {
    if (s & 1) return 1;
    return 0;
  }
  if (s > e / 4) return 1;
  return win(s, e >> 2);
}
long long lose(long long s, long long e) {
  if (s > e / 2) return 1;
  return win(s, e >> 1);
}
int main() {
  long long i, n, j, k, t, m, w, l, cur = 0;
  scanf("%lld", &t);
  for (i = 1; i <= t; i++) scanf("%lld%lld", &s[i], &e[i]);
  for (i = 1; i <= t; i++) {
    w = win(s[i], e[i]);
    l = lose(s[i], e[i]);
    w ^= cur;
    l ^= cur;
    if (w == l) break;
    if (w)
      cur = 1;
    else
      cur = 0;
  }
  printf("%lld %lld\n", w, l);
}
