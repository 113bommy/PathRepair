#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a == 1)
    cout << 0 << endl;
  else {
    int b = a / 2;
    if (b % 2 == 0)
      cout << (b - 2) / 2 << endl;
    else
      cout << (b - 1) / 2 << endl;
  }
}
