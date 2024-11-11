#include <bits/stdc++.h>
using namespace std;
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
const long long N = 2e3 + 10;
const long long M = 1e18 + 7;
const long long H = 1e9 + 9;
const long long base = 131;
long long logx(long long a, long long bs) { return log(a) / log(bs); }
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long Min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long big_mul(long long a, long long b, long long m) {
  long long x = 0, y = a % m;
  while (b > 0) {
    if (b & 1) x = (x + y) % m;
    y = (2 * y) % m;
    b >>= 1;
  }
  return x % m;
}
long long big_mod(long long a, long long b, long long m) {
  long long x = 1, y = a % m;
  while (b > 0) {
    if (b & 1) x = (x * y) % m;
    y = (y * y) % m;
    b >>= 1;
  }
  return x % m;
}
long long Big_mod(long long a, long long b, long long m) {
  long long x = 1, y = a % m;
  while (b > 0) {
    if (b & 1) x = big_mul(x, y, m);
    y = big_mul(y, y, m);
    b >>= 1;
  }
  return x % m;
}
long long mod_inverse(long long a, long long m) { return big_mod(a, m - 2, m); }
long long GCD(long long a, long long b) {
  if (!a) return b;
  return GCD(b % a, a);
}
vector<bool> vis(N);
vector<bool> boss;
vector<int> level(N);
vector<vector<int> > vec(N);
void dfs(int x, int cnt) {
  vis[x] = true;
  level[x] = cnt;
  for (int i = 0; i < vec[x].size(); i++) {
    int p = vec[x][i];
    if (vis[p] == false) dfs(p, cnt + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > 0)
      vec[a].push_back(i + 1);
    else
      boss.push_back(i + 1);
  }
  for (int i = 0; i < boss.size(); i++) {
    int p = boss[i];
    if (vis[p] == false) dfs(p, 1);
  }
  int ans = 0;
  for (int i = 1; i < n + 1; i++) ans = max(ans, level[i]);
  cout << ans << endl;
  return 0;
}
