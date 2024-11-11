#include <bits/stdc++.h>
using namespace std;
int long long mod = 1e9 + 7;
int long long mod1 = mod * (-1);
vector<int long long> v[1000001], tr[100001];
int long long level[1000001] = {0};
int long long in[1000001] = {0};
int long long out[1000001] = {0};
int long long low[1000001] = {0};
int long long vis[1000001] = {0};
int long long visit[1001][1001] = {0};
int long long dis[1001][1001] = {0};
int long long dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int long long dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int long long timer, n, m, t, q, eq = 0;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  double l;
  cin >> n >> l;
  double d;
  double a[n + 2];
  a[0] = -1;
  a[n + 1] = mod;
  for (int long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 2);
  a[0] = -a[1];
  a[n + 1] = l + (l - a[n]);
  d = 0;
  for (int long long i = 0; i < n + 1; i++) {
    d = max(d, a[i + 1] - a[i]);
  }
  cout << fixed << d / 2.0 << "\n";
}
