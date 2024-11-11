#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  int k = 0, e = 0, b = 0;
  for (int i = 0; i < 6; i++) {
    cin >> p;
    s += p;
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < 2; i++) {
    if (s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3]) {
      s.erase(i, 4);
      k = 1;
    }
  }
  if (k == 0) {
    cout << "Alien";
    return 0;
  }
  if (s[0] != s[1]) {
    b = 1;
  }
  if (s[0] == s[1]) {
    e = 1;
  }
  if (e == 1 && b == 0) {
    cout << "Elephant";
  }
  if (e == 0 && b == 1) {
    cout << "Bear";
  }
  if (e == 1 && b == 1) {
    cout << "Alien";
  }
  return 0;
}
