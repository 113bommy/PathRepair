#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return (a - b + mod) % mod; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
int f[N];
int fp(int b, int p) {
  if (p == 0) return 1;
  return mul(fp(mul(b, b), p / 2), p & 1 ? b : 1);
}
int inv(int n) { return fp(n, mod - 2); }
int nCk(int n, int k) { return mul(mul(f[n], inv(f[k])), inv(f[n - k])); }
void givemeareasontokeepgoing() {
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = mul(i, f[i - 1]);
  int n;
  cin >> n;
  vector<string> a(n);
  for (string &s : a) cin >> s;
  int cntW = 0, cntB = 0;
  for (string &s : a) {
    cntW += s[0] == 'W';
    cntW += s[1] == 'W';
    cntB += s[0] == 'B';
    cntB += s[1] == 'B';
  }
  if (cntB > n || cntW > n) {
    cout << 0;
    return;
  }
  int res = nCk(2 * n - cntW - cntB, n - cntW);
  int ways = 1;
  for (string s : a) {
    ways = mul(
        ways, (int)(s[0] != 'W' && s[1] != 'B') + (s[0] != 'B' && s[1] != 'W'));
  }
  res = sub(res, ways);
  bool wb = true, bw = true;
  for (string s : a) {
    bw &= (s[0] != 'W' && s[1] != 'B');
    wb &= (s[0] != 'B' && s[1] != 'W');
  }
  res = add(res, (int)bw + wb);
  cout << res << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) givemeareasontokeepgoing();
}
