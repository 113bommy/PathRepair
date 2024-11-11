#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a == b)
    cout << a << 0;
  else {
    int small = (a > b) ? b : a;
    int large = (a > b) ? a : b;
    cout << small << " " << (large - small) / 2;
  }
  return 0;
}
