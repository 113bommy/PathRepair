#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
const int N = 1e6 + 100;
const int M = 1e9 + 7;
inline int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (1ll * res * a) % M;
    }
    a = (1ll * a * a) % M;
    b >>= 1;
  }
  return res;
}
inline int inv(int x) { return power(x, M - 2); }
int q[N], c[N], fact[N], ifact[N];
inline int isPrime(int n) {
  int ans = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (n % (i * i) == 0) {
        return 0;
      }
      n /= i;
      ans ^= 1;
    }
  }
  if (n > 1) {
    ans ^= 1;
  }
  return ans ? -1 : 1;
}
vector<pair<int, int>> primes;
void precalc() {
  for (int i = 2; i < N; i++) {
    int r = isPrime(i);
    if (r == 0) {
      continue;
    }
    primes.push_back(make_pair(i, r));
  }
  for (int i = 1; i < N; i++) {
    q[i] = (q[i] + i) % M;
    for (auto j : primes) {
      if (i * j.first > N) {
        break;
      }
      q[i * j.first] = (q[i * j.first] + ((i * j.second + M) % M)) % M;
    }
  }
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % M;
    ifact[i] = inv(fact[i]);
  }
}
int n, k, m;
int cnt[N];
int ans = 0;
void precalc2() {
  for (int i = 0; i < N; i++) {
    if (i < k) {
      c[i] = 0;
    } else {
      c[i] = (((1ll * fact[i] * ifact[k]) % M) * ifact[i - k]) % M;
    }
  }
}
inline void add2(int x) {
  ans = (ans - ((1ll * c[cnt[x]] * q[x]) % M) + M) % M;
  cnt[x]++;
  ans = (ans + 1ll * c[cnt[x]] * q[x]) % M;
}
inline void add(int x) {
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      add2(i);
      if (i * i != x) {
        add2(x / i);
      }
    }
  }
}
int main() {
  precalc();
  cin >> n >> k >> m;
  precalc2();
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    add(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    add(x);
    printf("%d\n", ans);
  }
  return 0;
}
