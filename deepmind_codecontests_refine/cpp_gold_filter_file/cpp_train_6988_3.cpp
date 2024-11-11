#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { return uniform_int_distribution<int>(0, x - 1)(rng); }
const int maxn = 1e6 + 7;
const int inf = 1e9 + 7;
const long long mod = 1e9 + 7;
long long gcd(long long x, long long y) {
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  return gcd(y, x % y);
}
int A[17][10005];
bool ham[17][17];
bool dp[1 << 16][17][17];
vector<int> G[17];
int n, m;
void doham() {
  for (int j = 0; j < (1 << n); j++) {
    for (int v = 0; v < n; v++) {
      for (int w = 0; w < n; w++) {
        dp[j][v][w] = false;
      }
    }
  }
  for (int msk = 0; msk < (1 << n); msk++) {
    for (int s = 0; s < n; s++) {
      if ((msk & (1 << s)) == 0) continue;
      for (int e = 0; e < n; e++) {
        if ((msk & (1 << e)) == 0) continue;
        if (msk == (1 << s) && s == e) {
          dp[msk][s][e] = true;
          continue;
        }
        for (int y : G[s]) {
          if (msk & (1 << y)) {
            dp[msk][s][e] = dp[msk][s][e] || dp[msk ^ (1 << s)][y][e];
          }
        }
      }
    }
  }
  for (int s = 0; s < n; s++) {
    for (int e = 0; e < n; e++) {
      ham[s][e] = dp[(1 << n) - 1][s][e];
    }
  }
}
bool okay(int K) {
  for (int j = 0; j < n; j++) {
    G[j].clear();
  }
  for (int j = 0; j < n; j++) {
    for (int k = j + 1; k < n; k++) {
      bool ok = true;
      for (int i = 0; i < m; i++) {
        if (abs(A[j][i] - A[k][i]) < K) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      G[j].push_back(k);
      G[k].push_back(j);
    }
  }
  doham();
  for (int s = 0; s < n; s++) {
    for (int e = 0; e < n; e++) {
      if (s == e && n > 1) continue;
      bool ok = true;
      for (int j = 0; j < m - 1; j++) {
        if (abs(A[e][j] - A[s][j + 1]) < K) {
          ok = false;
          break;
        }
      }
      if (ok && ham[s][e]) return true;
    }
  }
  return false;
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
  };
  cin >> n >> m;
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < m; k++) {
      cin >> A[j][k];
    }
  }
  int l = 0, r = inf;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (okay(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << "\n";
}
