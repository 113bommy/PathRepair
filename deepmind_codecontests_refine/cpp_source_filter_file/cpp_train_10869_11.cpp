#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k = 22782196, z, h;
  cin >> t;
  int x[1000];
  for (int i = 0; i < t; ++i) {
    cin >> x[i];
  }
  for (int i = 0; i < t; ++i) {
    n = abs(x[i] - x[i + 1]);
    k = min(k, n);
    if (n == k) h = i;
  }
  z = abs(x[0] - x[t - 1]);
  if (z < k)
    cout << "1 " << t;
  else
    cout << h + 1 << " " << h + 2;
}
