#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0;
  cin >> a >> b;
  c += min(a, b);
  a -= c;
  b -= c;
  cout << c << " ";
  c = 0;
  c += (a + b) / 2;
  cout << c << endl;
  return 0;
}
