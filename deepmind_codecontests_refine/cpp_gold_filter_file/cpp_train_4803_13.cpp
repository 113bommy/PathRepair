#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000000000000;
long long mod = 1000000000;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 3e5 + 2;
long long n, m;
bool cycle;
void dfs(int i, vector<long long> g[], vector<long long> &visi,
         vector<long long> &topo) {
  visi[i] = 1;
  if (cycle) return;
  for (auto x : g[i]) {
    if (visi[x] == 0) {
      dfs(x, g, visi, topo);
    } else if (visi[x] == 1) {
      cycle = true;
      return;
    }
  }
  visi[i] = 2;
  topo.push_back(i);
}
void solve() {
  {
    cin >> n >> m;
    vector<pair<pair<long long, long long>, long long>> edg;
    long long right = 0;
    for (int i = 0; i < m; i++) {
      long long u, v, w;
      cin >> u >> v >> w;
      edg.push_back({{u, v}, w});
      right = max(right, w);
    }
    long long left = 0;
    vector<long long> ans;
    long long res = MAX;
    while (left <= right) {
      long long mid = (left + right) / 2;
      cycle = false;
      vector<long long> g[n + 1];
      for (auto x : edg) {
        if (x.second > mid) {
          g[x.first.first].push_back(x.first.second);
        }
      }
      vector<long long> topo;
      vector<long long> visi(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        if (visi[i] == 0) {
          dfs(i, g, visi, topo);
        }
      }
      if (!cycle) {
        right = mid - 1;
        if (res > mid) {
          res = mid;
          reverse(topo.begin(), topo.end());
          long long topocount[n + 1];
          long long cnt = 0;
          for (auto x : topo) {
            topocount[x] = cnt;
            cnt++;
          }
          ans.clear();
          cnt = 1;
          for (auto x : edg) {
            if (x.second <= mid &&
                topocount[x.first.first] > topocount[x.first.second]) {
              ans.push_back(cnt);
            }
            cnt++;
          }
        }
      } else {
        left = mid + 1;
      }
    }
    cout << res << " " << ans.size() << endl;
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
}
int main() {
  pls();
  solve();
  return 0;
}
