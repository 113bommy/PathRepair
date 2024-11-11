#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string code;
  cin >> code;
  for (int k = 0; k < code.length(); k++) {
    for (int j = 1; j < code.length(); j++) {
      int cnt = 0;
      for (int i = 0; i < code.length(); i++) {
        if (k + j * i < code.length() && code[k + j * i] == '*') {
          cnt++;
        }
        if (k + j * i < code.length() && code[k + j * i] == '.') {
          cnt = 0;
        }
        if (cnt >= 4) {
          cout << "yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "no" << endl;
}
