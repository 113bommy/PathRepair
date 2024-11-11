#include <bits/stdc++.h>
using namespace std;
set<set<long long> > ss;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a[14], b[14], mans = 0;
  for (long long i = 0; i < 14; i++) cin >> a[i];
  for (long long i = 0; i < 14; i++) {
    for (long long j = 0; j < 14; j++) b[j] = a[j];
    long long p = a[0] / 14, q = a[0] % 14, ans = 0;
    b[0] = 0;
    for (long long j = 0; j < 14; j++) {
      b[j] += p;
    }
    for (long long j = 1; j < q + 1; j++) b[j] += 1;
    for (long long j = 0; j < 14; j++) {
      if (b[j] % 2 == 0) {
        ans += b[j];
      }
    }
    p = a[0];
    for (long long j = 0; j < 13; j++) {
      a[j] = a[j + 1];
    }
    a[13] = p;
    mans = max(ans, mans);
  }
  cout << mans;
}
