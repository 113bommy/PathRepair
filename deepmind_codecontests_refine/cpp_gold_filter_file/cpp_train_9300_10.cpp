#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  long long n;
  cin >> n;
  long long a[2][2] = {{3, 1}, {1, 3}};
  long long r[2][2];
  long long t[2][2];
  r[0][0] = r[1][1] = 1;
  r[1][0] = r[0][1] = 0;
  while (n) {
    if (n & 1) {
      memset(t, 0, sizeof(t));
      for (int i = 0; i < (2); i++)
        for (int j = 0; j < (2); j++)
          for (int k = 0; k < (2); k++) {
            t[i][j] = (t[i][j] + r[i][k] * a[k][j]) % mod;
          }
      memcpy(r, t, sizeof(r));
    }
    n /= 2;
    memset(t, 0, sizeof(t));
    for (int i = 0; i < (2); i++)
      for (int j = 0; j < (2); j++)
        for (int k = 0; k < (2); k++) {
          t[i][j] = (t[i][j] + a[i][k] * a[k][j]) % mod;
        }
    memcpy(a, t, sizeof(a));
  }
  cout << r[0][0] << endl;
  return 0;
}
