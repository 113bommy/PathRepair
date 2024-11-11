#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const long long mod = 1e9 + 7;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
const int maxn = 100005;
vector<long long> v[maxn];
long long coloridx[maxn];
long long color[3][maxn];
long long dfs(int u, int fa, int val1, int val2) {
  int val3 = 3 - val1 - val2;
  coloridx[u] = val3;
  long long ans = color[val3][u - 1];
  for (auto x : v[u]) {
    if (x != fa) ans += dfs(x, u, val3, val1);
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> color[i][j];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  long long root = -1;
  for (long long i = 1; i < n + 1; i++) {
    if (v[i].size() > 2) {
      cout << -1 << "\n";
      return;
    }
    if (v[i].size() == 1) root = i;
  }
  long long ans = LLONG_MAX;
  long long ansi = -1, ansj = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        long long tmp = dfs(root, root, i, j);
        if (tmp < ans) {
          ans = tmp;
          ansi = i;
          ansj = j;
        }
      }
    }
  }
  dfs(root, root, ansi, ansj);
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    cout << coloridx[i] + 1 << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
