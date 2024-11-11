#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long long MOD1 = 2286661337;
const long long MOD2 = 998244353;
const int INF = (int)1e9 + 7;
const double EPS = 1e-7;
const int N = (int)2e5;
const int M = 35;
int n, m, k;
long long a[N], in_base[M];
vector<long long> dp[M][M + 1];
long long p[M + 1];
int popcnt(long long x) {
  bitset<64> cur(x);
  return cur.count();
}
void solve1() {
  vector<long long> set_;
  set_.push_back(0);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < 1 << i; ++j) {
      set_.push_back(set_[j] ^ a[i]);
    }
  }
  for (int i = 0; i < 1 << k; ++i) {
    ++p[popcnt(set_[i])];
  }
  long long pow_ = 1;
  for (int i = 0; i < n - k; ++i) {
    pow_ = pow_ * 2 % MOD2;
  }
  for (int i = 0; i < m + 1; ++i) {
    p[i] = p[i] * pow_ % MOD2;
  }
}
void solve2() {
  for (int i = 0; i < k; ++i) {
    int cur_mask = 0, ind = 0;
    for (int j = 0; j < m; ++j) {
      if (!in_base[j]) {
        if (a[i] >> j & 1) {
          cur_mask |= 1 << ind;
        }
        ++ind;
      }
    }
    for (int cnt = 0; cnt < k + 1; ++cnt) {
      dp[i][cnt].resize(1 << m - k, 0);
      for (int s = 0; s < 1 << m - k; ++s) {
        if (i == 0) {
          if (cnt == 0 && s == 0 || cnt == 1 && s == cur_mask) {
            dp[i][cnt][s] = 1;
          }
        } else {
          dp[i][cnt][s] = dp[i - 1][cnt][s];
          if (cnt) {
            dp[i][cnt][s] =
                (dp[i][cnt][s] + dp[i - 1][cnt - 1][s ^ cur_mask]) % MOD2;
          }
        }
      }
    }
  }
  if (k) {
    for (int cnt = 0; cnt < k + 1; ++cnt) {
      for (int s = 0; s < 1 << m - k; ++s) {
        int ind = cnt + popcnt(s);
        p[ind] = (p[ind] + dp[k - 1][cnt][s]) % MOD2;
      }
    }
  } else {
    p[0] = 1;
  }
  long long pow_ = 1;
  for (int i = 0; i < n - k; ++i) {
    pow_ = pow_ * 2 % MOD2;
  }
  for (int i = 0; i < m + 1; ++i) {
    p[i] = p[i] * pow_ % MOD2;
  }
}
signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    for (int j = m - 1; j >= 0; --j) {
      if (a[i] >> j & 1) {
        if (in_base[j]) {
          a[i] ^= in_base[j];
        } else {
          in_base[j] = a[i];
          break;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (in_base[i]) {
      for (int j = i - 1; j >= 0; --j) {
        if (in_base[j] && (in_base[i] >> j & 1)) {
          in_base[i] ^= in_base[j];
        }
      }
      a[k] = in_base[i];
      ++k;
    }
  }
  if ((1ll << k) < (1ll << m - k) * k * k) {
    solve1();
  } else {
    solve2();
  }
  for (int i = 0; i < m + 1; ++i) {
    printf("%lld ", p[i]);
  }
  return 0;
}
