#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  if ((m % 2 == 0) && (n % 2 == 0))
    cout << ((m * n) / 2) - 1;
  else
    cout << m * n / 2;
}
