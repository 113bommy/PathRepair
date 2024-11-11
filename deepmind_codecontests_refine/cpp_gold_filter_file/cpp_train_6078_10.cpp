#include <bits/stdc++.h>
using namespace std;
long long l[20000];
long long res, p, i, k, n, j;
int main() {
  cin >> n >> k;
  l[1] = 1;
  l[2] = 2;
  l[3] = 9;
  l[4] = 64;
  l[5] = 625;
  l[6] = 7776;
  l[7] = 49 * 49 * 49;
  l[8] = 64 * 64 * 64 * 8;
  for (i = k + 1; i <= n; i++) {
    l[k] = l[k] * (n - k);
    l[k] %= 1000000007;
  }
  cout << l[k] << endl;
}
