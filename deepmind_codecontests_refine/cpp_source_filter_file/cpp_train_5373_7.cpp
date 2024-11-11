#include <bits/stdc++.h>
using namespace std;
bool n[30];
int main() {
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (n[s[i]] == 0) {
      n[s[i]] = 1;
      ans++;
    }
  }
  int m;
  cin >> m;
  if (m > s.length()) {
    cout << "impossible";
    return 0;
  }
  cout << abs(m - ans);
  return 0;
}
