#include <bits/stdc++.h>
using namespace std;
string s;
char col;
long long row, kq;
int n;
int code(char x) {
  switch (x) {
    case 'f':
      return 1;
    case 'e':
      return 2;
    case 'd':
      return 3;
    case 'c':
      return 6;
    case 'b':
      return 5;
    case 'a':
      return 4;
  }
}
int main() {
  getline(cin, s);
  n = s.length();
  col = s[n - 1];
  s.erase(n - 1, 1);
  n--;
  row = 0;
  for (int i = 0; i <= n - 1; i++) row = row * 10 + (s[i] - '0');
  kq = 0;
  long long tmp = (row - 1) / 4;
  kq = tmp * 13 + (tmp - 1) * 3 + 3;
  row = row - tmp * 4;
  if (row % 2 == 1) kq = kq + code(col);
  if (row % 2 == 0) kq = kq + 7 + code(col);
  cout << kq;
}
