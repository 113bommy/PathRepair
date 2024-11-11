#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (((a xor b) and (c xor d)) xor ((b and c) xor (a xor d)));
  return 0;
}
