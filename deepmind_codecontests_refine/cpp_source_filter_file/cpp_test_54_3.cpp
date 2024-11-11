#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll BIG = 1e18;
auto lambda_pairs = [](const pi &x, const pi &y) {
  if (x.first == y.first) {
    return x.second > y.second;
  } else {
    return x.first > y.first;
  }
};
using namespace std;
int maxi = 700005;
vector<vector<int> > adj;
int color[700005];
int tot = 0;
int tot2 = 0;
int n2 = 200000;
bool con = false;
void dfs(int node, int val) {
  color[node] = val;
  int new_val;
  if (node <= n2) {
    if (val == 1) {
      tot++;
    } else {
      tot2++;
    }
  }
  if (val == 1) {
    new_val = 0;
  } else {
    new_val = 1;
  }
  for (int i = 0; i < adj[node].size(); i++) {
    if (color[adj[node][i]] == -1) {
      dfs(adj[node][i], new_val);
    } else if (color[adj[node][i]] != new_val) {
      con = true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int fake = n + 1;
    n2 = n + 1;
    adj.assign(n + m + 5, vector<int>());
    for (int i = 0; i < maxi; i++) {
      color[i] = -1;
    }
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      string second;
      cin >> second;
      if (second == "imposter") {
        adj[l].push_back(r);
        adj[r].push_back(l);
      } else {
        adj[l].push_back(fake);
        adj[r].push_back(fake);
        adj[fake].push_back(l);
        adj[fake].push_back(r);
        fake++;
      }
    }
    int maxe = 0;
    con = false;
    for (int i = 1; i <= n; i++) {
      if (color[i] == -1) {
        tot = 0;
        tot2 = 0;
        dfs(i, 1);
        maxe += max(tot, tot2);
      }
      if (con) {
        break;
      }
    }
    if (con) {
      cout << -1 << endl;
    } else {
      cout << maxe << endl;
    }
  }
}
