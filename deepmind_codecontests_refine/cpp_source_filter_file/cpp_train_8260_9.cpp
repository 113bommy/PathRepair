#include <bits/stdc++.h>
using namespace std;
set<long long> k;
long long n, a[100001], ans;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    k.insert(a[i]);
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = i - 1; j >= 0; j--) {
      if (a[j] == (a[j] | a[i])) break;
      a[j] |= a[i];
      k.insert(a[j]);
    }
  }
  ans = k.size();
  cout << ans;
  return 0;
}
