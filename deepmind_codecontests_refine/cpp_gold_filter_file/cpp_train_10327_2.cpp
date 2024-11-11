#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
      if (s[i] == t[i]) {
        continue;
      }
      p.push_back(i);
      if (p.size() == 3) {
        break;
      }
    }
    bool r = p.size() == 0;
    if (p.size() == 2) {
      if (s[p[0]] == s[p[1]] && t[p[1]] == t[p[0]]) {
        r = true;
      }
    }
    cout << (r ? "Yes" : "No") << endl;
  }
  return 0;
}
