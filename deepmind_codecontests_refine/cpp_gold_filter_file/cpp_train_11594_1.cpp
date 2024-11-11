#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const int INFi = 0x7f7f7f7f;
long long test = 1, second, k;
vector<long long> v, ans;
void init() {
  v.push_back(1);
  long long i = 0, j = 0, res = 1;
  while (res <= second) {
    v.push_back(res);
    j += 1;
    res += v[j];
    if (j >= k) {
      res -= v[i];
      i += 1;
    }
  }
}
void solve() {
  cin >> second >> k;
  init();
  while (second > 0) {
    auto it = upper_bound(v.begin(), v.end(), second);
    it--;
    ans.push_back(*it);
    second -= *it;
  }
  ans.push_back(0);
  cout << ans.size() << " "
       << "\n";
  for (auto it : ans) cout << it << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
