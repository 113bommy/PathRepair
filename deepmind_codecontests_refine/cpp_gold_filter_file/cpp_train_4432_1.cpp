#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  long long n, m, x = 0;
  cin >> n >> c;
  if (int(c) <= int('c'))
    m = int(c) - int('a') + 4;
  else
    m = int('f') - int(c) + 1;
  x += (((n - 1) / 4) * 12) + (4 * ((n - 1) / 4));
  if (n % 2 == 0) x += 7;
  cout << x + m;
}
