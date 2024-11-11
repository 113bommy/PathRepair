#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int L = 1e5 + 1;
const ll mod = ll(1e9) + 7;
const ld eps = 1e-8;
int t, n, k, m;
string s;
vector<pair<int, int>> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int q = 0; q < t; q++) {
    cin >> n >> k;
    cin >> s;
    ans.clear();
    for (int i = 0; i < k * 2; i++) {
      if (i % 2 == 0) {
        if (s[i] == ')') {
          int r = i;
          while (s[r] == ')' && r < n) {
            r++;
          }
          if (r == n - 1) {
            reverse(s.begin() + i, s.end());
          } else
            reverse(s.begin() + i, s.begin() + r + 1);
          ans.push_back({i + 1, r + 1});
        }
      } else {
        if (s[i] == '(') {
          int r = i;
          while (s[r] == '(' && r < n) {
            r++;
          }
          if (r == n - 1) {
            reverse(s.begin() + i, s.end());
          } else
            reverse(s.begin() + i, s.begin() + r + 1);
          ans.push_back({i + 1, r + 1});
        }
      }
    }
    for (int i = k * 2; i < n; i++) {
      if (i < k * 2 + (n - k * 2) / 2) {
        if (s[i] == ')') {
          int r = i;
          while (s[r] == ')' && r < n) {
            r++;
          }
          if (r == n - 1) {
            reverse(s.begin() + i, s.end());
          } else
            reverse(s.begin() + i, s.begin() + r + 1);
          ans.push_back({i + 1, r + 1});
        }
      } else
        break;
    }
    cout << (int)ans.size() << '\n';
    for (auto i : ans) {
      cout << i.first << ' ' << i.second << '\n';
    }
  }
  return 0;
}
