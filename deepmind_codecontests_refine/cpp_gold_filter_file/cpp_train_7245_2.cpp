#include <bits/stdc++.h>
using namespace std;
bool check(vector<string> &s) {
  bool found = false;
  for (int i = 0; i < 10; i++) {
    int current = 0, j = 0;
    while (j < 10) {
      if (s[i][j] == 'X') {
        current++;
      } else {
        current = 0;
      }
      if (current == 5) found = true;
      j++;
    }
  }
  for (int i = 0; i < 10; i++) {
    int current = 0, j = 0;
    while (j < 10) {
      if (s[j][i] == 'X') {
        current++;
      } else {
        current = 0;
      }
      if (current == 5) found = true;
      j++;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int count = 0;
      for (int d = 0; d < 5; d++) {
        if (i + d < 10 and j + d < 10) {
          if (s[i + d][j + d] == 'X') count++;
        }
      }
      if (count == 5) found = true;
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int count = 0;
      for (int d = 0; d > -5; d--) {
        if (i - d < 10 and j + d >= 0) {
          if (s[i - d][j + d] == 'X') count++;
        }
      }
      if (count == 5) found = true;
    }
  }
  return found;
}
int main() {
  vector<string> s(10);
  for (int i = 0; i < 10; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (s[i][j] == '.') {
        s[i][j] = 'X';
        if (check(s)) {
          cout << "YES" << endl;
          return 0;
        }
        s[i][j] = '.';
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
