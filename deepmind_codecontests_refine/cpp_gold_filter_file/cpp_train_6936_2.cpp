#include <bits/stdc++.h>
using namespace std;
vector<long long> vt;
long long dp[1000010][21];
long long p[1000100];
long long func(long long here, long long ch) {
  if (here == 0) {
    if (ch == 0)
      return 1;
    else
      return 0;
  }
  long long &ret = dp[here][ch];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i <= ch; i++) {
    ret += func(here - 1, ch - i);
    ret %= 1000000007;
  }
  return ret;
}
long long mypow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return (a * mypow((a * a) % 1000000007, b / 2)) % 1000000007;
  return mypow((a * a) % 1000000007, b / 2);
}
int main() {
  for (int i = 2; i <= sqrt(1000000); i++) {
    if (p[i]) continue;
    vt.push_back(i);
    for (int y = i + i; y <= sqrt(1000000); y += i) p[y] = 1;
  }
  memset(dp, -1, sizeof(dp));
  long long n;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    long long q, w;
    scanf("%lld %lld", &q, &w);
    long long dap = 1;
    for (int y = 0; y < vt.size(); y++) {
      int cnt = 0;
      while (q % vt[y] == 0) {
        q /= vt[y];
        cnt++;
      }
      dap *= func(w, cnt);
      dap %= 1000000007;
    }
    if (q != 1) {
      dap *= func(w, 1);
      dap %= 1000000007;
    }
    dap *= (mypow(2, w - 1));
    dap %= 1000000007;
    printf("%lld\n", dap);
  }
}
