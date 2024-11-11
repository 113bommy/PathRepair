#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = 0;
  int y = 0;
  x = n / 10;
  int u = n % 10;
  y = x * 10 + u;
  cout << max(x, max(y, n)) << "\n";
  return 0;
}
