#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
int t;
int n, k;
string second;
vector<pair<int, int> > ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (int _ = 0; _ < (signed)(t); _++) {
    cin >> n >> k >> second;
    --k;
    for (int i = 0; i < (signed)(n); i++) {
      char c;
      if (i / 2 < k) {
        c = i % 2 ? ')' : '(';
      } else {
        if (i == 2 * k || i == n - 1) {
          c = i % 2 ? ')' : '(';
        } else {
          c = i % 2 ? '(' : ')';
        }
      }
      if (second[i] == c) continue;
      for (int j = (i + 1); j <= (signed)(n - 1); j++) {
        if (second[j] == c) {
          ans.push_back({i, j});
          int l = i, r = j;
          while (l < r) {
            swap(second[l], second[r]);
            l++;
            r--;
          }
          break;
        }
      }
    }
    cout << ans.size() << "\n";
    for (auto u : ans) {
      cout << u.first + 1 << " " << u.second + 1 << "\n";
    }
    ans.clear();
  }
  return 0;
}
