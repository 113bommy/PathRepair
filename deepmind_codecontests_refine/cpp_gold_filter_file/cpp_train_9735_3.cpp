#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void si(T &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c<48 | c> 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modinverse(long long a, long long M) { return bigmod(a, M - 2, M); }
void io() { freopen("/Users/MyMac/Desktop/in.txt", "r", stdin); }
const int N = 1e6 + 6;
long long nxt[N];
const long long MOD = 1e9 + 7;
bool vis[N];
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  dfs(nxt[u]);
}
int main() {
  long long p, k;
  cin >> p >> k;
  if (k == 0) {
    long long ans = 1;
    for (int i = 0; i < p - 1; i++) {
      ans *= p;
      ans %= MOD;
    }
    cout << ans << endl;
    return 0;
  }
  if (k == 1) {
    long long ans = 1;
    for (int i = 0; i < p; i++) {
      ans *= p;
      ans %= MOD;
    }
    cout << ans << endl;
    return 0;
  }
  for (long long i = 0; i < p; i++) {
    nxt[i * k % p] = i;
  }
  long long ans = 1;
  for (int i = 1; i < p; i++) {
    if (vis[i] == 0) {
      dfs(i);
      ans *= p;
      ans %= MOD;
    }
  }
  printf("%lld\n", ans);
}
