#include <bits/stdc++.h>
using namespace std;
long long f[52], i, j;
long long n, k, A;
int main() {
  f[1] = 1;
  f[2] = 2;
  for (i = 3; i <= 50; i++) f[i] = f[i - 2] + f[i - 1];
  cin >> n >> k;
  A = k;
  for (i = 1; i <= n; i++) {
    if (i == n) {
      cout << i << " ";
      break;
    }
    if (f[n - i] >= A)
      cout << i << " ";
    else {
      cout << i + 1 << " " << i << " ";
      A -= f[n - i];
      i++;
    }
  }
  cout << endl;
  return 0;
}
