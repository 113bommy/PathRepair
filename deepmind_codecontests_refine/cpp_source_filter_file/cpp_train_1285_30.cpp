#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, k, b, n, t, z = 1;
  cin >> k >> b >> n >> t;
  for (i = 0; i < n && z < t; i++) z = z * k + b;
  if (z > t) i--;
  cout << n - i << endl;
}
