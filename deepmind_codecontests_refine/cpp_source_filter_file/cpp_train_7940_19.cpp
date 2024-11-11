#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
const long long MOD = (long long)(1e9 + 7);
int modk(int k, int x) { return ((x % k) + k) % k; }
int b[500000 + 5], idx[500000 + 5];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (int)n; ++i) cin >> b[i + 1];
  b[0] = -200000000;
  b[n + 1] = 200000000;
  for (int i = 0; i < (int)n + 2; ++i) b[i] -= i;
  idx[0] = 0;
  for (int i = 0; i < (int)k; ++i) cin >> idx[i + 1];
  idx[k + 1] = n + 1;
  int ans = 0;
  for (int i = 0; i < (int)k + 1; ++i) {
    int l = idx[i], r = idx[i + 1];
    if (b[l] > b[r]) {
      cout << "-1";
      return;
    }
    vector<int> lis;
    for (int j = l + 1; j < r; ++j) {
      int numcur = b[j];
      if (b[l] <= numcur && numcur <= b[r]) {
        auto pos = upper_bound(lis.begin(), lis.end(), numcur);
        if (pos == lis.end())
          lis.push_back(numcur);
        else
          (*pos) = numcur;
      }
    }
    ans += (r - l - 1) - int(lis.size());
  }
  cout << ans;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
