#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
long long x[maxn];
vector<int> adj[maxn];
bool vst[maxn];
vector<pair<long long, int> > acs[maxn];
int par[maxn];
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b != 0) {
    return gcd(b, a % b);
  } else {
    return a;
  }
}
long long sol() {
  queue<int> q;
  q.push(0);
  par[0] = -1;
  long long sm = 0;
  vst[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (par[u] != -1) {
      for (pair<long long, int> p : acs[par[u]]) {
        long long v = gcd(x[u], p.first);
        if (acs[u].size() != 0 && acs[u].back().first == v) {
          acs[u].back().second += p.second;
        } else {
          acs[u].push_back({v, p.second});
        }
      }
    }
    acs[u].push_back({x[u], 1});
    for (pair<long long, int> p : acs[u]) {
      sm += p.first % mod * p.second % mod;
      sm %= mod;
    }
    for (int v : adj[u]) {
      if (!vst[v]) {
        vst[v] = true;
        par[v] = u;
        q.push(v);
      }
    }
  }
  return sm;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cout << sol() << endl;
  return 0;
}
