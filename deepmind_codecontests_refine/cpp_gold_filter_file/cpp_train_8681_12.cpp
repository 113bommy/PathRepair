#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int col[N], row[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<pair<int, int> > ans1, ans2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != 'E' && !col[j]) {
        ans1.emplace_back(1 + i, 1 + j);
        ++col[j];
      }
    }
    for (int j = 0; j < n; ++j) {
      if (s[j][i] != 'E' && !row[j]) {
        ans2.emplace_back(j + 1, i + 1);
        ++row[j];
      }
    }
  }
  if (ans1.size() >= n) {
    for (auto i : ans1) cout << i.first << " " << i.second << endl;
  } else if (ans2.size() >= n) {
    for (auto i : ans2) cout << i.first << " " << i.second << endl;
  } else {
    cout << "-1";
  }
}
