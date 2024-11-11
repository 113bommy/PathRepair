#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
long long inv(long long a) { return qp(a, mod - 2); }
struct Seg {
  long long l, r;
  Seg() {}
  Seg(long long _l, long long _r) {
    l = _l;
    r = _r;
  }
};
int n;
long long l[58], r[58];
int segl[128], segr[128];
vector<long long> vec;
vector<Seg> segs;
long long dp[54][54];
bool allin(int id, int L, int R) {
  for (int i = L; i <= R; ++i) {
    if (id < segl[i] || id > segr[i]) return false;
  }
  return true;
}
long long C(long long n, long long k) {
  if (k == 0) return 1;
  long long ret = 1;
  for (int i = 1; i <= k; ++i) ret = ret * inv(i) % mod;
  for (int i = n - k + 1; i <= n; ++i) ret = ret * i % mod;
  return ret;
}
int main() {
  cin >> n;
  long long tot = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    r[i]++;
    vec.push_back(l[i]);
    vec.push_back(r[i]);
    tot = tot * (r[i] - l[i]) % mod;
  }
  for (int i = 1; i * 2 <= n; ++i) {
    swap(l[i], l[n - i + 1]);
    swap(r[i], r[n - i + 1]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  segs.emplace_back(-1, -1);
  for (int i = 0; i < vec.size(); ++i) {
    if (i >= 1) segs.emplace_back(vec[i - 1], vec[i]);
  }
  int sl = segs.size() - 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= sl; ++j)
      if (l[i] == segs[j].l) {
        segl[i] = j;
        break;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= sl; ++j)
      if (r[i] == segs[j].r) {
        segr[i] = j;
        break;
      }
  dp[0][0] = 1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < sl; ++j) {
      if (i > 0 && j == 0) continue;
      for (int k = 0; i + k <= n; ++k) {
        if (allin(j + 1, i + 1, i + k)) {
          dp[i + k][j + 1] =
              (dp[i + k][j + 1] +
               dp[i][j] * C(k + segs[j + 1].r - segs[j + 1].l - 1, k) % mod) %
              mod;
        }
      }
    }
  }
  printf("%lld\n", dp[n][sl] * inv(tot) % mod);
}
