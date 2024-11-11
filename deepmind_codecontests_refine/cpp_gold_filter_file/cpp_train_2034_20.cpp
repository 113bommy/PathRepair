#include <bits/stdc++.h>
using namespace std;
long long i, j, m, n, p, q, r, s, l;
long double a;
int main() {
  cin >> a;
  if (a <= 127)
    cout << "byte";
  else if (a <= 32767)
    cout << "short";
  else if (a <= 2147483647)
    cout << "int";
  else if (a <= 9223372036854775807)
    cout << "long";
  else
    cout << "BigInteger";
}
