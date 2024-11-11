#include <bits/stdc++.h>
using namespace std;
const long long M = 2e5 + 5;
long long n, a[M], cnt[32];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    for (long long j = 31; j >= 0; j--)
      if (a[i] & (1 << j)) cnt[j]++;
  }
  long long idx = 0, mx = 0;
  for (long long i = 0; i < n; i++) {
    long long cur = 0;
    for (long long j = 31; j >= 0; j--)
      if ((a[i] & (1 << j)) && cnt[j] == 1) cur += (1 << j);
    if (cur > mx) {
      mx = cur;
      idx = i;
    }
  }
  cout << a[idx] << " ";
  for (long long i = 0; i < n; i++)
    if (i != idx) cout << a[i] << " ";
  return 0;
}
