#include <bits/stdc++.h>
using namespace std;
int x, y, n;
int f[(int)(10e6)];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> x >> y >> n;
  f[0] = x;
  f[1] = y;
  for (int i = 2; i <= 100; i++) f[i] = f[i - 1] - f[i - 2];
  cout << (f[n % 6 - 1] % (long long)(10e8 + 7) + (long long)(10e8 + 7)) %
              (long long)(10e8 + 7);
  return 0;
}
