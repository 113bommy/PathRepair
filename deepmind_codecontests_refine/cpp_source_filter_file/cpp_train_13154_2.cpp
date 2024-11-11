#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, f = 0, b;
  string a;
  cin >> a;
  b = a.size();
  for (int i = 0; i < b - 1; ++i) {
    for (int j = i + 1; j < b; ++j) {
      if (a.at(i) == a.at(j)) {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      c = c + 1;
      f = 0;
    }
  }
  c = b - c;
  if (c % 2 == 0) cout << "CHAT WITH HER!";
  if (c % 2 != 0) cout << "IGNORE HIM";
  return 0;
}
