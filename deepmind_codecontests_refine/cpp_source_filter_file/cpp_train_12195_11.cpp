#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100009;
long long N, colors[MAXN], out;
vector<long long> adj[MAXN];
vector<vector<int> > br(MAXN);
void dfs(long long node, long long parent) {
  for (auto i : adj[node])
    if (i != parent) {
      dfs(i, node);
      br[node][1] += br[i][1];
      br[node][2] += br[i][2];
    }
}
int main() {
  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> colors[i];
    br[i].push_back(0);
    br[i].push_back(0);
    br[i].push_back(0);
    br[i][colors[i]]++;
  }
  for (long long i = 1; i < N; i++) {
    long long u, v, c;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  for (long long node = 1; node < N; node++) {
    pair<long long, long long> first_subtree(br[0][1] - br[node][1],
                                             br[0][2] - br[node][2]);
    pair<long long, long long> second_subtree(br[node][1], br[node][2]);
    if (first_subtree.first != 0 && first_subtree.second != 0) continue;
    if (second_subtree.first != 0 && second_subtree.second != 0) continue;
    out++;
  }
  cout << out << endl;
  return 0;
}
