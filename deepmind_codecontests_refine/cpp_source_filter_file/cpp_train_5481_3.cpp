#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
signed main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> ruio(n + 1, 0);
  vector<long long> ruit(n + 1, 0);
  long long ro = 0;
  long long rt = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      ro++;
    } else {
      rt++;
    }
    ruio[i + 1] = ro;
    ruit[i + 1] = rt;
  }
  long long ans = rt;
  for (long long i = 0; i < n; i++) {
    long long ltmp = 0;
    for (long long j = 0; j < i; j++) {
      ltmp = max(ltmp, ruio[j] + (ruit[i + 1] - ruit[j]));
    }
    long long rtmp = 0;
    for (long long j = i; j < n; j++) {
      rtmp = max(rtmp, (ruit[j + 1] - ruit[i]) + (ruio[n] - ruio[j]));
    }
    ans = max(ans, ltmp + rtmp);
  }
  cout << ans << endl;
}
