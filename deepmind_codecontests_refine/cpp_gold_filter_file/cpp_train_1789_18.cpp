#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1e9 + 7;
;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
const int maxn = 1e3 + 5;
int n;
int sz[maxn];
vector<int> adj[maxn];
void dfs(int a, int p) {
  sz[a] = 1;
  for (int b : adj[a])
    if (b != p) {
      dfs(b, a);
      sz[a] += sz[b];
    }
}
int val[maxn];
void solve(int a, int p, function<int()> gen) {
  val[a] = gen();
  printf("%d %d %d\n", a, p, val[a] - val[p]);
  for (int b : adj[a])
    if (b != p) {
      solve(b, a, gen);
    }
}
int main() {
  cin >> n;
  for (int k = (int)1; k < (int)n; k++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int k = (int)1; k < (int)n + 1; k++) {
    dfs(k, 0);
    vector<pair<int, int> > cur;
    for (auto b : adj[k]) {
      cur.push_back({sz[b], b});
    }
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    if (cur.size() == 0 || cur[0].first > n / 2) continue;
    int tot = 0, i = 1, j = 1;
    auto gen_small = [&]() { return i++; };
    auto gen_big = [&]() { return (tot + 1) * (j++); };
    for (auto x : cur) {
      if (tot < n / 3) {
        solve(x.second, k, gen_small);
        tot += x.first;
      } else {
        solve(x.second, k, gen_big);
      }
    }
    break;
  }
}
