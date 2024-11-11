#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 5;
int b[lim];
void solve() {
  string s;
  cin >> s;
  if (int((s).size()) < 3) {
    cout << "Just a Legend";
    return;
  }
  int i = 0, j = -1;
  b[0] = -1;
  while (i < int((s).size())) {
    while (j >= 0 && s[i] != s[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
  }
  set<int> m;
  for (int i = 1; i < int((s).size()) - 1; i++) {
    m.insert(b[i]);
  }
  i = int((s).size()) - 1;
  j = b[i];
  int ans = -1;
  while (j >= 0) {
    if (s[i] == s[j]) {
      if (m.find(j + 1) != m.end()) {
        ans = j + 1;
        break;
      }
    }
    j = b[j];
  }
  if (ans == -1) {
    cout << "Just a Legend";
  } else {
    cout << s.substr(0, ans);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1, kickstart = 0;
  for (int i = 1; i <= test; i++) {
    if (kickstart) {
      cout << "Case #" << i << ": ", solve(), cout << endl;
    } else
      solve();
  }
  return 0;
}
