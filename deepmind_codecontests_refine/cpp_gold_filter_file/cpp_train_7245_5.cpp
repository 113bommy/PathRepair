#include <bits/stdc++.h>
using namespace std;
char table[20][20];
bool check() {
  bool res = false;
  for (int i = 0; i < 10 && !res; i++) {
    for (int j = 0; j + 5 <= 10 && !res; j++) {
      bool cur = true;
      for (int k = 0; k < 5 && cur; k++) {
        cur = cur && (table[i][j + k] == 'X');
      }
      if (cur) res = true;
    }
  }
  for (int i = 0; i + 5 <= 10 && !res; i++) {
    for (int j = 0; j < 10 && !res; j++) {
      bool cur = true;
      for (int k = 0; k < 5 && cur; k++) {
        cur = cur && (table[i + k][j] == 'X');
      }
      if (cur) res = true;
    }
  }
  for (int i = 0; i + 5 <= 10 && !res; i++) {
    for (int j = 0; j + 5 <= 10 && !res; j++) {
      bool cur = true;
      for (int k = 0; k < 5 && cur; k++) {
        cur = cur && (table[i + k][j + k] == 'X');
      }
      if (cur) res = true;
    }
  }
  for (int i = 4; i < 10 && !res; i++) {
    for (int j = 0; j + 5 <= 10 && !res; j++) {
      bool cur = true;
      for (int k = 0; k < 5 && cur; k++) {
        cur = cur && (table[i - k][j + k] == 'X');
      }
      if (cur) res = true;
    }
  }
  return res;
}
int main() {
  for (int i = 0; i < 10; i++) cin >> table[i];
  bool ans = false;
  for (int i = 0; i < 10 && !ans; i++) {
    for (int j = 0; j < 10 && !ans; j++) {
      if (table[i][j] == '.') {
        table[i][j] = 'X';
        ans = ans || check();
        table[i][j] = '.';
      }
    }
  }
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
