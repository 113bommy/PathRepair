#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n;
  cin >> n;
  if (n < 128) {
    cout << "byte" << endl;
    ;
  } else if (n < 32768) {
    cout << "short" << endl;
    ;
  } else if (n < 2147483648) {
    cout << "int";
  } else if (n < 9223372036854775808) {
    cout << "long" << endl;
    ;
  } else {
    cout << "BigInteger" << endl;
  }
}
