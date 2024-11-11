#include <bits/stdc++.h>
using namespace std;
long long ans[60];
int cb[100][100];
void solve(int d, long long x, const vector<long long>& bs) {
  if (d == bs.size()) {
    ans[__builtin_popcountll(x)]++;
    return;
  }
  solve(d + 1, x ^ bs[d], bs);
  solve(d + 1, x, bs);
}
int C(int n, int m) {
  if (m < 0 || n < m) return 0;
  if (m == 0 || n == m) return 1;
  if (cb[n][m]) return cb[n][m];
  return cb[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % 998244353;
}
int main() {
  int n, m;
  long long x;
  scanf("%d%d", &n, &m);
  vector<long long> bs;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x);
    for (int j = 0; j < bs.size(); j++) {
      if (x & (bs[j] & -bs[j])) x ^= bs[j];
    }
    if (x) bs.push_back(x);
  }
  int rk = bs.size();
  long long p2 = 1;
  for (int i = 0; i < n - rk; i++) p2 = (p2 + p2) % 998244353;
  long long piv = 0;
  for (int i = rk - 1; i >= 0; i--) {
    piv |= bs[i] & -bs[i];
    for (int j = i - 1; j >= 0; j--) {
      if (bs[j] & (bs[i] & -bs[i])) bs[j] ^= bs[i];
    }
  }
  if (rk <= (m + 1) / 2) {
    solve(0, 0, bs);
    for (int i = 0; i <= m; i++)
      printf("%lld ", ans[i] % 998244353 * p2 % 998244353);
  } else {
    vector<long long> dual;
    for (int i = 0; i < m; i++) {
      if ((piv >> i) & 1) continue;
      long long tmp = (1LL << i);
      for (auto x : bs) {
        if ((x >> i) & 1) tmp |= x & -x;
      }
      dual.push_back(tmp);
    }
    solve(0, 0, dual);
    long long rans[60] = {};
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= m; j++) {
        long long c = 0;
        for (int k = 0; k <= m; k++) {
          if (k & 1)
            c -= C(j, k) * C(m - j, i - k) % 998244353;
          else
            c += C(j, k) * C(m - j, i - k) % 998244353;
        }
        c = (c % 998244353 + 998244353) % 998244353;
        rans[i] += ans[j] % 998244353 * c % 998244353;
      }
      rans[i] %= 998244353;
      for (int j = 0; j < m - rk; j++) {
        if (rans[i] & 1)
          rans[i] = (rans[i] + 998244353) / 2;
        else
          rans[i] /= 2;
      }
      printf("%lld ", rans[i] * p2 % 998244353);
    }
  }
  return 0;
}
