#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char a[s.size() + 5];
  if (s[0] > 90) {
    a[0] = s[0] - 32;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] < 90) {
        a[i] = s[i] + 32;
      } else {
        cout << s;
        return 0;
      }
    }
  } else {
    for (int i = 0; i < s.size(); i++) {
      {
        if (s[i] < 90) {
          a[i] = s[i] + 32;
        } else {
          cout << s;
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    cout << a[i];
  }
  return 0;
}
