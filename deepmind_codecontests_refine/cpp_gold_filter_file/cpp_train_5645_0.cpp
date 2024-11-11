#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int t;
  cin >> t;
  vector<vector<int> > vc;
  vector<int> k(26);
  int n = s.size();
  vc.push_back(k);
  for (int i = 0; i < n; i++) {
    k[s[i] - 'a']++;
    vc.push_back(k);
  }
  while (t--) {
    int x, y;
    cin >> x >> y;
    bool ok = 1;
    if (y - x == 0) {
      cout << "Yes" << endl;
      continue;
    }
    vector<int> arr(26);
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
      arr[i] = vc[y][i] - vc[x - 1][i];
      if (arr[i] == y - x + 1) {
        ok = 0;
      }
      if (arr[i] > 0) {
        cnt++;
      }
    }
    if (s[x - 1] == s[y - 1] && cnt < 3) {
      ok = 0;
    }
    cout << (!ok ? "No" : "Yes") << endl;
  }
}
