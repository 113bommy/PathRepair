#include <bits/stdc++.h>
using namespace std;
int main() {
  long double s;
  cin >> s;
  if (s <= 127) {
    cout << "byte";
    return 0;
  } else if (s <= 32767) {
    cout << "short";
    return 0;
  } else if (s <= 2147483647) {
    cout << "int";
    return 0;
  } else if (s <= 9223372036854775807) {
    cout << "long";
    return 0;
  } else
    cout << "BigInteger";
  return 0;
}
