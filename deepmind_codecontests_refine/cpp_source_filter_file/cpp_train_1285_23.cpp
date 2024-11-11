#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, b, n, t, z = 1;
  cin >> k >> b >> n >> t;
  int i;
  for (i = -1; z <= t; i++) z = k * z + b;
  if (n - i < 0)
    cout << 0;
  else
    cout << n - i;
  return 0;
}
