#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 100005;
int prime[1100000], primesize;
bool isprime[11000000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long f[N], invf[N];
void getlist(int listsize) {
  memset(isprime, 1, sizeof(isprime));
  isprime[1] = false;
  for (int i = 2; i <= listsize; i++) {
    if (isprime[i]) prime[++primesize] = i;
    for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++) {
      isprime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}
long long fpow(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * a) % mod;
    k >>= 1;
    a = a * a % mod;
  }
  return res;
}
void init(int n) {
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i % mod;
  }
  invf[n] = fpow(f[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) {
    invf[i] = invf[i + 1] * (i + 1) % mod;
  }
}
long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return f[n] * invf[k] % mod * invf[n - k] % mod;
}
char g[1005][1005];
long long vis[1005][1005];
long long ans[1005][1005];
queue<pair<long long, long long>> q;
void dfs(int x, int y) {
  vis[x][y] = 1;
  ans[x][y] = 0;
  q.push(make_pair(x, y));
  for (int i = 0; i <= 3; i++) {
    long long xx = x + dx[i];
    long long yy = y + dy[i];
    if (g[xx][yy] == g[x][y] && !vis[xx][yy]) {
      dfs(xx, yy);
    }
  }
}
void bfs() {
  while (!q.empty()) {
    pair<long long, long long> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    for (int k = 0; k <= 3; k++) {
      int xx = x + dx[k];
      int yy = y + dy[k];
      if (g[xx][yy] != -1 && ans[x][y] + 1 < ans[xx][yy]) {
        q.push(make_pair(xx, yy));
        ans[xx][yy] = ans[x][y] + 1;
      }
    }
  }
}
void solve() {
  long long inf = 0x3f3f3f3f3f3f3f3f;
  memset(ans, inf, sizeof(ans));
  long long n, m, p;
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    cin >> g[i] + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      g[i][j] -= '0';
    }
  }
  for (int i = 1; i <= m; i++) {
    g[0][i] = g[n + 1][i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    g[i][m + 1] = g[i][0] = -1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= 3; k++) {
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (g[xx][yy] == g[i][j]) {
          dfs(i, j);
          break;
        }
      }
    }
  }
  bfs();
  while (p--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (ans[a][b] == inf) {
      cout << int(g[a][b]) << endl;
    } else {
      if (ans[a][b] >= c) {
        cout << int(g[a][b]) << endl;
      } else if ((c - ans[a][b]) % 2) {
        cout << 1 - int(g[a][b]) << endl;
      } else {
        cout << int(g[a][b]) << endl;
      }
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
