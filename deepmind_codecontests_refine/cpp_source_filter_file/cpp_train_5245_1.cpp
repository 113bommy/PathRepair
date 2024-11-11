#include <bits/stdc++.h>
using namespace std;
int n, m, head[500050], num, ans[1000050], anum, cnt[1000050], sta[1000050],
    rd[1000005], t;
struct mp {
  int to, nxt;
} p[1000050];
struct node {
  int z, wz;
};
vector<node> v[100050];
vector<int> rk[100050];
bool cmp(node al, node bl) { return al.z < bl.z; }
void add(int from, int to) {
  p[++num].nxt = head[from];
  p[num].to = to;
  head[from] = num;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) v[i].push_back((node){0, 0}), rk[i].push_back(0);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int u;
      scanf("%d", &u);
      v[i].push_back((node){u, j});
    }
  for (int i = 1; i <= n; i++) sort(v[i].begin() + 1, v[i].end(), cmp);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if ((v[i][j].z > v[i][j - 1].z || j == 1) && v[i][j].z != -1)
        rk[i].push_back(++cnt[i]);
      else
        rk[i].push_back(cnt[i]);
    }
  int temp = m;
  for (int i = 1; i <= n; i++) {
    int l = temp;
    for (int j = 1; j <= m; j++) {
      if (rk[i][j] > 1) add(i * m + rk[i][j] - 1, v[i][j].wz), rd[v[i][j].wz]++;
      if (rk[i][j] && rk[i][j] < rk[i][m])
        add(v[i][j].wz, i * m + rk[i][j]), rd[i * m + rk[i][j]]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!rd[i]) sta[++t] = i;
  while (t > 0) {
    int x = sta[t];
    if (x && x <= m) ans[++anum] = x;
    t--;
    for (int i = head[x]; i; i = p[i].nxt) {
      rd[p[i].to]--;
      if (!rd[p[i].to]) sta[++t] = p[i].to;
    }
  }
  if (anum != m) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
}
