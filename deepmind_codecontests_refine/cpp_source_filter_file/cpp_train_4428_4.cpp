#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, s, a;
  cin >> n;
  if (n == 0)
    cout << 1;
  else {
    s = 6 * n;
    a = n / 2 * (6 + s);
    cout << a + 1;
  }
  return 0;
}
