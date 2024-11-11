#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k;
string s;
void solve() {
  cin >> n >> k;
  cin >> s;
  vector<char> ans(n);
  int have = 0;
  vector<pair<int, int> > ops;
  int idx = 0;
  while (idx < n) {
    int inc = 0;
    if (have != k - 1) {
      ans[idx] = '(';
      ans[idx + 1] = ')';
      inc = 2;
    } else {
      int len = n - idx;
      for (int i = idx; i < idx + len; i++) {
        ans[i] = '(';
      }
      for (int i = idx + len; i < n; i++) {
        ans[i] = ')';
      }
      inc = 2 * len;
    }
    ++have;
    idx += inc;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != ans[i]) {
      for (int j = i + 1; j < n; j++) {
        if (s[j] == ans[i]) {
          swap(s[i], s[j]);
          ops.push_back({i, j});
          break;
        }
      }
    }
  }
  cout << ops.size() << endl;
  for (int i = 0; i < ops.size(); i++) {
    cout << ops[i].first << " " << ops[i].second << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
