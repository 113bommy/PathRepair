#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1)
    cout << 1;
  else if (k == 2)
    cout << n * (n - 1) / 2 + 1;
  else if (k == 3)
    cout << n * 1LL * (n - 1) * (n - 2) / 3 + n * (n - 1) / 2 + 1;
  else
    cout << n * 1LL * (n - 1) * (n - 2) * (n - 3) / 24 * 9 +
                n * 1LL * (n - 1) * (n - 2) / 3 + n * (n - 1) / 2 + 1;
  return 0;
}
