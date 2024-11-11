#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & 1 && n >= 2)
    n = (n - 2) / 2 + 1;
  else if (n >= 2)
    n = (n - 2) / 2;
  else if (n == 1)
    n = 0;
  cout << n << "\n";
  return 0;
}
