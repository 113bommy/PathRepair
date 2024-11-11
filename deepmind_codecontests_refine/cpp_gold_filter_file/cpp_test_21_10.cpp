#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void Read(T &x) {
  x = 0;
  char c;
  long long dau = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') dau = -1;
  do {
    x = x * 10 + c - '0';
  } while (isdigit(c = getchar()));
  x *= dau;
}
long long read() {
  long long tmp;
  cin >> tmp;
  return tmp;
}
void giuncute() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void OF() {
  if (fopen("f"
            ".inp",
            "r")) {
    freopen(
        "f"
        ".inp",
        "r", stdin);
    freopen(
        "f"
        ".out",
        "w", stdout);
  } else if (fopen("f"
                   ".in",
                   "r")) {
    freopen(
        "f"
        ".in",
        "r", stdin);
    freopen(
        "f"
        ".out",
        "w", stdout);
  }
}
const long long mxn = 107;
long long dp[mxn][mxn][mxn], n, m, k, MOD, cnk[mxn][mxn] = {{0}}, p[mxn];
inline long long sol(long long len, long long ma, long long cnt) {
  if (cnt > len || cnt < 0) return 0;
  if (ma < 0 || ma > len) return (cnt ? 0 : p[len]);
  long long &cur = dp[len][ma][cnt];
  if (!len) return cur = !cnt;
  if (len == 1) return cur = (ma == 1 ? (cnt == 1) : (cnt == 0));
  if (~cur) return cur;
  cur = 0;
  for (long long i = 1; i <= (len + 1) / 2; ++i) {
    for (long long ncnt = 0; ncnt <= min(i - 1, cnt); ++ncnt)
      (cur += (1 + (i + i <= len)) * cnk[len - 1][i - 1] *
              ((sol(i - 1, ma - 1, ncnt) *
                sol(len - i, ma - 1, cnt - ncnt - (ma == 1))) %
               MOD)) %= MOD;
  }
  return cur;
}
int main() {
  giuncute();
  cin >> n >> m >> k >> MOD;
  p[0] = 1;
  for (long long i = 1; i <= n; ++i) p[i] = (p[i - 1] * i) % MOD;
  for (long long i = 0; i <= n; ++i) cnk[i][0] = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= i; ++j)
      cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
  memset(dp, -1, sizeof dp);
  cout << sol(n, m, k);
}
