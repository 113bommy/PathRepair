#include <bits/stdc++.h>
using namespace std;
int a[20];
int main() {
  int n;
  string s, t, p;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    getline(cin, s);
    if (s.size() > 4) {
      for (int j = 0; j < 5; j++) t += s[j];
      for (int j = s.size() - 5; j < s.size(); j++) p += s[j];
      if (p == "lala." && t != "miao.")
        a[i] = 1;
      else if (p != "lala." && t == "miao.")
        a[i] = 2;
    }
    s.clear();
    t.clear();
    p.clear();
  }
  for (int i = 0; i <= n; i++) {
    if (a[i] == 0)
      cout << "OMG>.< I don't know!" << endl;
    else if (a[i] == 1)
      cout << "Freda's" << endl;
    else
      cout << "Rainbow's" << endl;
  }
}
