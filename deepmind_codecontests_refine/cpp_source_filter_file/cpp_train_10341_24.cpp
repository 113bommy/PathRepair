#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000009;
int n, i, j, k;
long long f[1000011];
int main() {
  cin >> n;
  n /= 2;
  f[2] = 1;
  for (i = 3; i <= n; i++) f[i] = (2 * (f[i - 1] + 2)) % maxn;
  for (i = n; i >= 3; i--) f[i] = (f[i + 1] + 4) * (f[i] + 1) % maxn;
  f[2] = f[3] + 4;
  if (n == 1) f[2] = 0;
  cout << 2 * ((f[2] + 2) * (f[2] + 2) + 1) % maxn;
  return 0;
}
