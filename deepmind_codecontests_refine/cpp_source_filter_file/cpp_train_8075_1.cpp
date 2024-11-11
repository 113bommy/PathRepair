#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
const int N = 1e5;
const int M = 10;
int a[N];
vector<int> g[N];
long long ans = 0;
int b[N][M];
long long cur[M][2], dp[N][M][2], dep[N][M][2];
void dfscalc(int v, int pr = -1) {
  for (int i = 0; i < M; i++) {
    int bt = ((a[v] & (1 << i)) > 0);
    b[v][i] = bt;
    dep[v][i][bt] = 1;
  }
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == pr) {
      continue;
    }
    dfscalc(to, v);
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        dep[v][j][first ^ b[v][j]] += dep[to][j][first];
      }
    }
  }
}
void dfs(int v, int pr = -1) {
  for (int i = 0; i < M; i++) {
    ans += (dep[v][i][1] + (pr == -1 ? 0 : cur[i][1])) * (1 << i);
  }
  for (int i = 0; i < M; i++) {
    cur[i][b[v][i]]++;
  }
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == pr) {
      continue;
    }
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur[j][first ^ b[v][j]] += dep[to][j][first];
      }
    }
  }
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == pr) {
      continue;
    }
    int cur1[M][2], cur2[M][2];
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur1[j][first] = cur[j][first];
        cur2[j][first] = 0;
      }
    }
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur[j][first ^ b[v][j]] -= dep[to][j][first];
      }
    }
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur2[j][first ^ b[to][j]] += cur[j][first];
      }
    }
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur[j][first] = cur2[j][first];
      }
    }
    dfs(to, v);
    for (int j = 0; j < M; j++) {
      for (int first = 0; first < 2; first++) {
        cur[j][first] = cur1[j][first];
      }
    }
  }
  for (int i = 0; i < M; i++) {
    cur[i][b[v][i]]--;
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int q, w;
    cin >> q >> w;
    q--;
    w--;
    g[q].push_back(w);
    g[w].push_back(q);
  }
  dfscalc(0);
  dfs(0);
  cout << (ans + sum) / 2;
}
