#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, p, q, a[100001];
int main() {
  cin >> n >> k;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3 * 3;
  a[4] = 4 * 4 * 4;
  a[5] = 5 * 5 * 5 * 5;
  a[6] = 6 * 6 * 6 * 6 * 6;
  a[7] = 7 * 7 * 7 * 7 * 7 * 7;
  a[8] = 8 * 8 * 8 * 8 * 8 * 8 * 8;
  for (i = k + 1; i <= n; i++) {
    a[k] *= (n - k);
    a[k] %= 1000000007;
  }
  cout << a[k];
}
