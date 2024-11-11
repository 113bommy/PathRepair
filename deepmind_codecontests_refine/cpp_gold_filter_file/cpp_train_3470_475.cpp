#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  if (d == 5)
    cout << 1;
  else
    cout << (d % 3) + 1;
  return 0;
}
