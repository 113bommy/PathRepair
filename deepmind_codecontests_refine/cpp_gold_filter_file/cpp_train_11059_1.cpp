#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int j = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> b;
    b.push_back(0);
    for (int i = 0; i < int(s.size()); i++) {
      if (s[i] == 'R') {
        b.push_back(i + 1);
      }
    }
    b.push_back(s.size() + 1);
    int ans = 0;
    for (int i = 0; i < b.size() - 1; i++) {
      ans = std::max(ans, (b[i + 1] - b[i]));
    }
    cout << ans << endl;
  }
  return 0;
}
