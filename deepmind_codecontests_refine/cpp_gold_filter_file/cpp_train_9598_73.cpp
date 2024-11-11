#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  cout << ((a + b < n) ? (b + 1) : (n - a));
  return 0;
}
