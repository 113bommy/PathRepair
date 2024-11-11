#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n;
  string s, name;
  cin >> s;
  cin >> m;
  vector<set<int>> pos(26);
  for (int i = 0; i < n; ++i) {
    pos[s[i] - 'a'].insert(i);
  }
  for (int j = 0; j < m; ++j) {
    cin >> name;
    int curPos = -1;
    int ans = 0;
    vector<int> lastTaken(26);
    for (int i = 0; i < name.size(); ++i) {
      curPos = lastTaken[name[i] - 'a'];
      curPos = *pos[name[i] - 'a'].lower_bound(curPos);
      lastTaken[name[i] - 'a'] = curPos;
      ans = max(ans, curPos + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
