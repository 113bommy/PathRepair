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
  int long long l;
  cin >> n >> l;
  double d;
  int long long a[n];
  for (int long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  d = a[0];
  for (int long long i = 0; i < n - 1; i++) {
    if (2 * d < (a[i + 1] - a[i])) {
      d = (1.0) * (a[i + 1] - a[i]) / 2;
    }
  }
  if (a[n - 1] + d < l) {
    d = l - a[n - 1];
  }
  cout << fixed << d << "\n";
}
