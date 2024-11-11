#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << b + min(a + b + 1, c) << '\n';
  return 0;
}
