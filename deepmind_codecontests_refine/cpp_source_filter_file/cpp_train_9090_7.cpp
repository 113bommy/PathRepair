#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> n;
  getline(cin, s);
  int ct = -100;
  int cd = 0;
  int cm = 0;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    int h = (s[1] - '0') * 10 + (s[2] - '0');
    int m = (s[4] - '0') * 10 + (s[5] - '0');
    char l = s[7];
    if (l == 'a') {
      if (h == 12) h = 0;
    } else {
      h += 12;
      if (h == 24) h = 12;
    }
    int t = h * 60 + m;
    if (t < ct || t == ct && cm == 10) {
      cd++;
      cm = 0;
    } else if (t == ct)
      cm++;
    else
      cm = 0;
    ct = t;
  }
  cout << cd + 1 << endl;
  return 0;
}
