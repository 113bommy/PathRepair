#include <bits/stdc++.h>
#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
#pragma gcc optimize("O3")
#pragma gcc optimize("abm,mmx,avx,avx2,unroll-loops,fast-math,section-anchors")
#pragma GCC target("avx,avx2")
const long long inf = 1e18, mod = 1e9 + 9, N = 400000;
const int k = 320, mil = 102300;
const long double pi = acos(-1);
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long s = 0, ret = 0;
  map<long long, long long> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (m.end() == m.find(a[i])) m[a[i]] = 0;
    m[a[i]]++;
    s += a[i];
  }
  s *= 2;
  if (s % n != 0) {
    cout << "0\n";
    return;
  }
  s /= n;
  for (auto [x, y] : m) {
    if (x != s - x)
      ret += y * m[s - x];
    else
      ret += y * (y - 1);
  }
  cout << ret / 2 << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
