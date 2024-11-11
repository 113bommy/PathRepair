#include <bits/stdc++.h>
using namespace std;
string s;
long long x, d;
int main() {
  cin >> s;
  if (s.size() < 3) {
    cout << "byte";
  } else if (s.size() == 3) {
    d = 1;
    x = 0;
    for (int i = 2; i > -1; i--) {
      x += d * (s[i] - '0');
      d *= 10;
    }
    if (x <= 127)
      cout << "byte";
    else
      cout << "short";
  } else if (s.size() < 5) {
    cout << "short";
  } else if (s.size() == 5) {
    d = 1;
    x = 0;
    for (int i = 4; i > -1; i--) {
      x += d * (s[i] - '0');
      d *= 10;
    }
    if (x <= 32767)
      cout << "short";
    else
      cout << "int";
  } else if (s.size() < 10) {
    cout << "int";
  } else if (s.size() == 10) {
    d = 1;
    x = 0;
    for (int i = 9; i > -1; i--) {
      x += d * (s[i] - '0');
      d *= 10;
    }
    if (x <= 2147483647)
      cout << "int";
    else
      cout << "long";
  } else if (s.size() < 19) {
    cout << "long";
  } else if (s.size() == 19) {
    d = 1;
    x = 0;
    for (int i = 18; i > -1; i--) {
      x += d * (s[i] - '0');
      d *= 10;
    }
    if (x <= 9223372036854775807 && x > 1e17)
      cout << "long";
    else
      cout << "BigInteger";
  } else
    cout << "BigInteger";
  return 0;
}
