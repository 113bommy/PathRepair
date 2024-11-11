#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main() {
  cin >> n;
  if (n % 2 == 0) {
    a = n + 4;
    b = 4;
    cout << a << " " << b;
    return 0;
  }
  a = n + 9;
  b = 9;
  cout << a << " " << b;
  return 0;
}
