#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c, d;
  int *b = new int();
  cin >> a >> *b >> c >> d;
  delete b;
  cout << (a && a == d || !b && a == d);
  return 0;
}
