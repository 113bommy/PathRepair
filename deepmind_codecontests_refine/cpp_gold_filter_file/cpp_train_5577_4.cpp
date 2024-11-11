#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  b = min(b, a * 2);
  c = min(c, a + b);
  b = min(b, c * 2);
  a = min(a, b + c);
  if (n % 4 == 0)
    cout << 0;
  else if (n % 4 == 3)
    cout << a;
  else if (n % 4 == 2)
    cout << b;
  else
    cout << c;
  return 0;
}
