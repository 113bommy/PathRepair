#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, x = 0, y = 0;
  string s[10001];
  s[0] = "aeiou";
  s[1] = "uaeio";
  s[2] = "ouaei";
  s[3] = "iouae";
  s[4] = "eioua";
  cin >> n;
  for (i = 5; i <= n / 5; i++) {
    if (n % i == 0) {
      y = i;
      x = n / i;
      break;
    }
  }
  if (x < 5 || y < 5)
    cout << "-1" << endl;
  else {
    for (i = 5; i < x; i++) s[i] = "aeiou";
    for (i = 5; i < y; i++) s[0] += "a";
    for (i = 5; i < y; i++) s[1] += "e";
    for (i = 5; i < y; i++) s[2] += "i";
    for (i = 5; i < y; i++) s[3] += "o";
    for (i = 5; i < y; i++) s[4] += "u";
    for (i = 5; i < x; i++) {
      for (j = 5; j < y; j++) s[i] += "a";
    }
    for (i = 0; i < x; i++) cout << s[i];
  }
  return 0;
}
