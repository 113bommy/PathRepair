#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    vector<int> res;
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> used(n);
    for (int i = 0; i <= n - 1; i++) {
      if (i + 4 < n) {
        string tmp;
        for (int j = i; j <= i + 4; j++) {
          tmp += s[j];
        }
        if (tmp == "twone") {
          res.push_back(i + 2);
          used[i + 1] = used[i + 3] = 1;
        }
      }
    }
    for (int i = 0; i <= n - 3; i++) {
      string tmp;
      for (int j = i; j <= i + 2; j++) {
        tmp += s[j];
      }
      if (tmp == "two" || tmp == "one") {
        if (!used[i + 1]) {
          res.push_back(i + 1);
        }
      }
    }
    cout << res.size() << "\n";
    for (auto i : res) cout << i + 1 << " ";
    cout << "\n";
  }
  return 0;
}
