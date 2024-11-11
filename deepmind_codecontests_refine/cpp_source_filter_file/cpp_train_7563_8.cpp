#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  x++;
  if (x == 0)
    cout << 0;
  else if (x % 2 == 0)
    cout << x / 2;
  else
    cout << x;
  return 0;
}
