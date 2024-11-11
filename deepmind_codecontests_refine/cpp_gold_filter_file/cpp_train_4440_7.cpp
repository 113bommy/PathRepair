#include <bits/stdc++.h>
using namespace std;
map<char, long long> check;
int main() {
  long long r, g, b;
  long long n, i, j, ans = 0;
  cin >> r >> g >> b;
  (r % 2 == 0) ? r = r / 2 : r = r / 2 + 1;
  (g % 2 == 0) ? g = g / 2 : g = g / 2 + 1;
  (b % 2 == 0) ? b = b / 2 : b = b / 2 + 1;
  long long x = max(r, max(g, b));
  if (x == b)
    cout << x + x + x + 29 << endl;
  else if (x == g)
    cout << x + x + (x - 1) + 29 << endl;
  else
    cout << x + (x - 1) + (x - 1) + 29 << endl;
  return 0;
}
