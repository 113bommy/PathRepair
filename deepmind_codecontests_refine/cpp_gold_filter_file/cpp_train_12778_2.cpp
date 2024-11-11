#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setiosflags(ios::fixed) << setprecision(10);
  srand(time(NULL));
  int a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  int m = max(2, min(50, *max_element(a, a + 4)));
  vector<string> ans;
  for (int k = 0; k < 4; k++) {
    int islands = a[(k + 1) % 4] - 1;
    string s(m, 'A' + k);
    vector<pair<int, int>> pos;
    ans.push_back(s);
    for (int x = 0; x < (islands + (m - 2)) / (m - 1); x++) {
      for (int i = 0; i < 3; i++) {
        ans.push_back(s);
      }
      for (int i = (x & 1); i < m - !(x & 1); i++) {
        pos.push_back({(int)ans.size() - 2 - ((i ^ x) & 1), i});
      }
    }
    random_shuffle(pos.begin(), pos.end());
    for (int i = 0; i < islands; i++) {
      ans[pos[i].first][pos[i].second] = 'A' + (k + 1) % 4;
    }
  }
  int sz = ans.size();
  if (sz <= m) {
    cout << sz << ' ' << m << '\n';
    for (string s : ans) {
      cout << s << '\n';
    }
  } else {
    cout << m << ' ' << sz << '\n';
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < sz; j++) {
        cout << ans[j][i];
      }
      cout << '\n';
    }
  }
  return 0;
}
