#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long i = 0;
  long long j = n - 1;
  long long ans = 0;
  long long cur = 0;
  long long cur2 = 0;
  while (i < j) {
    cur += a[i++];
    while (j >= i && cur2 < cur) {
      cur2 += a[j--];
    }
    if (cur == cur2) {
      ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
