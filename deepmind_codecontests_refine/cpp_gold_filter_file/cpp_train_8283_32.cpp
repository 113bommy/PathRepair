#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (((a xor b) and (c or d)) xor ((b and c) or (a xor d)));
  return 0;
}
