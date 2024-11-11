#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n == 8)
    cout << "vaporeon";
  else if (n == 6)
    cout << "espeon";
  else if (s[0] != '.')
    switch (s[0]) {
      case 'j':
        cout << "jolteon";
        return 0;
      case ('f'):
        cout << "flareon";
        return 0;
      case ('u'):
        cout << "umbreon";
        return 0;
      case ('l'):
        cout << "leafeon";
        return 0;
      case ('g'):
        cout << "glaceon";
        return 0;
      case ('s'):
        cout << "sylveon";
        return 0;
    }
  else if (s[1] != '.')
    switch (s[1]) {
      case 'o':
        cout << "jolteon";
        return 0;
      case ('m'):
        cout << "umbreon";
        return 0;
      case ('e'):
        cout << "leafeon";
        return 0;
      case ('y'):
        cout << "sylveon";
        return 0;
      case 'l':
        if (s[0] == 'f' || s[3] == 'r') {
          cout << "flareon";
          return 0;
        } else {
          cout << "glaceon";
          return 0;
        }
    }
  else if (s[2] != '.')
    switch (s[2]) {
      case ('b'):
        cout << "umbreon";
        return 0;
      case 'l':
        if (s[0] == 'j' || s[1] == 'o' || s[3] == 't') {
          cout << "jolteon";
          return 0;
        } else {
          "sylveon";
          return 0;
        }
      case 'a':
        if (s[0] == 'l' || s[1] == 'e' || s[3] == 'f') {
          cout << "leafeon";
          return 0;
        } else if (s[0] == 'f' || s[3] == 'r') {
          cout << "flareon";
          return 0;
        } else {
          cout << "glaceon";
          return 0;
        }
    }
  else if (s[3] != '.')
    switch (s[3]) {
      case 't':
        cout << "jolteon";
        return 0;
      case ('f'):
        cout << "leafeon";
        return 0;
      case ('c'):
        cout << "glaceon";
        return 0;
      case ('v'):
        cout << "sylveon";
        return 0;
      case 'r':
        if (s[0] == 'f' || s[1] == 'l' || s[2] == 'a') {
          cout << "flareon";
          return 0;
        } else {
          cout << "umbreon";
          return 0;
        }
    }
  return 0;
}
