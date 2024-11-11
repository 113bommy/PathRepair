#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline void read(int &x) {
  char c = getchar();
  x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}
const int N = 3e5;
const int maxn = N + 10;
const int mo = 1e9 + 7;
int T, n, Ans, p[maxn], pos[maxn], cnt[maxn], fac[maxn];
int primes, prime[maxn], Real[maxn];
bool vis[maxn];
void init() {
  int i, j;
  for (i = 2; i <= N; i++) {
    if (!vis[i]) {
      Real[i] = i;
      prime[++primes] = i;
    }
    for (j = 1; j <= primes && i * prime[j] <= N; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j])
        Real[i * prime[j]] = Real[i] * prime[j];
      else {
        Real[i * prime[j]] = Real[i];
        break;
      }
    }
  }
  fac[0] = 1;
  for (i = 1; i <= N; i++) fac[i] = (long long)fac[i - 1] * i % mo;
}
void solve() {
  int i, j;
  bool flag1 = 0;
  read(n);
  memset(cnt, 0, sizeof(cnt));
  memset(pos, 0, sizeof(pos));
  for (i = 1; i <= n; i++) {
    read(p[i]);
    pos[p[i]] = i;
    flag1 |= p[i] == 1;
    cnt[Real[i]]++;
    cnt[Real[p[i]]]--;
  }
  Ans = 1;
  for (i = 1; i <= n; i++) Ans = (long long)Ans * fac[cnt[i]] % mo;
  memset(cnt, 0, sizeof(cnt));
  cnt[1] = !flag1;
  for (i = 1; i <= primes && prime[i] <= n; i++) {
    int d = 0;
    for (j = 1; prime[i] * j <= n; j++) d = gcd(d, p[prime[i] * j]);
    if (prime[i] * 2 <= n && d == 1) {
      puts("0");
      return;
    }
    if ((long long)prime[i] * prime[i] <= n && d % prime[i]) {
      puts("0");
      return;
    }
    d = 0;
    for (j = 1; prime[i] * j <= n; j++) d = gcd(d, pos[prime[i] * j]);
    if (prime[i] * 2 <= n && d == 1) {
      puts("0");
      return;
    }
    if ((long long)prime[i] * prime[i] <= n && d % prime[i]) {
      puts("0");
      return;
    }
    if ((long long)prime[i] * prime[i] > n && d == 0) {
      cnt[n / prime[i]]++;
    }
  }
  for (i = 1; i <= n; i++) Ans = (long long)Ans * fac[cnt[i]] % mo;
  printf("%d\n", Ans);
}
int main() {
  init();
  T = 1;
  while (T--) {
    solve();
  }
}
