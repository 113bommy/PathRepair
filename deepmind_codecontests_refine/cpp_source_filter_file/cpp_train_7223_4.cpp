#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int r;
  cin >> n;
  char ss[111];
  cin.getline(ss, 111, '\n');
  for (int i = 0; i < n; ++i) {
    cin.getline(ss, 111, '\n');
    string s(ss);
    r = 0;
    if (s.size() >= 5) {
      if (s.substr(0, 5) == string("miao.")) {
        r += 1;
      }
      if (s.substr(s.size() - 5) == string("lala.")) {
        r += 2;
      }
    }
    switch (r) {
      case 1:
        cout << "Rainbow's\n";
        break;
      case 2:
        cout << "Freda's\n";
        break;
      default:
        cout << "OMG>.< I don't know!";
    }
  }
  return 0;
}
