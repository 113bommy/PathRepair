#include <bits/stdc++.h>
using namespace std;
int main() {
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  string Alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  iostream::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  bool arr[4][4];
  for (long long int i = 0; i < 4; i++) {
    for (long long int j = 0; j < 4; j++) {
      arr[i][j] = false;
    }
  }
  for (long long int k = 0; k < s.length(); k++) {
    if (s[k] == '1') {
      for (long long int i = 0; i < 4; i++) {
        for (long long int j = 0; j < 3; j++) {
          if (arr[i][j] == false && arr[i][j + 1] == false) {
            arr[i][j] = true;
            arr[i][j + 1] = true;
            cout << i + 1 << " " << j + 1 << endl;
            goto link;
          }
        }
      }
    } else {
      for (long long int i = 0; i < 4; i++) {
        for (long long int j = 0; j < 3; j++) {
          if (arr[j][i] == false && arr[j + 1][i] == false) {
            arr[j][i] = true;
            arr[j + 1][i] = true;
            cout << i + 1 << " " << j + 1 << endl;
            goto link2;
          }
        }
      }
    }
  link:
  link2:
    for (long long int i = 0; i < 4; i++) {
      bool checktrue = false;
      for (long long int j = 0; j < 4; j++) {
        if (arr[i][j] == false) {
          checktrue = true;
        }
      }
      if (checktrue == false) {
        for (long long int j = 0; j < 4; j++) {
          arr[i][j] = false;
        }
      }
    }
    for (long long int i = 0; i < 4; i++) {
      bool checktrue = false;
      for (long long int j = 0; j < 4; j++) {
        if (arr[j][i] == false) {
          checktrue = true;
        }
      }
      if (checktrue == false) {
        for (long long int j = 0; j < 4; j++) {
          arr[j][i] = false;
        }
      }
    }
  }
}
