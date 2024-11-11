#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
template <typename T>
void amin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void amax(T &x, T y) {
  if (y > x) x = y;
}
vector<int> g[maxn];
vector<pair<int, int>> adj[maxn];
bool vis[maxn];
long long int dis[maxn];
int par[maxn];
int col[maxn];
string dir = "URDL";
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  long long int y, k, n;
  cin >> y >> k >> n;
  long long int x;
  vector<long long int> pos;
  if (y <= k)
    x = k - y;
  else {
    x = k - y % k;
  }
  int f = 0;
  while (x + y <= n) {
    if ((x + y) % k == 0) {
      if (x != 0) cout << x << " ";
      x += k;
      f = 1;
    } else
      x++;
  }
  if (!f) cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) solve();
  return 0;
}
