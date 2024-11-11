#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[3030], res[3030], s2[3030], s1[3030];
  for (int i = 0; i < m; i++) {
    cin >> s1[i] >> s2[i];
    if (s1[i].size() > s2[i].size()) {
      res[i] = s2[i];
    } else
      res[i] = s1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i] == s1[j] || s[i] == s2[j]) {
        s[i] = res[j];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << s[i] << " ";
  return 0;
}
