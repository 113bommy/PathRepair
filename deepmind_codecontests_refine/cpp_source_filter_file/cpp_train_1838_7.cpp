#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint linf = 1e18 + 7;
const lint inf = 1e9 + 7;
const int MOD = 1000000007;
vector<lint> f;
lint k;
void rec(lint p) {
  if (p < k && p >= 1) return;
  if (p > 0) {
    f.push_back(-p / k);
    rec(-p / k);
  } else {
    f.push_back((-p + k - 1) / k);
    rec((-p + k - 1) / k);
  }
}
signed main() {
  lint p;
  cin >> p >> k;
  if (p < k) {
    cout << -1 << "\n";
    return 0;
  }
  rec(p);
  vector<lint> res(f.size() + 5, 0);
  int n = f.size();
  res[0] = p;
  for (int i = 0; i < n; ++i) {
    res[i] += f[i] * k;
    res[i + 1] += f[i];
  }
  cout << n + 1 << "\n";
  for (int i = 0; i < n + 1; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
  return 0;
}
