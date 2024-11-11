#include <bits/stdc++.h>
using namespace std;
const int maxn = 1234567;
bool vis[maxn];
int ai[maxn];
int n;
void init() {
  memset(ai, 0, sizeof(ai));
  memset(vis, 0, sizeof(vis));
  int u;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &u);
    vis[u] = 1;
  }
}
void play() {
  for (int i = 2; i <= 1000000; i++) {
    if (!vis[i]) continue;
    ai[i]++;
    for (int j = 2; j <= 1000000; j++) {
      long long cmp = ((long long)(i)) * j;
      if (cmp > 1000000) break;
      ai[i * j] = max(ai[i], ai[i * j]);
    }
  }
  int MAX = 0;
  for (int i = 1; i <= 1000000; i++) {
    MAX = max(MAX, ai[i]);
  }
  printf("%d\n", MAX);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    play();
  }
  return 0;
}
