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
string direc = "URDL";
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
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
vector<int> mp[44];
int col[44];
int C, I;
bool bip = 1;
void dfs(int x, int color) {
  col[x] = color;
  for (int c : mp[x])
    if (col[c] == 0)
      dfs(c, 3 - color);
    else if (col[c] != 3 - color)
      bip = 0;
}
long long dp[(1 << 20) + 5], rdp[(1 << 20) + 5];
int to[44];
long long cal() {
  if (n == 1) return 2;
  int ln = n / 2, rn = n - ln;
  for (int(i) = 0; (i) < (int)(1 << ln); (i)++) dp[i] = 1;
  for (int(i) = 1; (i) <= (int)(ln); (i)++)
    for (int j : mp[i])
      if (j <= ln) {
        dp[(1 << (i - 1)) | (1 << (j - 1))] = 0;
      }
  for (int s = 1; s < 1 << ln; s++) {
    for (int(j) = 0; (j) < (int)(ln); (j)++)
      if (s & (1 << j)) {
        if (dp[s ^ (1 << j)] == 0) {
          dp[s] = 0;
          break;
        }
      }
  }
  int msk = (1 << ln) - 1;
  for (int(i) = 0; (i) < (int)(1 << ln); (i)++) rdp[i] = dp[i ^ msk];
  for (int j = 0; j < ln; j++) {
    for (int i = msk; i >= 0; i--) {
      if (~i & (1 << j)) {
        rdp[i] += rdp[i ^ (1 << j)];
      }
    }
  }
  for (int(i) = 0; (i) < (int)(1 << rn); (i)++) dp[i] = 1;
  for (int i = ln + 1; i <= n; i++)
    for (int j : mp[i])
      if (j > ln) {
        dp[(1 << (i - ln - 1)) | (1 << (j - ln - 1))] = 0;
      } else {
        to[i - ln - 1] |= 1 << (j - 1);
      }
  for (int s = 1; s < 1 << rn; s++) {
    for (int(j) = 0; (j) < (int)(rn); (j)++)
      if (s & (1 << j)) {
        if (dp[s ^ (1 << j)] == 0) {
          dp[s] = 0;
          break;
        }
      }
  }
  long long ans = 0;
  for (int(i) = 0; (i) < (int)(1 << rn); (i)++)
    if (dp[i]) {
      int s = 0;
      for (int(j) = 0; (j) < (int)(rn); (j)++)
        if (i & (1 << j)) s |= to[j];
      ans += rdp[s];
    }
  return ans;
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int i = 0, u, v; i < m; i++) {
    scanf("%d%d", &u, &v);
    mp[u].push_back(v);
    mp[v].push_back(u);
  };
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (col[i] == 0) {
      dfs(i, 1);
      C++;
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (mp[i].empty()) I++;
  long long all = 1LL << n;
  all -= 1LL << C;
  all += 1LL << I;
  if (bip) all += 1LL << C;
  all += 1LL << I;
  all -= m == 0 ? 1LL << n : 0;
  all -= cal() * 2;
  printf("%lld\n", all);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
