#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
long long a[1000000];
long long b[1000000];
long long d[1000000];
int main() {
  d[0] = 1;
  for (int i = 1; i < 1000000; i++) d[i] = (d[i - 1] * 2) % mod;
  int n;
  long long ans = 0;
  cin >> n;
  if (n == 1)
    ans = 1;
  else if (n == 2)
    ans = 5;
  else {
    ans = 1;
    b[1] = 1;
    for (int i = 2; i < n; i++) {
      if (i % 2 == 0 && i > 2) {
        if (i != n - 1) {
          a[i] = (4 * (d[i / 2 - 1] - 1)) % mod;
        } else {
          a[i] = (i / 2 + 1);
        }
        b[i] = (b[i - 1] * a[i]) % mod;
      } else
        b[i] = b[i - 1];
      ans = (ans + 2 * b[i]) % mod;
    }
    cerr << ans << endl;
    ans = (ans + ans + ans * ans) % mod;
    ans += 2;
  }
  cout << (2 * ans) % mod;
  return 0;
}
