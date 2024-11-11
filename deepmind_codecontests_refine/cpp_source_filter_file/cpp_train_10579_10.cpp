#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 10000010, LOG = 20;
long long n, m, k, u, v, x, y, t, c1, c2, c3, ans;
int sieve[MAXN];
int phi[MAXN];
int ps[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve[1] = phi[1] = 1;
  for (int i = 2; i < MAXN; i++)
    if (!sieve[i])
      for (int j = i; j < MAXN; j += i)
        if (!sieve[j]) sieve[j] = i;
  for (int i = 2; i < MAXN; i++) {
    int p = sieve[i], tmp = i / p;
    if (tmp % p)
      phi[i] = (p - 1) * phi[tmp];
    else
      phi[i] = p * phi[tmp];
  }
  cin >> n;
  for (int i = 2; i <= n; i++) {
    c1 += i - phi[i] - 1;
    if (sieve[i] == i && 2 * i > n) t++;
  }
  t = n - t - 1;
  c3 = t * (t - 1) / 2;
  for (int i = 2; i <= n; i++) ps[sieve[i]]++;
  for (int i = 2; i <= n; i++) ps[i] += ps[i - 1];
  for (int i = 2; i <= n; i++) c2 += ps[n / sieve[i]];
  for (int i = 2; i <= n; i++)
    if (sieve[i] * sieve[i] <= n) c2--;
  c2 /= 2;
  c2 -= c1;
  c3 -= c1 + c2;
  cout << c1 + 2 * c2 + 3 * c3 << '\n';
  return 0;
}
