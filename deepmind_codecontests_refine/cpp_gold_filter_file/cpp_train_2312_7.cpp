#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
vector<int> g[N];
int a[N];
void solve() {
  long long i, j, n, k, data, m, f = 1;
  cin >> n;
  vector<long long> v;
  long long sum = 0;
  long long id = -1;
  for (i = 0; i < n; i++) {
    cin >> data;
    v.push_back(data);
    sum++;
    if (sum + 1 > n / 2 && id == -1) {
      id = i;
    }
  }
  if (n < 6) {
    cout << "0 0 0\n";
    return;
  }
  v.push_back(-1);
  long long cnt = 1;
  vector<pair<long long, long long> > vv;
  for (i = 0; i < n; i++) {
    if (v[i] == v[i + 1]) {
      cnt++;
    } else {
      vv.push_back(make_pair(v[i], cnt));
      cnt = 1;
    }
    if (i == id) {
      break;
    }
  }
  if (vv.size() == 0) {
    cout << "0 0 0\n";
    return;
  }
  long long g = 0, b = 0, s = 0, pg = -1, ps = -1, push_back = -1;
  g = vv[0].second;
  pg = vv[0].first;
  for (auto x : vv) {
    if (x.first < pg) {
      s += x.second;
      ps = x.first;
    }
    if (s > g) {
      break;
    }
  }
  for (auto x : vv) {
    if (x.first < ps) {
      b += x.second;
    }
  }
  if (g == 0 || s == 0 || b == 0 || b <= g || s <= g) {
    cout << "0 0 0\n";
    return;
  } else {
    cout << g << " " << s << " " << b << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
