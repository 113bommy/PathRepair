#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<int> ans;
  int minans = INT_MAX;
  for (int i = 0; i < m - n + 1; i++) {
    int cura = 0;
    vector<int> cur;
    for (int j = i; j < i + n; j++) {
      if (s[j - i] != t[j]) {
        cur.push_back(j - i);
        cura++;
      }
    }
    if (cura < minans) minans = cura, ans = cur;
  }
  cout << minans << '\n';
  for (auto i : ans) cout << i + 1 << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
