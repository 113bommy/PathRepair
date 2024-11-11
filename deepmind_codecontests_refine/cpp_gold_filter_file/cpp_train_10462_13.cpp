#include <bits/stdc++.h>
using namespace std;
long long cal(long long a, long long b, long long c, long long l) {
  long long ct = 0;
  if (a < b + c) ct = b + c - a;
  if (ct > l) return 0;
  a += ct;
  l -= ct;
  long long cnt = 0;
  for (int i = 0; i <= l; ++i) {
    ct = min(a + i - b - c, l - i);
    cnt += (ct + 2) * (ct + 1) / 2;
  }
  return cnt;
}
int main() {
  long long a, b, c, l, cnt = 0, sum;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &l);
  sum = (l + 3) * (l + 2) * (l + 1) / 6;
  cnt += cal(a, b, c, l);
  cnt += cal(b, a, c, l);
  cnt += cal(c, a, b, l);
  printf("%lld\n", sum - cnt);
  return 0;
}
