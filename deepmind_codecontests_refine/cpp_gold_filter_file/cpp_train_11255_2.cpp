#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, a[maxn], mp[maxn][maxn], now, fk = 0;
bool vis[maxn];
vector<int> que[maxn];
void solve(int x, int id) {
  que[id].push_back(x);
  for (int i = a[x]; i != x; i = a[i]) que[id].push_back(i), vis[i] = 1;
  for (int i = 1; i <= que[id].size(); i++)
    if (a[que[id][i - 1]] == 1) fk = id;
}
void getans(int id) {
  int las = now, S = que[id].size();
  for (int i = S - 1; i >= 1; i--, now--)
    if (que[id][(i + 1) % S] < que[id][i])
      mp[now][que[id][i]] = 2, mp[now][que[id][(i + 1) % S]] = 2;
    else
      mp[now][que[id][i]] = 1, mp[now][que[id][(i + 1) % S]] = 1;
  if (que[id][0] != 1 && S > 1) {
    mp[las][1] = 2, mp[now][1] = 1, mp[now][que[id][1]] = 1, now--;
  }
}
char get(int x) {
  if (x == 0) return '.';
  if (x == 1) return '/';
  return 92;
}
int main() {
  scanf("%d", &n);
  bool pd = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pd |= (a[i] != i);
  if (!pd) {
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf(".");
      puts("");
    }
    return 0;
  }
  printf("%d\n", n - 1);
  now = n;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) solve(i, ++m);
  if (fk) swap(que[fk], que[m]);
  for (int i = 1; i <= m; i++) getans(i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar(get(mp[i][j]));
    puts("");
  }
  return 0;
}
