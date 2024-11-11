#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size();
  int n1 = 0, n2 = 0;
  for (int i = 0; i < n; i++) {
    n1 += s1[i] == s2[i];
    n2 += s1[i] != s2[i];
  }
  if (n2 % 2 == 0) {
    string ans = s1;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (idx % 2 == 0) ans[i] = s2[i];
        idx++;
      }
    }
    cout << ans;
  } else
    cout << "impossible";
  return 0;
}
