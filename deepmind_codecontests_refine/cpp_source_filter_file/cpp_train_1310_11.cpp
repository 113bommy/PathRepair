#include <bits/stdc++.h>
using namespace std;
int N, M, edg;
vector<int> g[1010101];
long long deg[1010101], loop, lv[1010101];
bool vis[1010101];
void DFS(int n) {
  vis[n] = true;
  if (lv[n]) edg++;
  for (int next : g[n]) {
    if (vis[next]) continue;
    edg++;
    DFS(next);
  }
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
      loop++;
      lv[a]++;
      continue;
    }
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (vis[i]) continue;
    edg = 0;
    DFS(i);
    if (edg) cnt++;
  }
  if (cnt > 1) return !printf("0");
  long long res = 0;
  res += loop * (loop - 1) / 2;
  res += loop * (M - 1);
  for (int i = 1; i <= N; i++) res += deg[i] * (deg[i] - 1) / 2;
  printf("%lld", res);
  return 0;
}
