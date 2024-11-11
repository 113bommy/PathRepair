#include <bits/stdc++.h>
using namespace std;
map<char, int> vis;
int main() {
  string s;
  cin >> s;
  vis['a'] = 1;
  vis['e'] = 1;
  vis['o'] = 1;
  vis['u'] = 1;
  vis['i'] = 1;
  int len = s.length();
  int x = 0;
  for (int i = 0; i < len; i++) {
    if (vis[s[i]])
      x = 0;
    else
      x++;
    if (x > 2 && s[i] != s[i - 1] || s[i - 1] != s[i - 2]) {
      printf(" ");
      x = 1;
    }
    cout << s[i];
  }
  cout << endl;
  return 0;
}
