#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long lgput(long long a, long long b, long long mod) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (ret % mod);
}
inline long long inv(long long x, long long MOD) {
  return lgput(x, MOD - 2, MOD);
}
const long double PI = acos(-1);
const long double eps = 1e-6;
const int inf = 1e9;
const long long infll = 1e18;
using Matrix = vector<vector<long long> >;
Matrix mult(Matrix a, Matrix b) {
  int n = a.size();
  int k = a[0].size();
  int m = b[0].size();
  Matrix rez(n, vector<long long>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int l = 0; l < k; ++l) {
        rez[i][j] = (rez[i][j] + a[i][l] * b[l][j]) % (MOD - 1);
      }
    }
  }
  return rez;
}
Matrix put(Matrix a, long long putere) {
  Matrix ret = a;
  putere--;
  while (putere) {
    if (putere & 1) ret = mult(ret, a);
    a = mult(a, a);
    putere >>= 1;
  }
  return ret;
}
long long dpp[55][55][55][4];
long long fact[55];
int aux[4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(12);
  int n, t;
  cin >> n >> t;
  vector<pair<int, int> > v(n);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
    aux[v[i].second]++;
  }
  vector<vector<vector<vector<long long> > > > dp(
      t + 1, vector<vector<vector<long long> > >(
                 aux[1] + 1, vector<vector<long long> >(
                                 aux[2] + 1, vector<long long>(aux[3] + 1))));
  int cnt[4] = {0, 0, 0, 0};
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = t - v[i].first; j >= 0; --j) {
      if (j + v[i].first > t) continue;
      for (int j1 = 0; j1 <= cnt[1]; ++j1) {
        for (int j2 = 0; j2 <= cnt[2]; ++j2) {
          for (int j3 = 0; j3 <= cnt[3]; ++j3) {
            int nextj1 = j1 + (v[i].second == 1);
            int nextj2 = j2 + (v[i].second == 2);
            int nextj3 = j3 + (v[i].second == 3);
            dp[j + v[i].first][nextj1][nextj2][nextj3] += dp[j][j1][j2][j3];
            if (dp[j + v[i].first][nextj1][nextj2][nextj3] >= MOD)
              dp[j + v[i].first][nextj1][nextj2][nextj3] -= MOD;
          }
        }
      }
    }
    cnt[v[i].second]++;
  }
  dpp[0][0][0][0] = 1;
  for (int j1 = 0; j1 <= cnt[1]; ++j1) {
    for (int j2 = 0; j2 <= cnt[2]; ++j2) {
      for (int j3 = 0; j3 <= cnt[3]; ++j3) {
        for (int last = 0; last <= 3; ++last) {
          for (int now = 1; now <= 3; ++now) {
            if (last != now) {
              int nextj1 = j1 + (now == 1);
              int nextj2 = j2 + (now == 2);
              int nextj3 = j3 + (now == 3);
              dpp[nextj1][nextj2][nextj3][now] += dpp[j1][j2][j3][last];
              if (dpp[nextj1][nextj2][nextj3][now] >= MOD)
                dpp[nextj1][nextj2][nextj3][now] -= MOD;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int j1 = 0; j1 <= cnt[1]; ++j1) {
    for (int j2 = 0; j2 <= cnt[2]; ++j2) {
      for (int j3 = 0; j3 <= cnt[3]; ++j3) {
        long long add = dp[t][j1][j2][j3];
        add *= (dpp[j1][j2][j3][1] + dpp[j1][j2][j3][2] + dpp[j1][j2][j3][3]) %
               MOD;
        add %= MOD;
        add *= fact[j1];
        add %= MOD;
        add *= fact[j2];
        add %= MOD;
        add *= fact[j3];
        add %= MOD;
        ans += add;
        if (ans >= MOD) ans -= MOD;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
