#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  string result = s;
  int lens = t.length();
  int i = 0;
  while (s[i] == t[i] && i < lens) {
    i++;
  }
  bool found = false;
  if (t[i] - s[i] > 1) {
    result[i] = char(s[i] + 1);
    found = true;
  } else if (i < lens - 1 && s[i + 1] != 'z') {
    result[i] = s[i];
    result[i + 1] = 'z';
    found = true;
  } else if (i < lens - 1) {
    result[i] = t[i];
    i++;
    while (t[i] == 'a' && i < lens) {
      result[i] = t[i];
      i++;
    }
    if (i < lens) {
      result[i] = char(t[i] - 1);
      found = true;
    }
  }
  if (found) {
    cout << result;
  } else {
    cout << "No such string";
  }
  return 0;
}
