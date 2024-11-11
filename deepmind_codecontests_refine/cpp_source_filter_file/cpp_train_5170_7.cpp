#include <bits/stdc++.h>
using namespace std;
string w, s;
char getcase(int ind, char z) {
  if (s[ind] >= 'A' && s[ind] <= 'Z') return toupper(z);
  return tolower(z);
}
int main() {
  int n;
  cin >> n;
  vector<string> bad;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    bad.push_back(s);
  }
  char c;
  cin >> w >> c;
  s = w;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < bad.size(); j++) {
      if (i + bad[j].size() <= s.size()) {
        bool check = 1;
        for (int k = i; k < i + bad[j].size(); k++) {
          char a = s[k];
          char b = bad[j][k - i];
          a = tolower(a);
          b = tolower(b);
          if (a != b) {
            check = 0;
            break;
          }
        }
        if (check) {
          for (int k = i; k < i + bad[j].size(); k++) w[k] = '#';
        }
      }
    }
  }
  for (int i = 0; i < w.size(); i++) {
    if (w[i] == '#') {
      if (tolower(s[i]) != tolower(c))
        w[i] = getcase(i, c);
      else if (s[i] == c) {
        if (tolower(c) == 'a')
          w[i] = getcase(i, 'b');
        else
          w[i] = getcase(i, 'a');
      }
    }
  }
  cout << w << endl;
  return 0;
}
