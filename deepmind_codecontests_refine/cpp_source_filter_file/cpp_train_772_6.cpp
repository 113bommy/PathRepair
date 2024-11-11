#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e3 + 10;
bool check(string &str, int p, int n) {
  int l = p;
  int r = p + n;
  while (n--) {
    if (str[r] == '*') break;
    if (str[l++] != str[r++]) return false;
  }
  return true;
}
int main() {
  string str;
  cin >> str;
  int x;
  cin >> x;
  str += string(x, '*');
  x = (x + 1) / 2;
  int l = str.length();
  for (int n = str.length() / 2; n >= x; n--) {
    for (int i = 0; i + 2 * n < l; i++) {
      if (check(str, i, n)) {
        cout << n * 2 << endl;
        return 0;
      }
    }
  }
  return 0;
}
