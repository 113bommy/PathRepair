#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int h = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '<') {
      if (s[i + 1] == '/') {
        h--;
        for (int i = 0; i < h; i++) {
          cout << ' ';
        }
        cout << s.substr(i, 4) << endl;
        i += 3;
      } else {
        for (int i = 0; i < h; i++) {
          cout << ' ';
        }
        cout << s.substr(i, 3) << endl;
        h++;
        i += 2;
      }
    }
  }
}
