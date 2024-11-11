#include <bits/stdc++.h>
using namespace std;
long long int a[1000], b[1000];
long long int i, j, k, n;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    b[i] = b[i - 1] ^ b[i];
  }
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) {
      if (i > 1) {
        if ((b[j] ^ b[i - 1]) > k) k = b[j] ^ b[i - 1];
      } else if (b[j] > k)
        k = a[j];
    }
  if (a[n] > k) k = a[i];
  cout << k;
  return 0;
}
