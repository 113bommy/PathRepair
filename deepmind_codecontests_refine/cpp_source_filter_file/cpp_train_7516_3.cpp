#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
long long add(long long a, long long b) { return min((1LL << 60), a + b); }
long long mul(long long a, long long b) {
  if ((1LL << 60) / a < b) return 2147483647;
  return a * b;
}
long long fac[55], dp[55];
long long g(int x) {
  if (x <= 1) return 1;
  return fac[x - 2];
}
void init() {
  fac[0] = 1;
  for (int(i) = 1; (i) <= (int)(52); (i)++) fac[i] = mul(fac[i - 1], i);
  dp[0] = 1;
  for (int(i) = 1; (i) <= (int)(50); (i)++) {
    for (int j = 1; j <= i; j++) dp[i] = add(dp[i], mul(g(j), dp[i - j]));
  }
}
int p[55], q[55];
int fd(int x) {
  while (q[x]) x = q[x];
  return x;
}
void findq(int n, long long k) {
  if (n == 1) {
    q[1] = 1;
    return;
  }
  vector<bool> vis(55, 0);
  for (int(i) = 1; (i) <= (int)(n); (i)++) q[i] = 0;
  vis[n] = 1;
  q[1] = n;
  for (int i = 2; i < n; i++) {
    long long tar = fac[n - 1 - i];
    for (int(j) = 1; (j) <= (int)(n); (j)++)
      if (!vis[j] && fd(j) != i) {
        if (tar < k)
          k -= tar;
        else {
          q[i] = j;
          vis[j] = 1;
          break;
        }
      }
  }
  for (int(j) = 1; (j) <= (int)(n); (j)++)
    if (!vis[j]) {
      q[n] = j;
      break;
    }
  return;
}
void findp(int n, long long k) {
  if (n <= 0) return;
  int len = 0;
  for (int i = 1; i <= n; i++) {
    long long tar = mul(g(i), dp[n - i]);
    if (tar < k) {
      k -= tar;
    } else {
      len = i;
      break;
    }
  }
  assert(len != 0);
  long long num = dp[n - len];
  long long cc = (k - 1) / num;
  findp(n - len, k - cc * num);
  for (int i = n; i > len; i--) {
    p[i] = p[i - len] + len;
  }
  findq(len, cc + 1);
  for (int(i) = 1; (i) <= (int)(len); (i)++) p[i] = q[i];
}
void fmain(int tid) {
  scanf("%d%lld", &n, &lk);
  if (dp[n] < lk) {
    puts("-1");
    return;
  }
  findp(n, lk);
  for (int(i) = 1; (i) <= (int)(n); (i)++) printf("%d ", p[i]);
  puts("");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  init();
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
