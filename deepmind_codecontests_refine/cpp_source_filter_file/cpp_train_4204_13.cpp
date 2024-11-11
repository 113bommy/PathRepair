#include <bits/stdc++.h>
using namespace std;
int i, j, n, x[101], sum, maxi;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] = x[i] ^ x[i - 1];
  }
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      sum = x[i] ^ x[j + 1];
      maxi = max(maxi, sum);
    }
  }
  cout << maxi;
  return 0;
}
