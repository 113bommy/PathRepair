#include <bits/stdc++.h>
using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const long long MOD = 1e9 + 7;
long long rec(long long x1, long long x2, long long y1, long long y2,
              long long upper, long long len, long long offs) {
  if (upper < 0) return 0;
  if (x1 > y1 || (x1 == y1 && x2 < y2)) swap(x1, y1), swap(x2, y2);
  if (x1 == 0 && x2 == len) {
    upper = min(upper, len);
    long long sum = ((upper * (upper - 1)) / 2) % MOD;
    long long res = ((y2 - y1) * ((sum + (offs * len) % MOD) % MOD)) % MOD;
    return res;
  }
  long long res = 0;
  len /= 2;
  if (x1 < len && y1 < len)
    res += rec(x1, min(x2, len), y1, min(y2, len), upper, len, offs);
  if (x2 > len && y1 < len)
    res += rec(max(x1 - len, 0LL), x2 - len, y1, min(y2, len), upper - len, len,
               offs + len);
  if (x1 < len && y2 > len)
    res += rec(x1, min(x2, len), max(y1 - len, 0LL), y2 - len, upper - len, len,
               offs + len);
  if (x2 > len && y2 > len)
    res += rec(max(x1 - len, 0LL), x2 - len, max(y1 - len, 0LL), y2 - len,
               upper, len, offs);
  return res % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    long long x1, y1, x2, y2, k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--, y1--;
    cout << rec(x1, x2, y1, y2, k - 1, 1 << 30, 1) << "\n";
  }
}
