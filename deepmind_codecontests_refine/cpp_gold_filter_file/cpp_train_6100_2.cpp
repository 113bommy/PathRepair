#include <bits/stdc++.h>
using namespace std;
string itos(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int n;
vector<pair<int, int> > e[100010];
long long c[100010], kc[100010];
void mult(long long &x, long long y) { (x *= y) %= 1000000007; }
long long pwr(long long b, long long e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  return (pwr((b * b) % 1000000007, e / 2) * pwr(b, e % 2)) % 1000000007;
}
long long inv(long long x) { return pwr(x, 1000000007 - 2); }
void add(long long &x, long long y) {
  x += y;
  x %= 1000000007;
  if (x < 0) x += 1000000007;
}
void dfs(long long now, long long p) {
  bool isLeaf = true;
  c[now] = e[now].size();
  for (auto x : e[now]) {
    int nxt = x.first;
    int cost = x.second;
    add(kc[now], cost);
    if (nxt - p) {
      isLeaf = false;
      dfs(nxt, now);
      add(kc[now], kc[nxt]);
      add(c[now], -c[nxt]);
    }
  }
  if (isLeaf) {
    c[now] = kc[now] = 0;
    return;
  }
  c[now] = inv(c[now]);
  mult(kc[now], c[now]);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back((make_pair((v), (w))));
    e[v].push_back((make_pair((u), (w))));
  }
  dfs(0, 0);
  cout << kc[0] << endl;
  return 0;
}
