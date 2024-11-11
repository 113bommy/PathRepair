#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned n, m;
  cin >> n >> m;
  if (n % 2 != 0 && m % 2 != 0)
    cout << ((m * n) - 1) / 2;
  else
    cout << (m * n) / 2;
  return 0;
}
