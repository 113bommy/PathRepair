#include <bits/stdc++.h>
using namespace std;
vector<long long> ar[1000001];
int a2d[1001][1001], seg_tree[400004];
long long vis[1000001], vis2d[1001][1001];
int dis[1000001];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
long long n, m, a, k, p, t, b;
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
int l = 0;
void dfsongrid(int x, int y) {
  vis2d[x][y] = 1;
  for (int i = 0; i < 4; i++)
    if (isValid(x + dx[i], y + dy[i]) && a2d[x + dx[i]][y + dy[i]] == '.')
      dfsongrid(x + dx[i], y + dy[i]);
}
void bfson2d(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  vis2d[x][y] = 1;
  l++;
  while (!q.empty()) {
    int curx = q.front().first, cury = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (isValid(curx + dx[i], cury + dy[i]) &&
          a2d[curx + dx[i]][cury + dy[i]] == '.') {
        if (k == p - l) return;
        q.push(make_pair(curx + dx[i], cury + dy[i]));
        vis2d[curx + dx[i]][cury + dy[i]] = 1;
        l++;
      }
    }
  }
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
long long modInverse(long long a) {
  long long modu = 1000000007;
  long long m0 = modu;
  long long y = 0, x = 1;
  while (a > 1) {
    long long q = a / modu;
    long long t = modu;
    modu = a % modu;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int adj[1001][1001];
int in[1001], out[1001];
vector<long long> path(0);
void dfspipes(int node) {
  vis[node]++;
  for (int i : ar[node]) {
    if (!vis[i]) dfspipes(i);
  }
  path.push_back(node);
}
int main() {
  cout.precision(18);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> k;
    ar[a].push_back(b);
    in[b]++;
    out[a]++;
    adj[a][b] = k;
  }
  vector<long long> node(0);
  ;
  for (int i = 0; i < n; i++) {
    if (out[i] && !in[i]) {
      node.push_back(i);
    }
  }
  cout << node.size() << endl;
  for (int i = 0; i < node.size(); i++) {
    dfspipes(node[i]);
    cout << path.back() << " " << path.front() << " ";
    int dia = INT_MAX;
    for (int i = path.size() - 1; i > 0; i--)
      dia = min(dia, adj[path[i]][path[i - 1]]);
    cout << dia << endl;
    path.clear();
  }
  return 0;
}
