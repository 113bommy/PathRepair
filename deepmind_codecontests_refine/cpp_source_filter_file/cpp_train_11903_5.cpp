#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long temp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  string s;
  cin >> s;
  long long n = s.size();
  vector<long long> suff(n, 0ll);
  if (s[0] == '1') suff[0] = 1;
  for (long long i = 1; i < n; i++) {
    suff[i] = suff[i - 1];
    if (s[i] == '1') suff[i]++;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long indl = lower_bound(suff.begin(), suff.end(),
                                 s[i] == '1' ? suff[i] + k - 1 : suff[i] + k) -
                     suff.begin();
    long long indr = upper_bound(suff.begin(), suff.end(),
                                 s[i] == '1' ? suff[i] + k - 1 : suff[i] + k) -
                     suff.begin();
    ans += (indr - indl);
  }
  cout << ans << '\n';
  return 0;
}
