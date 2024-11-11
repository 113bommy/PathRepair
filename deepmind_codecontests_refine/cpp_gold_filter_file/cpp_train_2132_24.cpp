#include <bits/stdc++.h>
using namespace std;
int N, m;
int p[500];
int g[500][500], f[500][500];
vector<int> prime[101], edge[101], num[101];
int bfs(int g[][500], int f[][500], int src, int sink) {
  int m[6400], u, v;
  for (int i = 0; i < N; i++) {
    p[i] = -1;
  }
  p[src] = -2;
  m[src] = INT_MAX;
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (v = 0; v < N; v++) {
      if (g[u][v] - f[u][v] > 0 && p[v] == -1) {
        p[v] = u;
        m[v] = min(m[u], g[u][v] - f[u][v]);
        if (v != sink) {
          q.push(v);
        } else {
          return m[sink];
        }
      }
    }
  }
  return 0;
}
int max_flow(int g[][500], int f[][500], int src, int sink) {
  int m = 0;
  int flow = 0;
  while (1) {
    m = bfs(g, f, src, sink);
    if (m == 0) {
      break;
    } else {
      flow += m;
      int v = sink, u;
      while (v != src) {
        u = p[v];
        f[u][v] += m;
        f[v][u] -= m;
        v = u;
      }
    }
  }
  return flow;
}
int isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
int vis[100000];
int numbr;
int esize, osize;
vector<int> even, odd, evenidx, oddidx, numv;
void dfs(int root, int prev, int print = 0) {
  vis[root + 1] = 1;
  if (print) {
    if (root < esize)
      cout << evenidx[root] << " ";
    else
      cout << oddidx[root - esize] << " ";
  }
  numbr++;
  for (int i = 1; i <= osize + esize + 1; i++) {
    if (i - 1 == prev) continue;
    if (f[root + 1][i] == 1 && vis[i] == 0) {
      dfs(i - 1, root, print);
    }
  }
}
int main() {
  int n;
  cin >> n;
  int a[1000];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
      evenidx.push_back(i + 1);
    } else {
      odd.push_back(a[i]);
      oddidx.push_back(i + 1);
    }
  }
  esize = even.size();
  osize = odd.size();
  for (int i = 0; i < even.size(); i++) {
    for (int j = 0; j < odd.size(); j++) {
      if (isprime(even[i] + odd[j])) {
        g[i + 1][esize + j + 1] = 1;
      }
    }
  }
  for (int i = 0; i < esize; i++) {
    g[0][i + 1] = 2;
  }
  for (int i = 0; i < osize; i++) {
    g[esize + i + 1][esize + osize + 1] = 2;
  }
  N = esize + osize + 2;
  int fans = 0;
  fans = max_flow(g, f, 0, N - 1);
  if (fans < n) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (f[i][j] == 1) {
        f[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < esize + osize + 1; i++) {
    vis[i] = 0;
  }
  int ct = 0;
  for (int i = 0; i < esize; i++) {
    if (vis[i + 1] == 0) {
      ct++;
      numbr = 0;
      dfs(i, -1, 0);
      numv.push_back(numbr);
    }
  }
  for (int i = 0; i < esize + osize + 1; i++) {
    vis[i] = 0;
  }
  cout << ct << endl;
  int k = 0;
  for (int i = 0; i < esize; i++) {
    if (vis[i + 1] == 0) {
      numbr = 0;
      cout << numv[k] << " ";
      k++;
      dfs(i, -1, 1);
      cout << endl;
    }
  }
  return 0;
}
