#include <bits/stdc++.h>
using namespace std;
string s;
string t;
int main() {
  cin >> s;
  cin >> t;
  int j = 0;
  char x = s[j];
  long long found = 0;
  long long flag1 = -1;
  long long flag2 = -1;
  long long c = 0;
  long long bo = -1;
  for (long long i = 0; i < t.length(); i++) {
    if (t[i] == x && j + 1 != s.length()) {
      x = s[++j];
    } else if (j + 1 == s.length() && t[i] == x) {
      flag1 = i;
      break;
    }
  }
  j = s.length() - 1;
  x = s[j];
  for (long long i = t.length() - 1; i >= 0; i--) {
    if (t[i] == x && j - 1 != -1) {
      x = s[--j];
    } else if (j - 1 == -1 && t[i] == x) {
      flag2 = i;
      break;
    }
  }
  if (flag2 < flag1) {
    cout << "0";
  } else {
    cout << flag2 - flag1;
  }
  return 0;
}
