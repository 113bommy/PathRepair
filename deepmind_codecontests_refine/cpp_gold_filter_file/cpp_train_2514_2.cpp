#include <bits/stdc++.h>
using namespace std;
int n, sz[20];
string str;
int main() {
  cin >> n;
  cin >> str;
  for (int i = 1; i <= 9; i++) {
    cin >> sz[i];
  }
  for (int i = 0; i < str.size(); i++) {
    if (sz[str[i] - '0'] > str[i] - '0') {
      str[i] = sz[str[i] - '0'] + '0';
      for (int j = i + 1; j < str.size(); j++) {
        if (sz[str[j] - '0'] >= str[j] - '0') {
          str[j] = sz[str[j] - '0'] + '0';
        } else {
          break;
        }
      }
      break;
    }
  }
  cout << str;
  return 0;
}
