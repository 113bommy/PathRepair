#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
map<pair<long long, long long>, long long> cnt_p;
signed main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  long long bad = 0;
  cin >> n;
  long long cnt_f[n + 1], cnt_s[n + 1];
  memset(cnt_f, 0, sizeof(cnt_f));
  memset(cnt_s, 0, sizeof(cnt_s));
  long long fact[n + 1];
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % M;
  }
  pair<long long, long long> a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    cnt_f[a[i].first]++;
    cnt_s[a[i].second]++;
    cnt_p[a[i]]++;
  }
  long long bad_1 = 1, bad_2 = 1, bad_3 = 1;
  for (long long i = 0; i <= n; i++) {
    bad_1 = (bad_1 * fact[cnt_f[i]]) % M;
    bad_2 = (bad_2 * fact[cnt_s[i]]) % M;
  }
  for (auto elem : cnt_p) {
    bad_3 = (bad_3 * fact[elem.second]) % M;
  }
  sort(a, a + n);
  for (long long i = 1; i < n; i++) {
    if (a[i].second < a[i - 1].second) {
      bad_3 = 0;
      break;
    }
  }
  bad = (bad_1 + bad_2 - bad_3) % M;
  if (bad < 0) bad += M;
  long long res = (fact[n] - bad) % M;
  if (res < 0) res += M;
  cout << res << endl;
  return 0;
}
