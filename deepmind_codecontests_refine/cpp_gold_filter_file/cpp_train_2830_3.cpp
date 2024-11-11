#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
using pii = pair<int, int>;
int N;
string s, t;
vector<pii> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> s >> t;
  for (int i = 0, j = 0; i < N; ++i) {
    if (s[i] == t[i]) continue;
    for (j = i + 1; j < N; ++j) {
      if (s[j] != t[j] && s[i] == s[j]) {
        ans.emplace_back(i, j);
        swap(s[i], t[j]);
        j++;
        break;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    if (s[i] == t[i]) continue;
    for (int j = i + 1; j < N; ++j) {
      if (s[j] != t[j]) {
        ans.emplace_back(j, j);
        swap(s[j], t[j]);
        ans.emplace_back(i, j);
        swap(s[i], t[j]);
        i = j;
        break;
      }
    }
  }
  if (s == t) {
    cout << ans.size() << "\n";
    for (auto& [i, j] : ans) cout << i + 1 << " " << j + 1 << "\n";
  } else
    cout << -1;
}
