#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 1010;
const int M = 25;
const int MOD = int(1e9) + 7;
int sz;
char s[N];
int pv[N * M], pc[N * M], _link[N * M], q[N * M], len[N * M];
int _next[N * M][10], go[N * M][10];
int dp[N * M][M + 1][2], ndp[N * M][M + 1][2];
inline void build() {
  scanf("%s", s);
  int n = strlen(s);
  sz = 1;
  for (int i = 0; i < 10; ++i) {
    _next[0][i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < M && i + j < n; ++j) {
      if (_next[cur][s[i + j] - '0'] == -1) {
        for (int z = 0; z < 10; ++z) {
          _next[sz][z] = -1;
        }
        pv[sz] = cur;
        pc[sz] = s[i + j] - '0';
        len[sz] = len[cur] + 1;
        _next[cur][s[i + j] - '0'] = sz++;
      }
      cur = _next[cur][s[i + j] - '0'];
    }
  }
  int l = 0, r = 1;
  q[0] = 0;
  while (l < r) {
    int v = q[l++];
    if (v == 0 || pv[v] == 0) {
      _link[v] = 0;
    } else {
      _link[v] = go[_link[v]][pc[v]];
    }
    for (int i = 0; i < 10; ++i) {
      if (_next[v][i] != -1) {
        go[v][i] = _next[v][i];
      } else {
        go[v][i] = go[_link[v]][i];
      }
    }
    for (int i = 0; i < 10; ++i) {
      if (_next[v][i] != -1) {
        q[r++] = _next[v][i];
      }
    }
  }
}
inline int calc() {
  scanf("%s", s);
  int n = strlen(s);
  assert(n / 2 <= M);
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j <= n / 2; ++j) {
      for (int z = 0; z < 2; ++z) {
        dp[i][j][z] = 0;
      }
    }
  }
  dp[0][0][1] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < sz; ++j) {
      for (int z = 0; z <= n / 2; ++z) {
        for (int h = 0; h < 2; ++h) {
          ndp[j][z][h] = 0;
        }
      }
    }
    for (int j = 0; j < sz; ++j) {
      for (int z = 0; z <= n / 2; ++z) {
        for (int h = 0; h < 2; ++h) {
          if (dp[j][z][h] == 0) {
            continue;
          }
          for (int c = (i == 0 ? 1 : 0); c <= (h ? s[i] - '0' : 9); ++c) {
            int nj = go[j][c];
            int nz = max(z, len[nj]);
            if (nz > n / 2) {
              nz = n / 2;
            }
            int nh = h;
            if (h && c < s[i] - '0') {
              nh = 0;
            }
            ndp[nj][nz][nh] += dp[j][z][h];
            if (ndp[nj][nz][nh] >= MOD) {
              ndp[nj][nz][nh] -= MOD;
            }
          }
        }
      }
    }
    for (int j = 0; j < sz; ++j) {
      for (int z = 0; z <= n / 2; ++z) {
        for (int h = 0; h < 2; ++h) {
          dp[j][z][h] = ndp[j][z][h];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < sz; ++i) {
    ans = (ans + dp[i][n / 2][0]) % MOD;
    ans = (ans + dp[i][n / 2][1]) % MOD;
  }
  return ans;
}
inline bool check() {
  int n = strlen(s), cur = 0, max_len = 0;
  for (int i = 0; i < n; ++i) {
    cur = go[cur][s[i] - '0'];
    max_len = max(max_len, len[cur]);
  }
  if (max_len >= n / 2) {
    return true;
  } else {
    return false;
  }
}
int main() {
  if (0) cerr << (sizeof(dp) + sizeof(ndp)) / 1024 / 1024 << endl;
  build();
  int ans = (MOD - calc()) % MOD;
  if (check()) {
    ans = (ans + 1) % MOD;
  }
  ans = (ans + calc()) % MOD;
  cout << ans << endl;
  return 0;
}
