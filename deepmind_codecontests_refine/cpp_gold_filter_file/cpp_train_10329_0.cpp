#include <bits/stdc++.h>
using namespace std;
const long long NN = 3e5 + 5;
long long a[NN];
long long x[NN];
long long F[NN];
long long cek(long long aa) {
  long long H = 0, k = 0;
  for (long long i = 1; i <= aa; i++) a[i] = i;
  do {
    k++;
    H = 0;
    for (long long i = 1; i <= aa; i++) {
      long long mi = 1e18;
      long long ma = -1e18;
      for (long long j = i; j <= aa; j++) {
        mi = min(mi, a[j]);
        ma = max(ma, a[j]);
        if ((ma - mi) == (j - i)) x[j - i + 1]++;
      }
    }
  } while (next_permutation(a + 1, a + 1 + aa));
  for (long long i = 1; i <= 150; i++)
    if (x[i]) cout << i << " " << x[i] << "\n";
  return H;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, has = 0;
  cin >> n >> m;
  F[0] = 1;
  for (long long i = 1; i <= n; i++) F[i] = (F[i - 1] * i) % m;
  for (long long i = 1; i <= n; i++) {
    long long hz = ((n - i + 1) * F[i]) % m;
    hz = (hz * F[n - i + 1]) % m;
    has = (has + hz) % m;
  }
  cout << has << "\n";
}
