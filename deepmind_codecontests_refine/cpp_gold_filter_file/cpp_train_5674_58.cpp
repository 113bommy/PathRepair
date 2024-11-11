#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = (0); i < (m); ++i) {
    vector<int> u(n);
    for (int j = (0); j < (n); ++j) cin >> u[j];
    v[i] = max_element(u.begin(), u.end()) - u.begin();
  }
  vector<int> f(n);
  for (int i = (0); i < (m); ++i) f[v[i]]++;
  int ans = max_element(f.begin(), f.end()) - f.begin();
  cout << ans + 1 << '\n';
  return 0;
}
