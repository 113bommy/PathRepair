#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long f1[1000001], f2[1000001], f3[1000001], g[1000001];
long long muy[1000001], prime[1000001], pre[1000001];
bool cmps[1000001];
void sieve() {
  int k = 0;
  for (int i = 2; i < 1000001; i++)
    if (!cmps[i]) {
      prime[k++] = i;
      for (int j = i; j < 1000001; j += i) {
        pre[j] = i;
        cmps[j] = 1;
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  sieve();
  muy[1] = 1;
  for (int i = 2; i < 1000001; ++i) {
    long long j = i, pow = 1;
    int deg = 0;
    while (j % pre[i] == 0) {
      deg++, pow = pow * pre[i];
      j /= pre[i];
    }
    pow /= pre[i];
    muy[i] = muy[j] * pow * (pre[i] + deg * (pre[i] - 1));
  }
  for (long long i = 1; i < 1000001; i = i + 1) {
    g[i] =
        (i * (i + 1) * (2 * i + 1) / 3 - 3 * i * i + 2 * muy[i]) % 1000000007;
    f1[i] = (f1[i - 1] + g[i]) % 1000000007;
    f2[i] = (f2[i - 1] + g[i] * i) % 1000000007;
    f3[i] = (f3[i - 1] + g[i] * (i * i % 1000000007)) % 1000000007;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n > m) swap(n, m);
    m++, n++;
    long long ans =
        ((((m * n % 1000000007) * f1[n - 1] - (m + n) * f2[n - 1] + f3[n - 1]) %
          1000000007) +
         1000000007) %
        1000000007;
    cout << ans;
  }
}
