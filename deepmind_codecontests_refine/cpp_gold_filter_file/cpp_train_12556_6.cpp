#include <bits/stdc++.h>
using namespace std;
const int N = 2000000 + 10;
const int MOD = (int)1e9 + 7, rev = (MOD + 1) >> 1;
int n;
char s[N];
int a[N], b[N];
int ans[N];
int cnt[N];
int p2[30];
void FWT(int *a, int n) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = (x + y) % MOD, a[i + j + d] = (x - y + MOD) % MOD;
      }
}
void UFWT(int *a, int n) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        a[i + j] = 1LL * (x + y) * rev % MOD,
              a[i + j + d] = (1LL * (x - y) * rev % MOD + MOD) % MOD;
      }
}
void solve(int *a, int *b, int n) {
  FWT(a, n);
  FWT(b, n);
  for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * b[i] % MOD;
  UFWT(a, n);
}
void solve() {
  cin >> n;
  scanf("%s", s);
  p2[0] = 1;
  for (int i = 1; i <= 20; ++i) {
    p2[i] = p2[i - 1] * 2 % MOD;
  }
  for (int i = 0; i < 1 << n; ++i) {
    a[i] = s[i] - '0';
    b[i] = 1 - a[i];
    if (i) {
      cnt[i] = cnt[i - (i & -i)] + 1;
    }
  }
  solve(a, b, 1 << n);
  long long ret = 0;
  for (int i = 0; i < 1 << n; ++i) {
    (ret += 1ll * a[i] * p2[cnt[i]]) %= MOD;
  }
  cout << (ret * 3 % MOD + MOD) % MOD << endl;
}
int main() {
  solve();
  return 0;
}
