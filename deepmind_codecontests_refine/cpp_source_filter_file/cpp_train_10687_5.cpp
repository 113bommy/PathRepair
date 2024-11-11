#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, t;
  cin >> a >> t;
  for (int i = 1; i <= t; i++)
    if (a % 10 == 0)
      a = a / 10;
    else if (a / 10 != 0)
      a = a - 1;
  cout << a;
}
