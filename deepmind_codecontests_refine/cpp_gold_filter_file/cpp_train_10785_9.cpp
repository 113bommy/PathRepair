#include <bits/stdc++.h>
using namespace std;
vector<long long int> vct, key;
int main() {
  int n, k;
  long long int p, mx, ans = 1e18;
  cin >> n >> k >> p;
  vct.resize(n);
  key.resize(k);
  for (auto &i : vct) cin >> i;
  for (auto &i : key) cin >> i;
  sort(vct.begin(), vct.end());
  sort(key.begin(), key.end());
  for (int i = 0; i < k - n + 1; ++i) {
    mx = 0;
    for (int j = 0; j < n; ++j) {
      mx = max(mx, abs(key[j + i] - vct[j]) + abs(key[j + i] - p));
    }
    ans = min(ans, mx);
  }
  cout << ans << endl;
}
