#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
long long min(long long a, long long b) {
  if (a > b) return a;
  return b;
}
bool isNum(char ch) {
  if (ch <= '9' && ch >= '0') {
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m, i, j, k, l, t;
  long long w, x, y, z;
  long long row, col;
  cin >> t;
  while (t--) {
    string s, r = "";
    cin >> s;
    n = s.length();
    w = 0;
    x = 0;
    z = 0;
    for (i = 1; i < n; i++) {
      if (isNum(s[i]) && !isNum(s[i - 1])) {
        w++;
        x = i;
      }
    }
    row = 0;
    col = 0;
    if (w == 1) {
      for (i = x; i < n; i++) {
        y = s[i] - '0';
        row *= 10;
        row += y;
      }
      for (i = 0; i < x; i++) {
        y = s[i] - 'A' + 1;
        col *= 26;
        col += y;
      }
      cout << 'R' << row << 'C' << col << endl;
    }
    if (w == 2) {
      char ch;
      for (i = 1; i < x - 1; i++) {
        y = s[i] - '0';
        row *= 10;
        row += y;
      }
      for (i = x; i < n; i++) {
        y = s[i] - '0';
        col *= 10;
        col += y;
      }
      while (col > 0) {
        w = col % 26;
        x = col / 26;
        if (w == 0) {
          w = 26;
          x--;
        }
        col /= 26;
        ch = 'A' + w - 1;
        r = ch + r;
      }
      cout << r << row << endl;
    }
  }
}
