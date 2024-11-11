#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  int x = (a + b) / n;
  while ((((a / x + b / x)) < n) || a < x || b < x) x--;
  cout << x;
  return 0;
}
