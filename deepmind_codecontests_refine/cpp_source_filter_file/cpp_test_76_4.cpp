#include <bits/stdc++.h>
using namespace std;
inline bool Read(int &a) { return scanf("%d", &a) != EOF; }
inline bool Read(int &a, int &b) { return scanf("%d%d", &a, &b) != EOF; }
inline bool Read(int &a, int &b, int &c) {
  return scanf("%d%d%d", &a, &b, &c) != EOF;
}
inline bool Read(int &a, int &b, int &c, int &d) {
  return scanf("%d%d%d%d", &a, &b, &c, &d) != EOF;
}
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
long long g[50];
long long revg[50];
int N, M;
int d = 0;
bool dfs(bool connect, int u, int cnt, long long edges, long long tmp,
         long long &ans) {
  if (cnt == 5) {
    ans = tmp;
    return true;
  }
  long long e = edges;
  while (e > 0) {
    int v = __builtin_ctzll(e);
    e ^= 1LL << v;
    if (v == 0 || u == v) continue;
    long long gv = connect ? g[v] : revg[v];
    if (dfs(connect, v, cnt + 1, edges & gv, tmp | (1 << v), ans)) {
      return true;
    }
  }
  return false;
}
int Process() {
  while (Read(N, M)) {
    N = min(48, N);
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= N; i++) {
      revg[i] = ((1LL << (N + 1)) - 1) ^ (1LL << i);
    }
    for (int _i = 0; _i < M; _i++) {
      int u, v;
      Read(u, v);
      if (u <= 48 && v <= 48 && u != v) {
        g[u] |= 1LL << v;
        g[v] |= 1LL << u;
        revg[u] ^= 1LL << v;
        revg[v] ^= 1LL << u;
      }
    }
    long long ans;
    bool bFound = false;
    for (int i = 1; i <= N; i++) {
      long long tmp = 1LL << i;
      if (dfs(true, i, 1, g[i], tmp, ans)) {
        bFound = true;
        break;
      }
      if (dfs(false, i, 1, revg[i], tmp, ans)) {
        bFound = true;
        break;
      }
    }
    if (bFound) {
      for (int i = 1; i <= 48; i++) {
        if (ans & (1LL << i)) {
          printf("%d ", i);
        }
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  return Process();
}
