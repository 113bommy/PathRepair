#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;
const long double PI = 2 * acos(0.0);
const long double E = 2.71828;
const long long seed = 13331;
const long long size = 500005;
int main(void) {
  int n;
  cin >> n;
  if (n == 1) cout << 1 << endl, exit(0);
  if (n == 2) cout << "2 1" << endl, exit(0);
  if (n % 3 == 0) {
    cout << 1 << " ";
    for (int i = 2; i <= n; i++)
      if (i % 2 == 0)
        cout << i + 1 << " ";
      else
        cout << i - 1 << " ";
  } else {
    cout << n << " ";
    for (int i = 2; i < n; i++)
      if (i % 2 == 0)
        cout << i + 1 << " ";
      else
        cout << i - 1 << " ";
    cout << 1 << endl;
  }
  return 0;
}
