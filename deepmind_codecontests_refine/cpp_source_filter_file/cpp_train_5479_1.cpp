#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, w;
map<long long, long long> f;
long long ans = 0;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> w;
  f[w - 1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> w;
    while (f.begin() != f.end()) {
      auto it = --f.end();
      long long a = it->first, b = it->second;
      if (a < w) break;
      f.erase(it);
      f[w - 1] = max(f[w - 1], 1ll * (i - 1) * (a - a % w - w) + b);
      f[a % w] = max(f[a % w], 1ll * (i - 1) * (a - a % w) + b);
    }
  }
  for (auto x : f) ans = max(ans, 1ll * n * x.first + x.second);
  cout << ans;
  return 0;
}
