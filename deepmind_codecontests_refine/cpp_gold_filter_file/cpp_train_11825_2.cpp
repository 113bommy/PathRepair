#include <bits/stdc++.h>
using namespace std;
long long lvl[100];
int main() {
  lvl[1] = 1;
  for (int i = 2; i <= 55; i++) {
    lvl[i] = lvl[i - 1] * 2 + 1;
  }
  long long n, r, l;
  scanf("%lld %lld %lld", &n, &l, &r);
  long long temp = n;
  long long idx = 2;
  while (temp > 1) {
    idx++;
    temp /= 2;
  }
  long long tot = 0;
  for (long long i = l; i <= r; i++) {
    int cnt = 50;
    long long lo = 1, hi = lvl[idx - 1], mid;
    long long ret = 0;
    temp = n;
    while (cnt--) {
      mid = (lo + hi) / 2;
      if (mid == i) {
        ret = temp % 2;
        break;
      } else if (i < mid) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
      temp = temp / 2;
    }
    tot = tot + ret;
  }
  printf("%lld", tot);
}
