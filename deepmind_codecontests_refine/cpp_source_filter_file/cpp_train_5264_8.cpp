#include <bits/stdc++.h>
using namespace std;
void Read(int &n) {
  int sign = 1;
  n = 0;
  char c;
  do {
    c = getchar();
  } while (!isdigit(c) && c != '-');
  if (c == '-') {
    c = getchar();
    sign = -1;
  }
  do {
    n = n * 10 + c - 48;
    c = getchar();
  } while (isdigit(c));
  n *= sign;
}
void Read(long long &n) {
  int sign = 1;
  n = 0;
  char c;
  do {
    c = getchar();
  } while (!isdigit(c) && c != '-');
  if (c == '-') {
    c = getchar();
    sign = -1;
  }
  do {
    n = n * 10ll + c - 48;
    c = getchar();
  } while (isdigit(c));
  n *= sign;
}
void Write(int n) {
  if (n == 0) {
    putchar('0');
    return;
  } else if (n < 0)
    putchar('-'), n = -n;
  char C[30];
  int d = 0;
  while (n) {
    C[++d] = (n % 10) + 48;
    n /= 10;
  }
  for (int i = d; i >= 1; --i) putchar(C[i]);
}
void Write(long long n) {
  if (n == 0) {
    putchar('0');
    return;
  } else if (n < 0)
    putchar('-'), n = -n;
  char C[30];
  int d = 0;
  while (n) {
    C[++d] = (n % 10ll) + 48;
    n /= 10ll;
  }
  for (int i = d; i >= 1; --i) putchar(C[i]);
}
const int maxn = 5e4 + 3;
const int INF = 0x3f3f3f3f;
int A[maxn];
int p[maxn], b[maxn];
int pos[maxn][50];
int n;
struct Matching {
  vector<int> adj[maxn];
  int matchX[maxn], matchY[maxn];
  int d[maxn];
  void Init(int n) {
    for (int i = 1; i <= n; ++i) adj[i].clear();
  }
  void AddEdge(int u, int v) { adj[u].push_back(v); }
  bool BFS() {
    queue<int> Q;
    while (Q.size()) Q.pop();
    d[0] = INF;
    for (int i = 1; i <= n; ++i)
      if (matchX[i] == 0)
        Q.push(i), d[i] = 0;
      else
        d[i] = INF;
    while (Q.size()) {
      int u = Q.front();
      Q.pop();
      if (d[u] >= d[0]) continue;
      for (int k = 0; k < adj[u].size(); ++k) {
        int v = adj[u][k];
        if (d[matchY[v]] == INF) {
          d[matchY[v]] = d[u] + 1;
          Q.push(matchY[v]);
        }
      }
    }
    return d[0] != INF;
  }
  bool DFS(int u) {
    if (u == 0) return 1;
    for (int k = 0; k < adj[u].size(); ++k) {
      int v = adj[u][k];
      if (d[matchY[v]] == d[u] + 1 && DFS(matchY[v])) {
        matchX[u] = v;
        matchY[v] = u;
        return 1;
      }
    }
    d[u] = INF;
    return 0;
  }
  int MaxMatch() {
    int ans = 0;
    memset(matchX, 0, sizeof matchX);
    memset(matchY, 0, sizeof matchY);
    while (BFS())
      for (int i = 1; i <= n; ++i)
        if (matchX[i] == 0) ans += DFS(i);
    return ans;
  }
} G;
bool Check(int V) {
  G.Init(n);
  for (int i = 1; i <= n; ++i) {
    int d = A[i];
    for (int k = 0; k <= 31; ++k) {
      if (d == 0) break;
      if (d <= V) G.AddEdge(i, pos[i][k]);
      d >>= 1;
    }
  }
  return G.MaxMatch() == n;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  vector<int> pre;
  for (int i = 1; i <= n; ++i) {
    int d = A[i];
    while (d) pre.push_back(d), d >>= 1;
  }
  sort(pre.begin(), pre.end());
  pre.resize(unique(pre.begin(), pre.end()) - pre.begin());
  int m = pre.size();
  for (int i = 1; i <= m; ++i) b[i] = pre[i - 1];
  for (int i = 1; i <= n; ++i) {
    int d = A[i];
    for (int k = 0; k <= 31; ++k) {
      if (d == 0) break;
      pos[i][k] = lower_bound(b + 1, b + m + 1, d) - b;
      d >>= 1;
    }
  }
  int l = 1, r = m, f = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (Check(b[m])) {
      f = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  Check(f);
  for (int i = 1; i <= n; ++i) printf("%d ", b[G.matchX[i]]);
}
