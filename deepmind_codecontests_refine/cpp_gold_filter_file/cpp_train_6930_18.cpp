#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n > 2)
    cout << n - 2;
  else if (n == 1)
    cout << 3;
  else
    cout << 4;
  return 0;
}
