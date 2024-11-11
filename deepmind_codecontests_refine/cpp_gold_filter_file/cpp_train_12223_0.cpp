#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}
inline long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
const int MAXN = 100005;
const int INF = 1000000000;
int n;
long long v[MAXN];
vector<int> adj[MAXN];
long long tot;
bool impossible;
long long find_mmc(int u, int p) {
  int k = (int)adj[u].size();
  if (u != 0) k--;
  if (k < 1) {
    return 1;
  } else {
    long long aux = k, mmc = 1LL;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int next = adj[u][i];
      if (next == p) continue;
      mmc = lcm(mmc, find_mmc(next, u));
    }
    if (log(aux) + log(mmc) > log(tot) + 1.) impossible = true;
    return mmc * aux;
  }
}
bool solve(int u, int p, long long w) {
  int k = (int)adj[u].size();
  if (u != 0) k--;
  if (k < 1) {
    return w <= v[u];
  } else {
    long long aux = w / k, mmc = 1LL;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int next = adj[u][i];
      if (next == p) continue;
      if (!solve(next, u, aux)) return false;
    }
    return true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    tot = 0LL;
    impossible = false;
    for (int i = 0; i < n; ++i) tot += v[i];
    long long aux = find_mmc(0, 0);
    if (impossible) {
      cout << tot << endl;
    } else {
      long long lo = 1, hi = tot / aux;
      while (lo < hi) {
        long long mid = (lo + hi) >> 1;
        long long w = mid * aux;
        if (solve(0, 0, w)) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
      if (!solve(0, 0, hi * aux)) hi--;
      long long w = hi * aux;
      cout << tot - w << endl;
    }
  }
}
