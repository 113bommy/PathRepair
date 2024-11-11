#include <bits/stdc++.h>
using namespace std;
int main() {
  char c1[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
  char c2[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'};
  char c3[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
  char c;
  cin >> c;
  string s;
  cin >> s;
  if (c == 'R') {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < sizeof(c1); j++) {
        if (s[i] == c1[j]) {
          cout << c1[j - 1];
          break;
        }
      }
      for (int j = 0; j < sizeof(c2); j++) {
        if (s[i] == c2[j]) {
          cout << c2[j - 1];
          break;
        }
      }
      for (int j = 0; j < sizeof(c3); j++) {
        if (s[i] == c3[j]) {
          cout << c3[j - 1];
          break;
        }
      }
    }
  } else if (c == 'L') {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < sizeof(c1); j++) {
        if (s[i] == c1[j]) {
          cout << c1[j + 1];
          break;
        }
      }
      for (int j = 0; j < sizeof(c2); j++) {
        if (s[i] == c2[j]) {
          cout << c2[j + 1];
          break;
        }
      }
      for (int j = 0; j < sizeof(c3); j++) {
        if (s[i] == c3[j]) {
          cout << c3[j + 1];
          break;
        }
      }
    }
  }
}
