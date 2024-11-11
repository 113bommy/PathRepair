#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int a = 0, b = 0, c = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    a = i;
    while (i < s.size() && s[i] != 'a') b = i++;
    if (b != 0) break;
    if (s[i] == 'a') c++;
  }
  if (c != s.size()) {
    for (int i = a; i <= b; i++) s[i]--;
  } else
    s[s.size() - 1] = 'z';
  cout << s << endl;
  return 0;
}
