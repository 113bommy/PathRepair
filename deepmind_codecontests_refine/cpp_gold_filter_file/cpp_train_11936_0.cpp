#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long cnt = 1;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res % M;
}
long long a[100001], b[100001];
int main() {
  long long n, m, c1 = 0, d1 = 0, c2 = 0, d2 = 0, c = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c1 += (a[i] == 0);
    c += (a[i] == 0);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    c2 += (b[i] == 0);
    c += (b[i] == 0);
  }
  long long t = (m * (m - 1) / 2) % M;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      c1--;
      c2--;
      ans = ans +
            ((((((t * cnt) % M) * binpow(m, c1)) % M) * binpow(m, c2)) % M) % M;
      cnt = (cnt * m) % M;
    } else if (a[i] == 0) {
      c1--;
      ans = (ans + (((((((m - b[i] + M) % M) * cnt) % M) * binpow(m, c1)) % M) *
                    binpow(m, c2)) %
                       M) %
            M;
    } else if (b[i] == 0) {
      c2--;
      ans = (ans + (((((((a[i] - 1 + M) % M) * cnt) % M) * binpow(m, c1)) % M) *
                    binpow(m, c2)) %
                       M) %
            M;
    } else if (a[i] != b[i]) {
      if (a[i] > b[i]) {
        ans = (ans + (((cnt * binpow(m, c1)) % M) * binpow(m, c2)) % M) % M;
      }
      break;
    }
  }
  cout << (ans % M * binpow(binpow(m, c), M - 2) % M) % M;
  return 0;
}
