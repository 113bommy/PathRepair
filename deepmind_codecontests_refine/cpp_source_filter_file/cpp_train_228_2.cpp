#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long mod = 1000000009;
const long long maxn = 200005;
void std_quick_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long cot[maxn][26];
int main() {
  std_quick_io();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < n + 4; j++) {
        cot[i][j] = 0;
      }
    }
    string s;
    cin >> s;
    vector<long long> res(m);
    for (int i = 0; i < m; i++) {
      cin >> res[i];
      res[i]--;
    }
    res.push_back(n - 1);
    cot[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        if (s[i] - 'a' == j) {
          cot[i][j] = cot[i - 1][j] + 1LL;
        } else {
          cot[i][j] = cot[i - 1][j];
        }
      }
    }
    vector<long long> ans(26, 0);
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j <= m; j++) {
        ans[i] += cot[res[j]][i];
      }
    }
    for (int i = 0; i < 26; i++) {
      if (i != 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
