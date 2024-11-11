#include <bits/stdc++.h>
using namespace std;
int n, p;
string s, ans;
bool is_valid(int i, string &s, int c) {
  return (i - 2 < 0 || s[i - 2] - 'a' != c) &&
         (i - 1 < 0 || s[i - 1] - 'a' != c);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> p >> s;
  for (int i = n - 1; i >= 0; --i) {
    for (int c1 = 0; c1 < p; ++c1) {
      if (s[i] - 'a' < c1 && is_valid(i, s, c1)) {
        ans = s.substr(0, i) + string(1, c1 + 'a');
        for (int j = i + 1; j < n; ++j) {
          for (int c2 = 0; c2 < p; ++c2) {
            if (is_valid(j, ans, c2)) {
              ans.push_back(c2 + 'a');
              break;
            }
          }
        }
        cout << ans << "\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
