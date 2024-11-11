#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, m, s, k, x;
  cin >> m >> k >> n >> s;
  long long cnt = s;
  long long k1 = k;
  k = m - n * k + k;
  vector<long long> fl(m);
  vector<long long> ans(1000001);
  vector<long long> exp(1000001);
  for (long long i = 0; i < m; ++i) cin >> fl[i];
  for (long long i = 0; i < s; ++i) cin >> x, exp[x]++;
  for (long long i = 0; i < k; ++i) {
    ans[fl[i]]++;
    if (ans[fl[i]] <= exp[fl[i]]) cnt--;
  }
  long long q = k;
  if (cnt == 0) {
    cout << k - k1 << endl;
    for (long long j = 0; j < k; ++j) {
      if (exp[fl[j]] > 0)
        exp[fl[j]]--;
      else if (q > k1)
        cout << j + 1 << ' ', q--;
    }
    return 0;
  }
  for (long long i = k; i < m; ++i) {
    ans[fl[i - k]]--;
    if (ans[fl[i - k]] < exp[fl[i - k]]) cnt++;
    ans[fl[i]]++;
    if (ans[fl[i]] <= exp[fl[i]]) cnt--;
    if (cnt == 0 && (i - k + 1) % k1 == 0) {
      long long q = k;
      cout << k - k1 << endl;
      for (long long j = i - k; j <= i; ++j) {
        if (exp[fl[j]] > 0)
          exp[fl[j]]--;
        else if (q > k1)
          cout << j + 1 << ' ', q--;
      }
      return 0;
    }
  }
  cout << -1;
  return 0;
}
