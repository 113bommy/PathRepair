#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct edge
{
  int to, cost;
};

int main()
{
  int N, K, S;
  int X[2000], Y[2000], Z[2000];

  while(cin >> N >> K >> S, N) {
    for(int i = 0; i < N; i++) {
      cin >> X[i] >> Y[i] >> Z[i];
    }

    vector< edge > g[2000];
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < i; j++) {
        int latte = max(0LL, S - abs(X[i] - X[j]));
        int malta = max(0LL, S - abs(Y[i] - Y[j]));
        int beeet = max(0LL, S - abs(Z[i] - Z[j]));
        int ukuku = latte * malta + malta * beeet + beeet * latte;
        if(latte > 0 && malta > 0 && beeet > 0) {
          g[i].emplace_back((edge) {j, ukuku});
          g[j].emplace_back((edge) {i, ukuku});
        }
      }
    }

    int ret = -1;
    for(int i = 0; i < N; i++) {
      bool v[2000] = {};
      function< void(int, int, int) > dfs = [&](int idx, int k, int sz)
      {
        if(v[idx]++) return;
        if(k == 0) {
          if(K >= 3) for(auto &e: g[idx]) if(e.to == i) sz += e.cost;
          ret = max(ret, sz);
        } else {
          for(auto &e : g[idx]) dfs(e.to, k - 1, sz + e.cost);
        }
        v[idx] = false;
      };
      dfs(i, K - 1, 0);
    }
    if(ret == -1) cout << -1 << endl;
    else cout << 6 * S * S * K - ret * 2 << endl;
  }
}