#include <bits/stdc++.h>
using namespace std;
int clearr(int n) {
  int a = 0;
  int b = 1;
  while (n != 0) {
    if (n % 10 != 0) {
      a += a * b;
      b *= 10;
    }
    n /= 10;
  }
  return a;
}
int main() {
  int a, b, c;
  cin >> a >> b;
  c = a + b;
  a = clearr(a);
  b = clearr(b);
  c = clearr(c);
  if (a + b == c)
    cout << "YES";
  else
    cout << "NO";
}
