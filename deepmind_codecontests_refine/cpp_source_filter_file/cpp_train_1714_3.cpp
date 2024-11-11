#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, tmp;
  cin >> a >> b >> c;
  tmp = (a + b + c) / 3;
  if (a + b < tmp) tmp = a + b;
  if (a + c < tmp) tmp = a + c;
  if (b + c < tmp) tmp = b + c;
  cout << tmp << endl;
  return 0;
}
