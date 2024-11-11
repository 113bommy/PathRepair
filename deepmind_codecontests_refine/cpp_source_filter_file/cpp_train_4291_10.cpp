#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, n, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans;
  for (i = 0; i < n - 1; i++) {
    if (s[i] == 'B') {
      s[i] == 'W';
      s[i + 1] == 'W' ? (s[i + 1] = 'B') : (s[i + 1] = 'W');
      cnt++;
      ans.push_back(i);
    } else {
      continue;
    }
  }
  if (s[i] == 'W') {
    cout << cnt << endl;
    for (int u : ans) cout << u << " ";
  } else {
    for (i = 0; i < n - 1; i++) {
      if (s[i] == 'W') {
        s[i] = 'B';
        s[i + 1] == 'B' ? (s[i + 1] = 'W') : (s[i + 1] = 'B');
        cnt++;
        ans.push_back(i);
      }
    }
    if (s[i] == 'B') {
      cout << cnt << endl;
      for (int u : ans) cout << u << " ";
    } else {
      cout << -1;
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
