#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s += '9';
  long long tc = 1;
  long long c = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (((s[i] - '0') + (s[i + 1] - '0')) == 9) {
      c++;
    } else if (c != 0) {
      if (((c % 2) == 0) && c > 1) {
        tc *= (c + 1) / 2;
      }
      c = 0;
    }
  }
  cout << tc << endl;
}
