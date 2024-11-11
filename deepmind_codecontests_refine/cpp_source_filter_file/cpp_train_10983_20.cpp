#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int low = 0, up = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < 93) {
      up++;
    } else {
      low++;
    }
  }
  if (low > up) {
    for (int i = 0; i < s.size(); i++) {
      s[i] = tolower(s[i]);
    }
  } else {
    for (int i = 0; i < s.size(); i++) {
      s[i] = toupper(s[i]);
    }
  }
  cout << s;
}
