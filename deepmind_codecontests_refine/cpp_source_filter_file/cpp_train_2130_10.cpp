#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x[3];
} p[8];
map<long long, int> M;
int vis[60];
long long dis(const Point &a, const Point &b) {
  long long res = 0;
  for (int i = 0; i < 3; i++) {
    res += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
  }
  return res;
}
void dfs(int now) {
  if (now == 8) {
    M.clear();
    int id = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 7; i++) {
      for (int j = i + 1; j < 8; j++) {
        long long res = dis(p[i], p[j]);
        if (!M.count(res)) M[res] = id++;
        vis[M[res]]++;
        if (id > 3) return;
      }
      if (id > 3) return;
    }
    sort(vis, vis + 3);
    if (vis[0] == 4 && vis[1] == 12 && vis[2] == 12) {
      puts("YES");
      for (int i = 0; i < 8; i++) {
        printf("%d %d %d\n", p[i].x[0], p[i].x[1], p[i].x[2]);
      }
      exit(0);
    }
    return;
  }
  do {
    dfs(now + 1);
  } while (next_permutation(p[now].x, p[now].x + 3));
}
int main() {
  for (int i = 0; i < 8; i++) {
    scanf("%d%d%d", &p[i].x[0], &p[i].x[1], &p[i].x[2]);
    sort(p[i].x, p[i].x + 3);
  }
  dfs(0);
  puts("NO");
  return 0;
}
