#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string pro, dom, ru, cox;
  int in;
  switch (s[0]) {
    case 'h':
      pro = s.substr(0, 4);
      pro += "://";
      in = s.find("ru");
      if (in == 4) in = s.find("ru", 5);
      dom = s.substr(4, in - 4);
      ru = s.substr(in, 2);
      ru = '.' + ru;
      cox = "";
      if (s.size() > in + 1) {
        cox = s.substr(in + 2);
        cox = '/' + cox;
      }
      cout << pro + dom + ru + cox << endl;
      break;
    case 'f':
      pro = s.substr(0, 3);
      pro += "://";
      in = s.find("ru");
      if (in == 3) in = s.find("ru", 4);
      dom = s.substr(3, in - 3);
      ru = s.substr(in, 2);
      ru = '.' + ru;
      cox = "";
      if (s.size() > in + 1) {
        cox = s.substr(in + 2);
        cox = '/' + cox;
      }
      cout << pro + dom + ru + cox << endl;
      break;
  }
  return 0;
}
