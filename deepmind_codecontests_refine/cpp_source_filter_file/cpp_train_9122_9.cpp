#include <bits/stdc++.h>
using namespace std;
long long int add(long long int a, long long int b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
long long int sub(long long int a, long long int b) {
  return (a % 1000000007 - b % 1000000007 + 1000000007) % 1000000007;
}
long long int mul(long long int a, long long int b) {
  return (a % 1000000007 * b % 1000000007) % 1000000007;
}
long long int poww(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long int poww(long long int a, long long int b, long long int MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
      res %= MOD;
    }
    a = a * a;
    a %= MOD;
    b >>= 1;
  }
  return res;
}
const int N = 105;
int dp[N][N][26][2];
int vis[N][N][26][2];
std::vector<std::pair<int, int> > gr[N];
int go(int u, int v, int t, int c) {
  int curr = u;
  if (t) curr = v;
  int f = 0;
  for (auto x : gr[curr]) {
    if (x.second >= c) {
      f = 1;
      break;
    }
  }
  if (f == 0) return f;
  if (vis[u][v][t][c]) return dp[u][v][t][c];
  vis[u][v][t][c] = true;
  int ans;
  ans = 0;
  for (auto x : gr[curr]) {
    if (x.second >= c) {
      int _u = u, _v = v;
      if (t == 0) {
        _u = x.first;
      } else {
        _v = x.first;
      }
      if (go(_u, _v, 1 - t, x.second) == 0) {
        ans = 1;
        break;
      }
    }
  }
  return dp[u][v][t][c] = ans;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int u, v;
  char ch;
  for (int i = 0; i <= m - 1; i++) {
    cin >> u >> v >> ch;
    gr[u].push_back(make_pair(v, int(ch - 'a')));
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int ans = go(i, j, 0, 0);
      if (ans)
        cout << "A";
      else
        cout << "B";
    }
    cout << '\n';
  }
  return 0;
}
