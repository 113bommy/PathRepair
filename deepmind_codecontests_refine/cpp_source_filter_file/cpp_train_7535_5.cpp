#include <bits/stdc++.h>
using namespace std;
const int mod = 1e18 + 7;
vector<long long> pwr(50000 + 5);
void solve() {
  string s;
  long long n;
  cin >> s >> n;
  vector<string> v(n);
  vector<pair<long long, long long> > lr(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i] >> lr[i].first >> lr[i].second;
  }
  map<long long, long long> uni, each[n];
  int alp = 27;
  vector<long long> pref(s.size() + 1, 0);
  long long sz = s.size();
  for (long long j = 0; j < sz; j++) {
    pref[j + 1] = (pref[j] * alp) % mod + (s[j] - 'a' + 1);
    pref[j + 1] %= mod;
  }
  for (int j = 1; j <= sz; j++) {
    for (int xx, z = 0; z < j; z++) {
      xx = pref[j] - (pref[z] * pwr[j - z]) % mod;
      xx %= mod;
      if (xx < 0) xx += mod;
      uni[xx]++;
    }
  }
  vector<long long> subs, fre;
  while (uni.size()) {
    subs.push_back(uni.begin()->first);
    fre.push_back(uni.begin()->second);
    uni.erase(uni.begin());
  }
  for (long long i = 0; i < n; i++) {
    vector<long long> pref(v[i].size() + 1, 0);
    long long sz = v[i].size();
    for (long long j = 0; j < sz; j++) {
      pref[j + 1] = (pref[j] * alp) % mod + (v[i][j] - 'a' + 1);
      pref[j + 1] %= mod;
    }
    for (int j = 1; j <= sz; j++) {
      for (int xx, z = 0; z < j; z++) {
        xx = pref[j] - (pref[z] * pwr[j - z]) % mod;
        xx %= mod;
        if (xx < 0) xx += mod;
        each[i][xx]++;
      }
    }
  }
  long long ans = 0;
  long long nos = subs.size();
  for (long long i = 0; i < nos; i++) {
    int cnt = 0;
    for (long long val, j = 0; j < n; j++) {
      val = each[j][subs[i]];
      if (lr[j].first <= val and val <= lr[j].second) cnt++;
    }
    if (cnt == n) ans += fre[i];
  }
  cout << ans << "\n";
}
int main() {
  pwr[0] = 1;
  for (long long i = 1; i <= 50000 + 4; i++) pwr[i] = (pwr[i - 1] * 27) % mod;
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
