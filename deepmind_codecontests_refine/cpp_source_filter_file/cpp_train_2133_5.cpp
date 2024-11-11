#include <bits/stdc++.h>
using namespace std;
long long A, B;
long long n;
int check(long long mid, long long l, long long t, long long m) {
  long long biggest = mid * B + A - B;
  if (biggest > t) return 1;
  long long cnt = mid - l + 1;
  long long smallest = l * B + A - B;
  long long sum = (biggest + smallest) * cnt / 2;
  if (t * min(m, cnt) < sum)
    return 1;
  else
    return 0;
}
long long calc(long long _l, long long t, long long m) {
  long long l = _l;
  long long r = 1e18;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (check(mid, _l, t, m))
      r = mid;
    else
      l = mid;
  }
  return (check(l, _l, t, m) == 0) ? l : -1;
}
int main() {
  long long l, t, m;
  cin >> A >> B >> n;
  for (int i = 0; i < n; ++i) {
    cin >> l >> t >> m;
    long long res = calc(l, t, m);
    cout << res << endl;
  }
  return 0;
}
