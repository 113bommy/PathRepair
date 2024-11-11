#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int min;
  if (a < b)
    min = a;
  else
    min = b;
  int remaining = (a + b) - (2 * min);
  cout << min << " " << remaining % 2;
}
