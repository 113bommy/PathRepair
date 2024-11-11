#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int qt[3];
  memset(qt, 0, sizeof(qt));
  int atual = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '|') {
      qt[atual]++;
    }
    if (s[i] == '+') {
      atual = 1;
    }
    if (s[i] == '=') {
      atual = 2;
    }
  }
  for (int i = 0; i < 3; i++) {
  }
  if (qt[0] + qt[1] - qt[2] == 2) {
    if (qt[0] > 1) {
      for (int i = 0; i < qt[0] - 1; i++) {
        cout << "|";
      }
      cout << "+";
      for (int i = 0; i < qt[1]; i++) {
        cout << "|";
      }
      cout << "=";
      for (int i = 0; i < qt[2] + 1; i++) {
        cout << "|";
      }
      cout << endl;
    } else if (qt[1] > 1) {
      for (int i = 0; i < qt[0]; i++) {
        cout << "|";
      }
      cout << "+";
      for (int i = 0; i < qt[1] - 1; i++) {
        cout << "|";
      }
      cout << "=";
      for (int i = 0; i < qt[2] + 1; i++) {
        cout << "|";
      }
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  } else if (qt[0] + qt[1] - qt[2] == -2) {
    if (qt[2] > 1) {
      for (int i = 0; i < qt[0] + 1; i++) {
        cout << "|";
      }
      cout << "+";
      for (int i = 0; i < qt[1]; i++) {
        cout << "|";
      }
      cout << "=";
      for (int i = 0; i < qt[2] - 1; i++) {
        cout << "|";
      }
      cout << endl;
    } else {
      cout << "impossible" << endl;
    }
  } else if (abs(qt[0] + qt[1] - qt[2]) == 0) {
    for (int i = 0; i < s.size(); i++) {
      cout << s[i];
    }
    cout << endl;
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}
