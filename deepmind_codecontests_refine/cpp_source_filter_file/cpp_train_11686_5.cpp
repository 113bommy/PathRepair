#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
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
string direc = "RDLU";
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
char s[(2135)], t[(2135)];
int S[(2135)][26], T[(2135)][26];
int dp[(2135)][(2135)];
int cal(int i, int j) {
  if (i == 0) return 0;
  int& tmp = dp[i][j];
  if (tmp != (1 << 30)) return tmp;
  int num = t[j] - 'a';
  if (i + 1 <= n && j + 1 <= n) {
    if (S[i + 1][num] > T[j + 1][num]) {
      mintt(tmp, cal(i, j - 1));
    }
  }
  if (s[i] == t[j]) mintt(tmp, cal(i - 1, j - 1));
  mintt(tmp, cal(i - 1, j) + 1);
  return tmp;
};
void fmain(int tid) {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  vector<int> c(26, 0);
  for (int(i) = 1; (i) <= (int)(n); (i)++) c[s[i] - 'a']++;
  for (int(i) = 1; (i) <= (int)(n); (i)++) c[t[i] - 'a']--;
  for (int(j) = 0; (j) < (int)(26); (j)++)
    if (c[j] != 0) {
      puts("-1");
      return;
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(n); (j)++) dp[i][j] = (1 << 30);
  for (int(j) = 0; (j) < (int)(26); (j)++) {
    S[n + 1][j] = T[n + 1][j] = 0;
  }
  for (int i = n; i; i--) {
    for (int(j) = 0; (j) < (int)(26); (j)++) {
      S[i][j] += S[i + 1][j];
      T[i][j] += T[i + 1][j];
    }
    S[i][s[i] - 'a']++;
    T[i][t[i] - 'a']++;
  }
  printf("%d\n", cal(n, n));
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
