#include <bits/stdc++.h>
using namespace std;
const long long int INF = 2e18;
const long long int N = 2e5 + 1;
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long int exp(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n = n / 2;
  }
  return res;
}
char a[51][51];
map<pair<long long int, long long int>,
    vector<pair<long long int, long long int> > >
    v;
long long int flag = 0;
long long int vis[51][51] = {0};
void dfs(pair<long long int, long long int> x,
         pair<long long int, long long int> parent) {
  vis[x.first][x.second] = 1;
  for (auto i : v[x]) {
    if (a[x.first][x.second] == a[i.first][i.second] &&
        vis[i.first][i.second] == 0)
      dfs(i, x);
    else if (a[x.first][x.second] == a[i.first][i.second] && i != parent &&
             flag == 0) {
      flag = 1;
      cout << "Yes";
      return;
    }
  }
}
void null() {
  long long int i, j, k, n, m;
  char h;
  cin >> n >> m;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> a[i][j];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (i - 1 > 0) v[{i, j}].push_back({i - 1, j});
      if (i + 1 < n) v[{i, j}].push_back({i + 1, j});
      if (j - 1 > 0) v[{i, j}].push_back({i, j - 1});
      if (j + 1 < m) v[{i, j}].push_back({i, j + 1});
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!flag) {
        memset(vis, 0, sizeof vis);
        dfs({i, j}, {i, j});
      } else
        break;
    }
  }
  if (!flag) cout << "No";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  clock_t start, end;
  start = clock();
  cout << fixed << setprecision(3);
  while (t--) {
    null();
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
}
