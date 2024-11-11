#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  map<long long, long long> pref, suf;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++pref[v[i]];
  }
  long long ans = 0;
  for (int i = v.size() - 1; i >= 0; --i) {
    --pref[v[i]];
    if (v[i] % k == 0) ans += pref[v[i] / k] * suf[1LL * v[i] * k];
    ++suf[v[i]];
  }
  cout << ans << '\n';
  return 0;
}
