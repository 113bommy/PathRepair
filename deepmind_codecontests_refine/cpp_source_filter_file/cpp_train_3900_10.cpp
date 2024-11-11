#include <bits/stdc++.h>
using namespace std;
vector<int> ar[1000001];
int a2d[1001][1001];
long long vis[1000001] = {0}, vis2d[1001][1001] = {0};
int dis[1000001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
long long n, m, q, k, p, t;
bool isValid(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return false;
  if (vis2d[x][y]) return false;
  return true;
}
void dfs(int node) {
  vis[node] = 1;
  for (int child : ar[node]) {
    if (!vis[child]) dfs(child);
  }
}
void dfsongrid(int x, int y) {
  vis2d[x][y] = 1;
  for (int i = 0; i < 4; i++)
    if (isValid(x + dx[i], y + dy[i])) dfsongrid(x + dx[i], y + dy[i]);
}
void bfs(int n) {
  queue<int> q;
  q.push(n);
  vis[n] = 1;
  dis[n] = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int c : ar[curr]) {
      if (vis[c] == 0) {
        q.push(c);
        dis[c] = dis[curr] + 1;
        vis[c] = 1;
      }
    }
  }
}
long long bin(long long i) {
  long long j, sum = 0, t;
  vector<int> v;
  while (i != 0) {
    t = i % 2;
    v.push_back(t);
    i = i / 2;
  }
  reverse(v.begin(), v.end());
  for (j = 0; j < v.size(); j++) {
    sum = sum + ((v[j]) * pow(10, v.size() - j - 1));
  }
  return sum;
}
long long A[101][101], I[101][101];
void mul(long long A[][101], long long B[][101], long long dim) {
  long long res[dim + 1][dim + 1];
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      res[i][j] = 0;
      for (int k = 0; k < dim; k++)
        res[i][j] =
            (res[i][j] % 1000000007 +
             (A[i][k] % 1000000007) * (B[k][j] % 1000000007) % 1000000007) %
            1000000007;
    }
  }
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++) A[i][j] = res[i][j];
}
void power(long long A[][101], long long dim, long long n) {
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++) {
      if (i == j)
        I[i][j] = 1;
      else
        I[i][j] = 0;
    }
  while (n) {
    if (n % 2)
      mul(I, A, dim), n--;
    else
      mul(A, A, dim), n /= 2;
  }
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++) A[i][j] = I[i][j];
}
long long phi_a(long long n) {
  long long res = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      res /= i;
      res *= i - 1;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res /= n, res *= n - 1;
  return (res);
}
int fi[1000001];
void phi() {
  for (int i = 1; i < 1000001; i++) fi[i] = i;
  for (int i = 2; i < 1000001; i++) {
    if (fi[i] == i) {
      for (int j = i; j < 1000001; j += i) {
        fi[j] /= i;
        fi[j] *= (i - 1);
      }
    }
  }
}
int primes[1000001] = {0};
void sieve() {
  primes[0] = primes[1] = 1;
  for (int i = 2; i * i < 1000001; i++) {
    if (!primes[i])
      for (int j = i * i; j < 1000001; j += i) primes[j] = 1;
  }
}
int col[1000001], leaf[1000001];
void lea(int n) {
  vis[n] = 1;
  for (int child : ar[n]) {
    if (!vis[child]) {
      lea(child);
      leaf[n] += leaf[child];
    }
  }
  if (ar[n].size() == 1 && n != 1) leaf[n] = 1;
}
int main() {
  cout.precision(15);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int a[n][n], b[n][n], c[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j], b[i][j] = 0, c[i][j] = 0;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = i; j < n; j++) {
      b[0][i] += a[c][j];
      c++;
    }
  }
  for (int i = 0; i < n; i++) {
    int c = 1;
    for (int j = i + 1; j < n; j++) {
      b[c][j] = b[0][i];
      c++;
    }
  }
  for (int i = 1; i < n; i++) {
    int c = 0;
    for (int j = i; j < n; j++) {
      b[i][0] += a[j][c];
      c++;
    }
  }
  for (int i = 0; i < n; i++) {
    int c = 1;
    for (int j = i + 1; j < n; j++) {
      b[j][c] = b[i][0];
      c++;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int d = 0;
    for (int j = i; j >= 0; j--) {
      c[0][i] += a[d][j];
      d++;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    int d = 0;
    for (int j = i; j >= 0; j--) {
      c[d][j] = c[0][i];
      d++;
    }
  }
  for (int i = 1; i < n; i++) {
    int d = n - 1;
    for (int j = i; j < n; j++) {
      c[i][n - 1] += a[j][d];
      d--;
    }
  }
  for (int i = 1; i < n; i++) {
    int d = n - 1;
    for (int j = i; j < n; j++) {
      c[j][d] = c[i][n - 1];
      d--;
    }
  }
  vector<int> v;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) b[i][j] += c[i][j], b[i][j] -= a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) v.push_back(b[i][j]);
  long long ans = 0;
  long long ma = -1, p, q, r, s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i][j] > ma && (i + j) % 2 == 0) {
        ma = b[i][j];
        p = i + 1, q = j + 1;
      }
    }
  }
  ans += ma;
  ma = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (b[i][j] > ma && (i + j) % 2) {
        ma = b[i][j];
        r = i + 1, s = j + 1;
      }
    }
  }
  ans += ma;
  cout << ans << endl << p << " " << q << " " << r << " " << s;
  return 0;
}
