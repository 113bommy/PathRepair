#include <bits/stdc++.h>
using namespace std;
const int rx[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int cy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int n, p;
bool chk(string &s) {
  int n = (int)(s.size());
  for (int x = 0; x < n; x++) {
    if ((x - 1 >= 0 && s[x - 1] == s[x]) || (x + 1 < n && s[x + 1] == s[x]) ||
        (x - 2 >= 0 && s[x - 2] == s[x]) || (x + 2 < n && s[x + 2] == s[x]))
      return false;
  }
  return true;
}
int main() {
  cin >> n >> p;
  string s;
  cin >> s;
  int x = n - 1;
  while (1) {
    s[x]++;
    if (s[x] - 'a' == p) {
      x--;
      if (x < 0) {
        cout << "NO" << endl;
        return 0;
      }
    } else {
      if (!((x - 1 >= 0 && s[x - 1] == s[x]) ||
            (x - 2 >= 0 && s[x - 2] == s[x])))
        break;
    }
  }
  x++;
  while (x < n) {
    s[x] = 'a';
    int f = 1;
    for (int i = 0; i < p; i++) {
      s[x] = s[x] + i;
      if (((x - 1 >= 0 && s[x - 1] == s[x]) ||
           (x - 2 >= 0 && s[x - 2] == s[x])))
        continue;
      f = 0;
      break;
    }
    if (f) {
      cout << "NO" << endl;
      return 0;
    }
    x++;
  }
  cout << s << endl;
  return 0;
}
