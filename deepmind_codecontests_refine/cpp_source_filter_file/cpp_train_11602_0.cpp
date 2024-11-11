#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
const int INF = 1000000000 + 7;
string s[maxn];
set<char> vis;
int main() {
  int n;
  while (scanf("%d%d", &n) != EOF) {
    for (int i = 0; i < n; i++) cin >> s[i];
    int m = s[1].length();
    string ans = "";
    for (int i = 0; i < m; i++) {
      vis.clear();
      for (int j = 0; j < n; j++) {
        if (s[j][i] == '?') continue;
        vis.insert(s[j][i]);
      }
      if (vis.size() > 1) {
        ans.push_back('?');
      } else if (vis.size() == 1) {
        ans.push_back(*vis.begin());
      } else {
        ans.push_back('a');
      }
    }
    cout << ans << endl;
  }
  return 0;
}
