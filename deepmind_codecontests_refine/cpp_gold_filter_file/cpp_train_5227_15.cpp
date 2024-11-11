#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<pair<int, int>> ans;
  for (int i = 0; i < 2 * k - 2; i += 2) {
    if (s[i] != '(') {
      for (int j = i; j < n; ++j) {
        if (s[j] == '(') {
          ans.emplace_back(i + 1, j + 1);
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
    }
    if (s[i + 1] != ')') {
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == ')') {
          ans.emplace_back(i + 2, j + 1);
          reverse(s.begin() + i + 1, s.begin() + j + 1);
          break;
        }
      }
    }
  }
  for (int i = 2 * k - 2; i < n; ++i) {
    char need;
    if (i - 2 * k + 2 < n - 1 - i) {
      need = '(';
    } else {
      need = ')';
    }
    if (s[i] != need) {
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == need) {
          ans.emplace_back(i + 1, j + 1);
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto [a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
