#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long s, n, k, i, j, x, ss;
  vector<long long> f, ans;
  cin >> s >> k;
  f.push_back(1);
  ss = 1;
  while (f[f.size() - 1] <= s) {
    f.push_back(ss);
    ss += ss;
    if (f.size() > k) ss -= f[f.size() - k - 1];
  }
  for (i = f.size() - 1; i >= 0; i--) {
    if (s >= f[i]) {
      ans.push_back(f[i]);
      s -= f[i];
    }
  }
  if (ans.size() < 2) ans.push_back(0);
  cout << ans.size() << "\n";
  for (auto p : ans) cout << p << " ";
  cout << "\n";
  return 0;
}
