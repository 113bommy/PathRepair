#include <bits/stdc++.h>
using namespace std;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const long double PI = 3.141592653589793;
const long long INF = 9223372036854775807ll;
const long long mod = 1e9 + 7;
const int N = 8e4 + 2;
vector<int> adj[N];
vector<long long> sz(N, 1);
vector<long long> rem(N);
int n;
void dfs(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      rem[u] += (sz[v] * (sz[v] - 1)) / 2;
    }
  }
  rem[u] += ((n - sz[u]) * (n - sz[u] - 1)) / 2;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, -1);
  long long pr = (n * (n - 1)) / 2;
  pr *= (n * (n - 1)) / 2;
  for (int i = 1; i <= n; ++i) {
    long long add = (n - sz[i]) * sz[i];
    long long sub = (n * (n - 1)) / 2 - rem[i];
    pr -= sub * sub;
    pr += add * add;
  }
  cout << pr << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  solve();
  return 0;
}
