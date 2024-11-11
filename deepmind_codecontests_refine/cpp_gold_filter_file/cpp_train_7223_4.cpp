#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s.length() >= 5) {
      if ((s.substr(0, 5) == "miao.") &&
          (s.substr(s.length() - 5, 5) != "lala."))
        cout << "Rainbow's" << endl;
      else if ((s.substr(0, 5) != "miao.") &&
               (s.substr(s.length() - 5, 5) == "lala."))
        cout << "Freda's" << endl;
      else
        cout << "OMG>.< I don't know!" << endl;
    } else
      cout << "OMG>.< I don't know!" << endl;
  }
  return 0;
}
