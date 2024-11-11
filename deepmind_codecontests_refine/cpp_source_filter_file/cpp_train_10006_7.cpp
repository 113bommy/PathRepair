#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  for (x = 4; x < n + 4; x++)
    cout << (x / 4) * ((x & 2) ? 1 : -1) * (x & 1) << ' '
         << x / 4 * ((x & 2) ? 1 : -1) * !(x & 1) << endl;
}
