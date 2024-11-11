#include <bits/stdc++.h>
using namespace std;
int K = 1e9 + 7;
long long int mu(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int q = mu(a, n / 2);
  if (n % 2 == 0) return q * q % K;
  return q * q % K * a % K;
}
const int I2 = mu(2, K - 2);
const int N = 1 << 18;
void FWT(int *a, int n, bool inv, int op) {
  for (int i = 1; 2 * i <= n; i <<= 1) {
    for (int j = 0; j < n; j += 2 * i) {
      for (int k = 0; k < i; k++) {
        int x = a[j + k];
        int y = a[i + j + k];
        if (!inv) {
          if (op == 1) a[j + k] = (x + y) % K, a[i + j + k] = (x - y + K) % K;
          if (op == 2) a[j + k] = (x + y) % K;
          if (op == 3) a[i + j + k] = (x + y) % K;
        } else {
          if (op == 1)
            a[j + k] = 1ll * I2 * (x + y) % K,
                  a[i + j + k] = 1ll * I2 * (x - y + K) % K;
          if (op == 2) a[j + k] = (x - y + K) % K;
          if (op == 3) a[i + j + k] = (y - x + K) % K;
        }
      }
    }
  }
}
void multiply(int *a, int *b, int *c, int n, int op) {
  static int A[N], B[N];
  for (int i = 0; i < n; i++) A[i] = a[i], B[i] = b[i];
  FWT(A, n, 0, op);
  FWT(B, n, 0, op);
  for (int i = 0; i < n; i++) c[i] = 1ll * A[i] * B[i] % K;
  FWT(c, n, 1, op);
}
int a[45][200005], b[45][200005];
struct Edge {
  int u, v, c;
};
vector<Edge> backEdges;
vector<pair<int, int> > adj[100005];
vector<int> cycle[45];
int vs[100005], h[100005], p[100005], edgeLen[100005];
void dfs(int u) {
  vs[u] = 1;
  for (auto i : adj[u]) {
    if (i.first == p[u]) continue;
    if (vs[i.first]) {
      if (u < i.first) backEdges.push_back({u, i.first, i.second});
    } else {
      p[i.first] = u;
      h[i.first] = h[u] + 1;
      edgeLen[i.first] = i.second;
      dfs(i.first);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int xorAll = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
    xorAll ^= c;
  }
  h[1] = 1;
  dfs(1);
  int numCycle = 0;
  for (auto e : backEdges) {
    int curU = e.u, curV = e.v;
    numCycle++;
    cycle[numCycle].push_back(e.c);
    if (h[curU] > h[curV]) swap(curU, curV);
    while (h[curV] > h[curU]) {
      cycle[numCycle].push_back(edgeLen[curV]);
      curV = p[curV];
    }
    while (curU != curV) {
      cycle[numCycle].push_back(edgeLen[curU]);
      cycle[numCycle].push_back(edgeLen[curV]);
      curU = p[curU];
      curV = p[curV];
    }
  }
  for (int i = 1; i <= numCycle; i++) {
    for (auto j : cycle[i]) {
      a[i][j]++;
      b[i][j]++;
    }
  }
  a[0][0] = 1;
  b[0][0] = 1;
  int MAXN = (1 << 17);
  for (int i = 0; i <= numCycle; i++) {
    FWT(a[i], MAXN, 0, 1);
  }
  for (int i = 1; i <= numCycle; i++) {
    for (int j = 0; j <= MAXN - 1; j++) {
      a[0][j] = a[0][j] * 1ll * a[i][j] % K;
    }
  }
  FWT(a[0], MAXN, 1, 1);
  K = 77886769;
  for (int i = 0; i <= numCycle; i++) {
    FWT(b[i], MAXN, 0, 1);
  }
  for (int i = 1; i <= numCycle; i++) {
    for (int j = 0; j <= MAXN - 1; j++) {
      b[0][j] = b[0][j] * 1ll * b[i][j] % K;
    }
  }
  FWT(b[0], MAXN, 1, 1);
  int minVal = 1000000000;
  int cnt = 0;
  for (int i = 0; i <= MAXN - 1; i++) {
    if (!a[0][i] && !b[0][i]) continue;
    if (minVal > (i ^ xorAll)) {
      minVal = i ^ xorAll;
      cnt = a[0][i];
    }
  }
  cout << minVal << " " << cnt << endl;
  return 0;
}
