#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
vector<pair<int, int> > vec;
int num[maxn], par[maxn];
int root(int v) { return ((par[v] < 0) ? v : root(par[v])); }
int sum(int v) { return (num[v] + ((par[v] < 0) ? 0 : sum(par[v]))) % mod; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(par, -1, sizeof par);
  int n, res = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0) continue;
    int mx, mxsz = 0, mxval;
    vec.clear();
    for (int t = 0; t < k; t++) {
      int v, x;
      cin >> v >> x;
      --v;
      vec.push_back(make_pair(root(v), (x + sum(v)) % mod));
      res = (res + vec.back().second) % mod;
      if (-par[vec.back().first] > mxsz) {
        mxsz = -par[vec.back().first];
        mx = vec.back().first;
        mxval = vec.back().second;
      }
    }
    num[mx] = (num[mx] + mxval) % mod;
    par[mx] -= 1;
    num[i] -= num[mx];
    par[i] = mx;
    for (auto x : vec) {
      int u = x.first, val = x.second;
      if (u == mx) continue;
      par[mx] += par[u];
      par[u] = mx;
      num[u] = ((num[u] + val) % mod - num[mx]) % mod;
    }
  }
  cout << (res + mod) % mod << "\n";
}
