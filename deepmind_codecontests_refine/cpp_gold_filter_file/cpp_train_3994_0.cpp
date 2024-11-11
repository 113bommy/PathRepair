#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long mod = 1000000007;
int n, k, a[100005], f[100005];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = 0, r = 0, len = 1e6, lo = 0, hi = 0, d = 0;
  while (l < n) {
    while (d < k && r < n) {
      if (f[a[r]] == 0) d++;
      f[a[r]]++;
      ++r;
    }
    if ((r - l + 1) < len && d == k) {
      len = r - l + 1;
      lo = l;
      hi = r;
    }
    f[a[l]]--;
    if (!f[a[l]]) --d;
    ++l;
  }
  if (len == 1e6)
    puts("-1 -1");
  else
    cout << lo + 1 << " " << hi << endl;
  return 0;
}
