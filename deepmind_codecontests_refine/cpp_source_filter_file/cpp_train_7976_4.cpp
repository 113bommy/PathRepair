#include <bits/stdc++.h>
using namespace std;
map<string, int> MP;
int exal(string s) {
  int ln = s.size();
  int c, i1 = 0, i2 = ln - 1, x = 0;
  while (s[i1] == '&' && i1 < ln) {
    ++i1;
    c--;
  }
  while (s[i2] == '*' && i2 > -1) {
    --i2;
    c++;
  }
  string t = s.substr(i1, i2 - i1 + 1);
  if (!MP.count(t)) return -1;
  int v = MP[t];
  if (v < 0) return -1;
  v += c;
  if (v < 0) return -1;
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  int g, i;
  MP["void"] = 0;
  cin >> g;
  while (g--) {
    string t, a, b;
    cin >> t >> a;
    if (t == "typedef") {
      cin >> b;
      MP[b] = exal(a);
    } else {
      int x = exal(a);
      if (x == -1) {
        cout << "errtype" << endl;
        continue;
      } else {
        cout << "void";
        for (i = 0; i < x; i++) cout << '*';
        cout << endl;
      }
    }
  }
  return 0;
}
