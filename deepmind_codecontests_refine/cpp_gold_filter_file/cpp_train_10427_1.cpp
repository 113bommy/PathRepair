#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int prev = -1, cur = -1, num = 0;
  while (cin >> s) {
    ++num;
    prev = cur;
    cur = -1;
    if (s.length() >= 4 && s.substr(s.length() - 4, 4) == "lios") cur = 0;
    if (s.length() >= 5 && s.substr(s.length() - 5, 5) == "liala") cur = 1;
    if (s.length() >= 3 && s.substr(s.length() - 3, 3) == "etr") cur = 2;
    if (s.length() >= 4 && s.substr(s.length() - 4, 4) == "etra") cur = 3;
    if (s.length() >= 6 && s.substr(s.length() - 6, 6) == "initis") cur = 4;
    if (s.length() >= 6 && s.substr(s.length() - 6, 6) == "inites") cur = 5;
    if (cur == -1) {
      cout << "NO";
      return 0;
    }
    if (num == 2 && prev / 2 == 2) {
      cout << "NO";
      return 0;
    }
    if (prev == -1) continue;
    if (cur % 2 != prev % 2) {
      cout << "NO";
      return 0;
    }
    if (cur / 2 == 0 && prev / 2 != 0) {
      cout << "NO";
      return 0;
    }
    if (cur / 2 == 1 && prev / 2 != 0) {
      cout << "NO";
      return 0;
    }
    if (cur / 2 == 2 && prev / 2 != 1 && prev / 2 != 2) {
      cout << "NO";
      return 0;
    }
  }
  if (cur / 2 < 1 && num > 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
