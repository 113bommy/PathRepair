#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long mod = 99998244353;
long long n, m, t, k, a[N], b[N], tong, ans, d[N], u, v, h[N], st[N], fe[N];
priority_queue<long long, vector<long long>, greater<long long> > pq;
struct dang {
  long long s, f, l, b;
} e[N];
vector<long long> adj[N], kq;
vector<pair<long long, long long> > w;
void add(long long id) {
  for (; id <= n; id += id & -id) st[id] += v;
}
long long get(long long id) {
  long long total = 0;
  for (; id; id -= id & -id) total += st[id];
  return total;
}
void addfe(long long id) {
  for (; id <= n; id += id & -id) fe[id] += v;
}
long long getfe(long long id) {
  long long total = 0;
  for (; id; id -= id & -id) total += fe[id];
  return total;
}
void sol() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 62; j >= 0; j--) {
      if ((a[i] >> j) & 1) {
        adj[j].push_back(a[i]);
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    bool ok = false;
    for (int j = 0; j < 63; j++) {
      if (!((tong >> j) & 1) && adj[j].size()) {
        tong ^= adj[j].back();
        kq.push_back(adj[j].back());
        adj[j].pop_back();
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO";
      return;
    }
  }
  cout << "YES" << '\n';
  for (long long u : kq) cout << u << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("haircut"
            ".in",
            "r")) {
    freopen(
        "haircut"
        ".in",
        "r", stdin);
    freopen(
        "haircut"
        ".out",
        "w", stdout);
  }
  int ntest = 1;
  while (ntest-- > 0) sol();
}
