#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 3 == 0)
    cout << 1 << " " << 1 << " " << n - 2;
  else if (n % 3 == 1)
    cout << 1 << " " << 2 << " " << n - 3;
  else
    cout << 2 << " " << 2 << " " << n - 4;
  return 0;
}
