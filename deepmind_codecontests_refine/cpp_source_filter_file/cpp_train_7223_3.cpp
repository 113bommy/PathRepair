#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  string s;
  getline(cin, s);
  while (tt--) {
    getline(cin, s);
    int n = s.size();
    int q = n - 5;
    int p = n - 1;
    if (n < 5) {
      cout << "OMG>.< I don't know!\n";
      continue;
    }
    if (s.substr(q, p) == "lala." && s.substr(0, 5) == "miao.") {
      cout << "OMG>.< I don't know!\n";
      continue;
    } else if (s.substr(q, p) == "lala.") {
      cout << "Freda's\n";
      continue;
    } else if (s.substr(0, 5) == "miao.") {
      cout << "Rainbow's\n";
      continue;
    } else {
      cout << "OMG>.< I don't know!\n";
      continue;
    }
  }
}
