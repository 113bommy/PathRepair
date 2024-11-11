#include <bits/stdc++.h>
using namespace std;
const int limit = 4;
const int base = 1e4;
const int maxn = 3e5;
const int mod = 1e9 + 7;
int n;
int A[maxn + 8], B[maxn + 8];
char S[base + 8];
vector<int> dp[maxn + 8];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
struct Bignum {
  int v[base + 8], len;
  void readin() {
    scanf("%s", S + 1);
    for (int i = strlen(S + 1); i > 0; i -= 4) {
      int tim = 1;
      for (int j = 0; j < 4; j++) {
        if (i - j < 1) break;
        v[len] += (S[i - j] - '0') * tim, tim *= 10;
      }
      len++;
    }
  }
  int div(int x) {
    long long tmp = 0;
    for (int i = len - 1; ~i; i--) {
      tmp = tmp * base + v[i];
      v[i] = tmp / x;
      tmp %= x;
    }
    while (v[len - 1] == 0 && len > 1) len--;
    return tmp;
  }
} M;
void solve() {
  dp[0].push_back(1);
  for (int i = 1; i <= n; i++) {
    int siz = dp[i - 1].size(), f = 0, rest = 0;
    if (A[i + 1] != 1) rest = M.div(A[i + 1]);
    for (int j = 0; j < siz + B[i]; j++) {
      if (j < siz) f = (f + dp[i - 1][j]) % mod;
      if (j > B[i]) f = (f - dp[i - 1][j - B[i] - 1] + mod) % mod;
      if (rest == j % A[i + 1]) dp[i].push_back(f);
    }
  }
  printf("%d\n", M.len != 1 || dp[n].empty() ? 0 : dp[n][0]);
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) A[i] = read();
  A[n + 1] = maxn + 8;
  for (int i = 1; i <= n; i++) B[i] = read();
  M.readin();
  solve();
  return 0;
}
