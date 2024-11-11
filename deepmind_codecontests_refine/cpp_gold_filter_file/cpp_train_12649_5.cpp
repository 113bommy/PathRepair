#include <bits/stdc++.h>
using namespace std;
unsigned long long int ara[200000];
int main() {
  unsigned long long int n, i, z, q, z1, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> ara[i];
  }
  q = 2147483647;
  sort(ara, ara + n);
  k = (n - 2) >> 1;
  if (n > 2) {
    for (i = 0; i <= k; i++) {
      z = ara[n - 1 - k + i] - ara[i];
      if (z < q) q = z;
    }
    cout << q;
  } else {
    z1 = ara[1] - ara[0];
    cout << z1;
  }
  return 0;
}
