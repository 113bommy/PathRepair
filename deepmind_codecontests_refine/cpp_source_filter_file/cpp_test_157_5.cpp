#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, inf = 0x3f3f3f3f, mod = 998244353;
long long C[5010][5010];
void solve() {
  for (int i = 0; i <= 5000; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  long long n, k;
  scanf("%lld%lld", &n, &k);
  string s;
  cin >> s;
  int lo = 0, ri = 0, cnt = 0, plo = -inf, pri = -inf;
  long long ans = 0;
  if (k == 0) {
    printf("0\n");
    return;
  }
  while (ri < n) {
    if (s[ri] == '1') cnt++;
    while (ri + 1 < n && s[ri + 1] == '0') ri++;
    while (cnt > k) {
      if (s[lo] == '1') cnt--, lo++;
    }
    if (cnt == k) {
      ans = (ans + C[ri - lo + 1][k]) % mod;
      if (plo != -inf) {
        ans = (ans - C[pri - lo + 1][k - 1] + mod) % mod;
      }
      plo = lo;
      pri = ri;
    }
    ri++;
  }
  if (pri == -inf) {
    printf("1\n");
    return;
  }
  printf("%lld\n", (ans + mod) % mod);
}
int main() {
  solve();
  return 0;
}
