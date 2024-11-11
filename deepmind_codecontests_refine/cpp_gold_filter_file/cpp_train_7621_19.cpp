#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const long long mod = 998244353;
const int maxn = 55;
int L[maxn], R[maxn];
vector<long long> t;
int N, M;
long long DP[maxn][maxn * 4];
long long F[maxn * 4], INV[maxn * 4];
long long qpow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long inverse(int x) { return qpow(x, mod - 2); }
void init() {
  F[0] = 1ll;
  for (int i = 1; i < maxn * 4; ++i) {
    F[i] = F[i - 1] * i % mod;
  }
  INV[maxn * 4 - 1] = inverse(F[maxn * 4 - 1]);
  for (int i = maxn * 4 - 2; i >= 0; --i) {
    INV[i] = INV[i + 1] * (i + 1) % mod;
  }
}
void discrete() {
  t.clear();
  t.push_back(-1);
  for (int i = 1; i <= N; ++i) {
    t.push_back(L[i]);
    t.push_back(R[i]);
  }
  sort(t.begin(), t.end());
  t.resize(unique(t.begin(), t.end()) - t.begin());
  M = t.size() - 1;
  for (int i = 1; i <= N; ++i) {
    L[i] = lower_bound(t.begin(), t.end(), L[i]) - t.begin();
    R[i] = lower_bound(t.begin(), t.end(), R[i]) - t.begin();
  }
}
long long C(long long n, int r) {
  long long ret = 1ll;
  for (int i = n; i > n - r; --i) ret = ret * i % mod;
  return ret * INV[r] % mod;
}
int main() {
  init();
  cin >> N;
  long long fenmu = 1;
  for (int i = 1; i <= N; ++i) {
    cin >> L[i] >> R[i];
    ++R[i];
    fenmu = fenmu * inverse(R[i] - L[i]) % mod;
  }
  discrete();
  for (int i = 0; i <= M; ++i) {
    DP[0][i] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = L[i]; j < R[i]; ++j) {
      for (int k = i; k >= 1; --k) {
        if (j < L[k] || R[k] <= j) break;
        DP[i][j] =
            (DP[i][j] +
             DP[k - 1][j + 1] * C(t[j + 1] - t[j] + i - k, i - k + 1) % mod) %
            mod;
      }
    }
    for (int j = M - 1; j >= 1; --j) {
      DP[i][j] = (DP[i][j] + DP[i][j + 1]) % mod;
    }
  }
  cout << fenmu * DP[N][1] % mod << endl;
}
