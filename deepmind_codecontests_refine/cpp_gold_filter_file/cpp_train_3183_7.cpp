#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = 3.14159265359;
int n;
vector<int> v;
vector<vector<int>> cs(9);
bool works(const vector<int>& perm, const vector<int>& cts) {
  int l = 0;
  for (int i = 0; i < 8; i++) {
    int val = perm[i];
    int ct = cs[val][n - 1] - (l ? cs[val][l - 1] : 0);
    if (ct < cts[i]) return 0;
    int r = n - 1;
    int lp = l;
    while (l < r) {
      int mid = (l + r) / 2;
      ct = cs[val][mid] - (lp ? cs[val][lp - 1] : 0);
      if (ct < cts[i])
        l = mid + 1;
      else
        r = mid;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  v.resize(n);
  for (int& i : v) cin >> i;
  for (int i = 1; i <= 8; i++) {
    cs[i].resize(n);
  }
  cs[v[0]][0] = 1;
  for (int j = 1; j < n; j++) {
    for (int i = 1; i <= 8; i++) {
      cs[i][j] = cs[i][j - 1] + (v[j] == i);
    }
  }
  vector<int> perm = {1, 2, 3, 4, 5, 6, 7, 8};
  vector<int> vtemp(8);
  int ans = 0;
  do {
    int cmin = 0, cmax = 125;
    while (cmin < cmax) {
      int mid = (cmin + cmax) / 2;
      fill(vtemp.begin(), vtemp.end(), mid + 1);
      if (works(perm, vtemp))
        cmin = mid + 1;
      else
        cmax = mid;
    }
    if (ans >= 8 * cmin + 8) continue;
    for (int mask = 0; mask < (1 << 8); mask++) {
      if (ans >= 8 * cmin + __builtin_popcount(mask)) continue;
      for (int i = 0; i < 8; i++) {
        vtemp[i] = cmin + (bool)(mask & (1 << i));
      }
      if (works(perm, vtemp)) {
        ans = max(ans, 8 * cmin + __builtin_popcount(mask));
      }
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans;
  return 0;
}
