#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int MOD = 1e9 + 7;
int n, k;
vector<int> g[N];
int height[N];
int dp[N][25][25];
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
pair<int, int> getN(int a, int b, int oa, int ob, bool &error) {
  int na = max(oa, a);
  int nb = min(ob, b);
  return {na, nb};
}
pair<int, int> updatePair(int a, int b) {
  int dist = k - b - 1;
  if (dist >= a) {
    a = 0;
  }
  return {a, b};
}
void calc(int v, int p = -1) {
  vector<vector<int> > f(k + 2), nf(k + 2);
  for (int i = 0; i <= k + 1; ++i) {
    f[i].resize(k + 2);
    nf[i].resize(k + 2);
  }
  for (int a = 0; a <= k + 1; ++a) {
    for (int b = 0; b <= k + 1; ++b) {
      f[a][b] = 0;
      nf[a][b] = 0;
    }
  }
  f[0][k + 1] = 1;
  for (auto e : g[v]) {
    if (e == p) continue;
    calc(e, v);
    for (int oa = 0; oa <= k; ++oa) {
      for (int ob = 0; ob <= k + 1; ++ob) {
        if (!f[oa][ob]) continue;
        for (int a = 0; a <= k; ++a) {
          for (int b = 0; b <= k + 1; ++b) {
            if (!dp[e][a][b]) continue;
            bool error = false;
            pair<int, int> np = getN(a, b, oa, ob, error);
            int ret = 1LL * f[oa][ob] * dp[e][a][b] % MOD;
            add(nf[np.first][np.second], ret);
          }
        }
      }
    }
    for (int a = 0; a <= k; ++a) {
      for (int b = 0; b <= k + 1; ++b) {
        f[a][b] = nf[a][b];
        nf[a][b] = 0;
      }
    }
  }
  for (int a = 0; a <= k; ++a) {
    for (int b = 0; b <= k + 1; ++b) {
      pair<int, int> np = updatePair(a, b);
      add(nf[np.first][np.second], f[a][b]);
    }
  }
  for (int a = 0; a <= k; a++) {
    for (int b = 0; b <= k + 1; b++) {
      add(dp[v][0][0], nf[a][b]);
    }
  }
  for (int a = 0; a <= k; ++a) {
    for (int b = 0; b <= k + 1; ++b) {
      if (!nf[a][b]) continue;
      int na, nb;
      if (a == 0) {
        na = a + 1;
        if (b <= k) na = 0;
        nb = min(k + 1, b + 1);
      } else {
        na = a + 1;
        nb = min(k + 1, b + 1);
      }
      pair<int, int> np = updatePair(na, nb);
      add(dp[v][np.first][np.second], nf[a][b]);
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  calc(0);
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    add(ans, dp[0][0][i]);
  }
  cout << ans << endl;
  return 0;
}
