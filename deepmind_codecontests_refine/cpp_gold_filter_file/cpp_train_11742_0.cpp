#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

vector<bitset<50>> use_edge;
vector<vector<pair<int, int>>> edge;

bool dfs(int v, int i, int n, int p = -1) {
  if(n == v) return true;
  
  for(auto &e : edge[n]) {
    if(e.first == p) continue;
    
    bool res = dfs(v, i, e.first, n);
    
    if(res) {
      use_edge[i].set(e.second);
      return true;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  edge = vector<vector<pair<int, int>>>(n);
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a - 1].push_back({ b - 1, i });
    edge[b - 1].push_back({ a - 1, i });
  }
  int m;
  cin >> m;
  use_edge = vector<bitset<50>>(m, bitset<50>(0));
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    dfs(v - 1, i, u - 1);
  }

  i64 cnt = 0;
  for(int bit = 1; bit < (1 << m); ++bit) {
    int popcnt = 0;
    bitset<50> b(0);
    
    for(int i = 0; i < m; ++i) {
      if(bit & (1 << i)) {
        b |= use_edge[i];
        popcnt++;
      }
    }
    
    int e = (n - 1) - b.count();
    
    if(popcnt & 1 == 1) cnt += (1ll << e);
    else cnt -= (1ll << e);
  }

  i64 ans = (1ll << (n - 1)) - cnt;
  cout << ans << endl;
}
