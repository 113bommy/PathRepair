#include <bits/stdc++.h>
using namespace std;
string str[100005];
int check(string s) {
  if (s.size() >= 4 && s.substr(s.size() - 4, 4) == "lios")
    return 1;
  else if (s.size() >= 5 && s.substr(s.size() - 5, 5) == "liala")
    return 2;
  else if (s.size() >= 3 && s.substr(s.size() - 3, 3) == "etr")
    return 3;
  else if (s.size() >= 4 && s.substr(s.size() - 4, 4) == "etra")
    return 4;
  else if (s.size() >= 6 && s.substr(s.size() - 6, 6) == "initis")
    return 5;
  else if (s.size() >= 6 && s.substr(s.size() - 6, 6) == "inites")
    return 6;
  else
    return 7;
}
int main() {
  int i = 0, test = 0;
  while (cin >> str[i]) {
    if (i != 0) {
      if (check(str[i]) == 1) {
        if (check(str[i - 1]) != 1) {
          cout << "NO";
          return 0;
        }
      } else if (check(str[i]) == 2) {
        if (check(str[i - 1]) != 2) {
          cout << "NO";
          return 0;
        }
      }
      if (check(str[i]) == 3) {
        if (check(str[i - 1]) != 1) {
          cout << "NO";
          return 0;
        }
        test = 1;
      } else if (check(str[i]) == 4) {
        if (check(str[i - 1]) != 2) {
          cout << "NO";
          return 0;
        }
        test = 1;
      }
      if (check(str[i]) == 5) {
        if (check(str[i - 1]) != 3 && check(str[i]) != 5) {
          cout << "NO";
          return 0;
        }
      } else if (check(str[i]) == 6) {
        if (check(str[i - 1]) != 4 && check(str[i]) != 4) {
          cout << "NO";
          return 0;
        }
      } else if (check(str[i]) == 7) {
        cout << "NO";
        return 0;
      }
    }
    if (check(str[i]) == 7) {
      cout << "NO";
      return 0;
    } else if (i == 0 && (check(str[i]) == 3 || check(str[i]) == 4))
      test = 1;
    i++;
  }
  if (i > 1 && test == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
