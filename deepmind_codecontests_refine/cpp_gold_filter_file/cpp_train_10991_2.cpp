#include <bits/stdc++.h>
using namespace std;
const long long int INF = 98769876987698889LL;
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx4[] = {0, 0, 1, -1};
const int dy4[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;
const int MODB = 1e9 + 9;
const int N = 2e5 + 5;
const int SN = 5e5;
vector<int> G[N];
int vis[N];
vector<int> ans[N];
int cur = 0;
int n, m, k;
long long int mx;
void dfs(int x) {
  vis[x] = 1;
  ans[cur].push_back(x);
  int sz = ans[cur].size();
  if (sz == mx) {
    cur++;
  }
  for (auto ka : G[x]) {
    if (!vis[ka]) {
      dfs(ka);
      ans[cur].push_back(x);
      int szA = ans[cur].size();
      if (szA == mx) ++cur;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  mx = (ceil)(n + n + k - 1) / (1.0 * k);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1);
  for (int i = 0; i < k; i++) {
    if (ans[i].size() == 0) {
      cout << 1 << " " << 1 << endl;
    } else {
      cout << ans[i].size() << " ";
      for (auto f : ans[i]) cout << f << " ";
      cout << endl;
    }
  }
}
