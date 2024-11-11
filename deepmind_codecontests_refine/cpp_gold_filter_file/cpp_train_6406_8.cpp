#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
bool dp2[maxn], dp3[maxn];
string s;
set<string> Set;
int main() {
  cin >> s;
  int l = s.length() - 5;
  reverse(s.begin(), s.end());
  if (l >= 2) dp2[2] = true;
  if (l >= 3) dp3[3] = true;
  for (int i = 4; i <= l; i++) {
    if (dp2[i - 2] && s.substr(i - 4, 2) != s.substr(i - 2, 2)) dp2[i] = true;
    if (!dp2[i] && dp3[i - 2]) dp2[i] = true;
    if (dp3[i - 3] && s.substr(i - 6, 3) != s.substr(i - 3, 3)) dp3[i] = true;
    if (!dp3[i] && dp2[i - 3]) dp3[i] = true;
  }
  for (int i = 2; i <= l; i++) {
    string t;
    if (dp2[i]) {
      t = s.substr(i - 2, 2);
      reverse(t.begin(), t.end());
      Set.insert(t);
    };
    if (dp3[i]) {
      t = s.substr(i - 3, 3);
      reverse(t.begin(), t.end());
      Set.insert(t);
    };
  }
  cout << Set.size() << endl;
  for (string t : Set) cout << t << endl;
  return 0;
}
