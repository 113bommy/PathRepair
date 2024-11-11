#include <bits/stdc++.h>
const int N = 1e3 + 5;
using namespace std;
string s;
void init() {
  freopen(
      "550C"
      ".inp",
      "r", stdin);
  freopen(
      "550C"
      ".out",
      "w", stdout);
}
void nhap() { getline(cin, s); }
void xuli() {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '0' || s[i] == '8') {
      cout << "YES" << endl;
      cout << s[i];
      return;
    }
    for (int j = i + 1; j < s.length(); j++) {
      int x = s[i] - '0';
      int y = s[j] - '0';
      int tam = x * 100 + y * 10;
      if (tam % 8 == 0) {
        cout << "YES" << endl;
        cout << x << y;
        return;
      }
      for (int k = j + 1; k < s.length(); k++) {
        int x = s[i] - '0';
        int y = s[j] - '0';
        int z = s[k] - '0';
        int tam = x * 100 + y * 10 + z;
        if (tam % 8 == 0) {
          cout << "YES" << endl;
          cout << x << y << z;
          return;
        }
      }
    }
  }
  cout << "NO";
}
int main() {
  nhap();
  xuli();
}
