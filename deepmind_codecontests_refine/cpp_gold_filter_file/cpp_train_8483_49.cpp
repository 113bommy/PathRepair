#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = min(a, b);
  int d = (a ^ b ^ c) - c;
  cout << c << ' ' << d / 2 << endl;
  return 0;
}
