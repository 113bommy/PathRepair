#include <bits/stdc++.h>
using namespace std;
long long c, t, n, I;
int main(void) {
  cin >> n;
  for (int i = int(1), ni = int(n); i <= ni; i++) cin >> t, c += (t == 1);
  for (long long I1 = 1, I2 = 1, i = 2; i <= c; i++)
    I = (I1 + I2 * (i - 1) % 1000000007) % 1000000007, I2 = I1, I1 = I;
  for (int i = int(c + 1), ni = int(n); i <= ni; i++) I = (I * i) % 1000000007;
  cout << I;
  return 0;
}
