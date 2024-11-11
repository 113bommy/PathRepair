#include <bits/stdc++.h>
using namespace std;
bool pe = false;
string str;
int n;
int main() {
  string s;
  cin >> s;
  cin >> n;
  string se;
  int x = 0, y = 0, z = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '?')
      x++;
    else if (s[i] == '*')
      y++;
    else
      z++;
  }
  string ts;
  for (int i = 0; s[i]; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ts += s[i];
    } else if (z != n) {
      if (z < n && s[i] == '*') {
        ts += ts[ts.size() - 1];
        z++;
      } else if (z > n && (s[i] == '?' || s[i] == '*')) {
        ts.pop_back();
        z--;
      }
    }
  }
  if (ts.size() == n)
    cout << ts << endl;
  else
    cout << "Impossible" << endl;
}
