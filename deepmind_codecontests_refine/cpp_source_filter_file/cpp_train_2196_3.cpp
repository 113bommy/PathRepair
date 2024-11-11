#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(228);
const int SQRT_MAXN = 100000;
const int S = 10000;
bool nprime[SQRT_MAXN], bl[S];
int primes[SQRT_MAXN], cnt;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 3e8;
  cin >> n;
  unsigned int a, b, c, d;
  cin >> a >> b >> c >> d;
  int nsqrt = (int)sqrt(n + .0);
  for (int i = 2; i <= nsqrt; ++i)
    if (!nprime[i]) {
      primes[cnt++] = i;
      if (i * 1ll * i <= nsqrt)
        for (int j = i * i; j <= nsqrt; j += i) nprime[j] = true;
    }
  int result = 0;
  unsigned int ans = 0;
  for (int k = 0, maxk = n / S; k <= maxk; ++k) {
    memset(bl, 0, sizeof bl);
    int start = k * S;
    for (int i = 0; i < cnt; ++i) {
      int start_idx = (start + primes[i] - 1) / primes[i];
      int j = max(start_idx, 2) * primes[i] - start;
      for (; j < S; j += primes[i]) bl[j] = true;
    }
    if (k == 0) bl[0] = bl[1] = true;
    for (int i = 0; i < S && start + i <= n; ++i)
      if (!bl[i]) {
        ++result;
        unsigned int deg = 0;
        unsigned int p = start + i;
        int cur = p;
        while (cur <= n) {
          deg += n / cur;
          cur *= p;
        }
        ans += deg * (a * p * p * p + b * p * p + c * p + d);
      }
  }
  cout << ans << '\n';
}
