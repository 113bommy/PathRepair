#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, m = 50, p = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    s[i] += s[i];
  }
  for (int i = 0; i < n; i++) {
    c = 0;
    string a = s[i].substr(0, s[i].size() / 2);
    for (int j = 0; j < n; j++) {
      if (s[j].find(a) > s[j].size() / 2) {
        p = 1;
        break;
      } else
        c += s[j].find(a);
    }
    if (p) break;
    m = min(m, c);
  }
  cout << ((p) ? -1 : m);
  return 0;
}
