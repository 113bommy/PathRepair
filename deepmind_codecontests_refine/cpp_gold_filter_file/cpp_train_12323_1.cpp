#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (cin >> s) {
    int flag = 1;
    for (int i = 0; i < 7; i++) {
      if (s[i] == s[i + 1]) flag = 0;
    }
    for (int i = 0; i < 7; i++) {
      cin >> s;
      for (int j = 0; j < 7; j++) {
        if (s[j] == s[j + 1]) flag = 0;
      }
    }
    if (flag == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
