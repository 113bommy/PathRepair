#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  bool neg = false;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') neg = true, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (neg) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 5e2, M = 1e6, mod = 998244353;
int n, m, c[M + 2], dp[2 * N + 2][2 * N + 2];
vector<int> p[N + 2];
void input() {
  cin >> n >> m;
  for (int _b = m, i = 1; i <= _b; ++i) cin >> c[i];
}
void pre() {
  int newm = 0;
  for (int _b = m, i = 1; i <= _b; ++i)
    if (c[i] != c[newm]) c[++newm] = c[i];
  m = newm;
  if (m > 2 * n) {
    cout << 0;
    exit(0);
  }
  for (int _b = m, i = 1; i <= _b; ++i) p[c[i]].push_back(i);
  memset(dp, 255, sizeof(dp));
}
int solve(int l, int r) {
  int &res = dp[l][r];
  if (res != -1) return res;
  if (l > r) return res = 1;
  int b = c[l];
  for (int _b = r, i = l; i <= _b; ++i) b = min(b, c[i]);
  if (p[b].front() < l || p[b].back() > r) return res = 0;
  int pre = 0;
  for (int _b = p[b].front(), i = l; i <= _b; ++i)
    pre =
        (pre + 1ll * solve(l, i - 1) * solve(i, p[b].front() - 1) % mod) % mod;
  int suf = 0;
  for (int _b = r, i = p[b].back(); i <= _b; ++i)
    suf = (suf + 1ll * solve(p[b].back() + 1, i) * solve(i + 1, r) % mod) % mod;
  res = 1ll * pre * suf % mod;
  for (int _b = (int)p[b].size() - 2, i = 0; i <= _b; ++i)
    res = 1ll * res * solve(p[b][i] + 1, p[b][i + 1] - 1);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  pre();
  cout << solve(1, m);
  return 0;
}
