#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e6 + 1;
bool bo[MX];
vector<long long> vec, vec2, vec3;
pair<long long, long long> pa;
vector<pair<long long, long long>> vpa;
set<long long> se;
set<pair<long long, long long>> sepa;
map<long long, long long> ma;
map<pair<long long, long long>, long long> mapa;
map<pair<long long, long long>, pair<long long, long long>> mapapa;
vector<long long> adj[MX];
bool vis[MX];
void addEdge(long long u, long long v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool dfs(long long u, long long target) {
  if (u == target) {
    return true;
  }
  vis[u] = true;
  for (long long v : adj[u]) {
    if (!vis[v]) {
      bool encontrado = dfs(v, target);
      if (encontrado) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  while (n--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long mayor = max(max(a, b), c);
    long long asd = (3 * mayor) - (a + b + c);
    long long j = d - asd;
    if (j > 0) {
      if (j % 3 == 0)
        cout << "YES" << endl;
      else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
