#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1, n2;
  cin >> n;
  if (n >= 0)
    cout << n;
  else {
    n1 = n / 10;
    n2 = (n / 100) * 10;
    if (n1 > n2)
      cout << n1;
    else
      cout << n2;
  }
  return 0;
}
