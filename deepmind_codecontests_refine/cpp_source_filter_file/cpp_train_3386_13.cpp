#include <bits/stdc++.h>
using namespace std;
inline long long next_int() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const long long maxn = 2e5 + 10;
long long a[maxn], init, pref[maxn];
struct CHT {
  vector<pair<long long, long long> > lines;
  inline long long val(pair<long long, long long> line, long long x) {
    return line.first + x * line.second;
  }
  inline long long where(pair<long long, long long> a,
                         pair<long long, long long> b) {
    if (a.second <= b.second) {
      if (a.first > b.first) return -1e18;
      return 1e18;
    }
    long long ret = (b.first - a.first) / (a.second - b.second);
    if (val(a, ret) < val(b, ret)) ret++;
    return ret;
  }
  inline void add_line(long long b, long long x) {
    while (lines.size() >= 2 &&
           where({b, x}, lines.back()) <
               where(lines.back(), lines[(long long)lines.size() - 2]))
      lines.pop_back();
    lines.push_back({b, x});
  }
  inline long long get_maxi(long long x) {
    long long l = -1, r = (long long)lines.size() - 1;
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      if (val(lines[mid], x) <= val(lines[mid + 1], x))
        l = mid;
      else
        r = mid;
    }
    return val(lines[r], x);
  }
} A, B;
long long res = -1e18;
int32_t main() {
  long long n = next_int();
  for (long long i = 1; i <= n; i++) a[i] = next_int(), init += a[i] * i;
  for (long long i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
  for (long long l = n - 1; l >= 1; l--) {
    A.add_line(-pref[l + 1], -l - 1);
    res = max(res, A.get_maxi(-a[l]) + pref[l] - a[l] * a[l] + init);
  }
  for (long long r = 2; r <= n; r++) {
    B.add_line(-pref[r - 2], r - 1);
    res = max(res, B.get_maxi(a[r]) + pref[r - 1] - a[r] * r + init);
  }
  res = max(res, init);
  cout << res << endl;
}
