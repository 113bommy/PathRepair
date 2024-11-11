#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::max;
using std::min;
long long n, m, len;
long long ask(long long x, long long to) {
  if (x <= to << 1) return 0;
  long long res = 0, l1 = x - 1, l2 = x, cnt1 = 0, cnt2 = 1;
  for (; l1 >= to << 1; l1 = (l2 >> 1) - 1, l2 >>= 1) {
    if (l1 == to << 1) return res + cnt2;
    res += cnt1 + cnt2,
        l1& 1 ? cnt1 = (cnt1 << 1) + cnt2 : cnt2 = (cnt2 << 1) + cnt1;
  }
  return res;
}
long long Solve(long long l, long long r, long long v) {
  long long mid = l + r >> 1;
  v--;
  if (!v) return mid;
  long long res1 = ask(mid - l, len), res2 = ask(r - mid, len + 1);
  if (v > res1 + res2)
    return Solve(mid + 1, r, v - res1);
  else
    return Solve(l, mid - 1, v - res2);
}
int main() {
  cin >> n >> m;
  if (m == 1) return puts("1");
  if (m == 2) return !printf("%lld\n", n);
  n -= 2, m -= 2;
  long long l = 0, r = n, mid;
  for (; l < r;) mid = l + r + 1 >> 1, ask(n, mid) < m ? r = mid - 1 : l = mid;
  len = l;
  cout << Solve(1, n, m) + 1 << "\n";
  return 0;
}
