#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x;
  cin >> x;
  if (x <= 127)
    cout << "byte";
  else if (x <= 32767)
    cout << "short";
  else if (x <= 2147483647)
    cout << "int";
  else if (x <= 9223372036854775807)
    cout << "long";
  else
    cout << "BigInteger";
  return 0;
}
