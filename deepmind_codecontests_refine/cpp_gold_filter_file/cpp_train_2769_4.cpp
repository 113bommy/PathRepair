#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, c = 1;
  cin >> a >> b;
  if (b < a) a = b;
  for (i = 2; i <= a; i++) c *= i;
  cout << c << endl;
}
