#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long a, b, n, s;
  cin >> n;
  n++;
  a = 0;
  b = 0 + 6 * (n - 1);
  s = (a + b) / 2 * n;
  cout << s + 1;
}
