#include <bits/stdc++.h>
using namespace std;
void solve(long long tc) {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  long long x = 0;
  bool f = 1;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    long long ctr = 0;
    if (v[i] == 0) continue;
    string str;
    while (v[i]) {
      ctr++;
      if (v[i] % k) {
        if (v[i] % k > 1)
          f = 0, cerr << "1";
        else
          str.push_back('1');
      } else
        str.push_back('0');
      v[i] = v[i] / k;
    }
    for (long long j = 0; j < str.size(); j++) {
      if (str[j] == '0') continue;
      if (x & (1ll << j)) {
        f = 0;
      } else
        x |= 1ll << j;
    }
  }
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cerr.tie(NULL);
  cout.precision(20);
  long long t = 1, ctr = 0;
  cin >> t;
  while (t--) {
    solve(ctr + 1);
    ctr++;
  }
}
