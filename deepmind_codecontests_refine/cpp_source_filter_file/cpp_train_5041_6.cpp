#include <bits/stdc++.h>
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
const int N = 1e6 + 9;
const int M = 2e3 + 9;
const int INFINT = 1e9 + 9;
const long long INFLL = 1e18 + 9;
const long long MOD = (long long)(1000000007);
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
void solve() {
  string s;
  cin >> s;
  vector<vector<int>> cnt((int)(s.size()) + 1, vector<int>(27, INFINT));
  for (int i = (int)(int)(s.size()) - 1; i >= 0; --i) {
    for (int j = 0; j < (int)26; ++j) {
      cnt[i][j] = cnt[i + 1][j];
    }
    cnt[i][s[i] - 'a'] = i;
  }
  int d = 0;
  vector<int> ans(26, 0);
  for (int i = 0; i < (int)(int)(s.size()); ++i) {
    sort(cnt[i].begin(), cnt[i].end());
    for (int j = 0; j < (int)26; ++j) {
      d = max(d, j + 1);
      if (cnt[i][j + 1] == INFINT) {
        ans[j] += (int)(s.size()) - cnt[i][j];
        break;
      }
      ans[j] += cnt[i][j + 1] - cnt[i][j];
    }
  }
  cout << d << endl;
  for (int i = 0; i < (int)d; ++i) cout << ans[i] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
