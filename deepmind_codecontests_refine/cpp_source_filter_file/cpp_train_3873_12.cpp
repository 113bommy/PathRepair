#include <bits/stdc++.h>
using namespace std;
int n, a[26];
string s, t;
vector<pair<int, int>> ans;
void solve() {
  cin >> n;
  cin >> s >> t;
  ans.clear();
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
    a[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] % 2 == 1) {
      cout << "No"
           << "\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      continue;
    }
    for (int j = i; j < n; j++) {
      if (s[i] == s[j] && i != j) {
        swap(s[i], t[j]);
        ans.push_back({j + 1, i + 1});
        break;
      }
      if (s[i] == t[j]) {
        swap(s[j], t[j]);
        swap(s[j], t[i]);
        ans.push_back({j + 1, j + 1});
        ans.push_back({j + 1, i + 1});
        break;
      }
    }
  }
  if (ans.size() > 2 * n) {
    cout << "No"
         << "\n";
    return;
  }
  cout << "Yes\n" << ans.size() << "\n";
  for (auto p : ans) {
    cout << p.first << " " << p.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    solve();
  }
}
