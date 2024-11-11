#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s;
  cin >> t;
  int counter = 0;
  int s_length, t_length;
  s_length = s.length();
  t_length = t.length();
  if (s_length != t_length) {
    cout << "No";
    return 0;
  } else {
    for (int i = 0; i < s_length; i++) {
      int s_int, t_int;
      s_int = s[i];
      t_int = t[i];
      if ((s_int > 122) || (s_int < 65) || ((s_int > 90) && (s_int < 97))) {
        cout << "No";
        return 0;
      }
      if ((t_int > 122) || (t_int < 65) || ((t_int > 90) && (t_int < 97))) {
        cout << "No";
        return 0;
      }
    }
    for (int i = 0; i < s_length; i++) {
      if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') ||
          (s[i] == 'u')) {
        if ((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') ||
            (t[i] == 'u'))
          counter++;
        else {
          cout << "No";
          return 0;
        }
      } else {
        if ((t[i] != 'a') && (t[i] != 'e') && (t[i] != 'i') && (t[i] != 'o') &&
            (t[i] != 'u'))
          counter++;
        else {
          cout << "No";
          return 0;
        }
      }
    }
    cout << "Yes";
    return 0;
  }
}
