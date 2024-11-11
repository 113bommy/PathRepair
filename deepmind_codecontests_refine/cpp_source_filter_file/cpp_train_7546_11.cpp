#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
using namespace std;
long long int fpow(long long int a, long long int b) {
  b %= (M - 1);
  a %= M;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % M;
    }
    a = a * a % M;
    b >>= 1;
  }
  return res;
}
long long int fac[100005];
long long int inv(long long int n) {
  if (n == 1) {
    return 1;
  }
  return (M - (M / n) * inv(M % n) % M) % M;
}
long long int bc(long long int n, long long int k) {
  return fac[n] * inv(fac[k]) % M * inv(fac[n - k]) % M;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fac[0] = 1;
  for (long long int i = 0; i < 100004; i++) {
    fac[i + 1] = fac[i] * (i + 1) % M;
  }
  long long int n;
  cin >> n;
  cout << (2 * bc(2 * n - 1, n - 1) % M - n + M) % M << endl;
  return 0;
}
