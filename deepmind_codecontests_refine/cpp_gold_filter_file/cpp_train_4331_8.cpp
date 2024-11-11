#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
  static int n, ch;
  n = 0, ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
  return n;
}
const int MAX_N = 1000000 + 3;
string s, p;
void solve(int n) {
  if (n == 1) {
    s = p = "a";
  } else if (n == 2) {
    s = "aa";
    p = "a";
  } else if (n & 1) {
    solve(n >> 1);
    char newChar = 'a' + p.length();
    string a = s.substr(0, p.length()),
           b = s.substr(p.length(), s.length() - p.length());
    s = a + string(1, newChar) + b;
    s += string(2, newChar);
    p += string(1, newChar);
  } else {
    solve((n - 2) >> 1);
    char newChar = 'a' + p.length();
    string a = s.substr(0, p.length()),
           b = s.substr(p.length(), s.length() - p.length());
    s = a + string(2, newChar) + b;
    s += string(2, newChar);
    p += string(1, newChar);
  }
}
int main() {
  solve(readInt());
  cout << s << ' ' << p << endl;
  return 0;
}
