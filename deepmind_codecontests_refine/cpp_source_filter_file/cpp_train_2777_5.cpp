#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 3e5 + 4;
long long fun(vector<int> &v) {
  long long val = 0;
  for (int it : v) val = 10 * val + it;
  return val;
}
int solve() {
  string s;
  cin >> s;
  long long fac[20];
  fac[0] = 1;
  for (int i = 1; i < 20; i++) fac[i] = fac[i - 1] * i;
  set<long long> st;
  vector<int> rfa(10, 0);
  int n = (int)s.size();
  for (int i = 0; i < n; i++) rfa[s[i] - '0'] = 1;
  long long ans = 0;
  for (int mask = 1; mask < 1 << n; mask++) {
    vector<int> v;
    vector<int> hfa(10, 0);
    for (int bit = 0; bit < n; bit++)
      if (mask & (1 << bit)) v.push_back(s[bit] - '0'), hfa[s[bit] - '0'] = 1;
    int cflag = 1;
    for (int i = 0; i < 10; i++)
      if (hfa[i] != rfa[i]) cflag = 0;
    if (cflag == 0) continue;
    sort(v.begin(), v.end());
    long long val = fun(v);
    if (st.find(val) != st.end()) continue;
    st.insert(val);
    vector<int> fa(10, 0);
    int nn = __builtin_popcount(mask);
    for (int it : v) fa[it]++;
    long long here = fac[nn];
    for (int i = 0; i < 10; i++) here /= fac[fa[i]];
    if (fa[0]) {
      long long subtract = fac[nn - 1] / fac[fa[0] - 1];
      for (int i = 1; i < 10; i++) subtract /= fac[fa[i]];
      here -= subtract;
    }
    ans += here;
  }
  printf("%lld\n", ans);
  return 0;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
