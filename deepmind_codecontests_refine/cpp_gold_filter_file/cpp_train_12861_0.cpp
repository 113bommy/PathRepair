#include <bits/stdc++.h>
using namespace std;
long long c[1000005], m;
long long val(long long i) {
  long long moo = 0;
  for (long long j = 2; j <= 1000002; ++j) {
    if (c[j] > i) break;
    moo += (i / c[j]);
  }
  return moo;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> m;
  for (long long i = 1; i <= 1000003; ++i) c[i] = i * i * i;
  long long l = 1, r = 1000000000000000005, mid = (l + r) / 2, v, ans = 0;
  while (l < r) {
    v = val(mid);
    if (v == m) ans = mid;
    if (v >= m)
      r = mid;
    else
      l = mid + 1;
    mid = (l + r) / 2;
  }
  if (v == m || ans != 0)
    cout << mid << endl;
  else
    cout << -1 << endl;
  return 0;
}
