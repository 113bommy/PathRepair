#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1164777216")
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double pi = acos(-1.0), eps = 1e-15;
const int INF = 1000 * 1000 * 1000 + 5, MAXN = 100005, MOD = 1000007;
const long long INFL = 1000000000000000005;
void prepare(string s) {
  if ((int)s.size() != 0) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
int n, a[2 * MAXN], sum = 0;
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if ((sum - a[i]) % (n - 1) == 0)
      if ((sum - a[i]) / (n - 1) == a[i]) ans.push_back(i + 1);
  }
  cout << (int)ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << ' ';
}
int main() {
  prepare("");
  srand(time(NULL));
  solve();
  return 0;
}
