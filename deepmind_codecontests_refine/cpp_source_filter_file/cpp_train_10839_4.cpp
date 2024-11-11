#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long a[1000] = {0};
  long long b[1000] = {0};
  long long k[1000] = {0};
  for (int i = 0; i < t; i++) {
    cin >> a[i] >> b[i] >> k[i];
  }
  for (int i = 0; i < t; i++) {
    if (k[i] % 2 == 0)
      cout << k[i] / 2ll * (a[i] - b[i]) << endl;
    else
      cout << (k[i] - 1ll) / 2ll * (a[i] - b[i]) + a << endl;
  }
  return 0;
}
