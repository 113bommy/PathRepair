#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 1510;
const long long Inf = 4e6, Sed = 2333, Mod = 1e9 + 7;
const int Prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};
map<long long, int> mp;
int stk[N], divd[N], top;
int num[9][N], rec[12][N];
int cnt[N];
int dis[M][M], tmp[M], temp[N];
void Init(int now, int div, long long prob) {
  if (now == 9) {
    divd[++top] = div;
    for (int i = 0; i <= 8; i++) num[i][top] = stk[i];
    long long hash = 0;
    for (int i = 1; i <= 8; i++)
      if (stk[i]) {
        hash = (hash * Sed % Mod + stk[i]) % Mod;
      }
    mp[hash] = top;
    return;
  }
  for (int i = 0, sz = stk[now - 1]; i <= sz; i++) {
    stk[now] = i;
    Init(now + 1, div * (i + 1), prob);
    prob *= Prime[now];
    if (prob > Inf) break;
  }
}
int ls[11];
int GetIndex(int x) {
  int now = x;
  memset(ls, 0, sizeof(ls));
  for (int i = 1, j; i <= cnt[x]; i++) {
    j = rec[i][x];
    while (!(now % j)) now /= j, ++ls[i];
  }
  sort(ls + 1, ls + cnt[x] + 1);
  long long hash = 0;
  for (int i = cnt[x]; i >= 1; i--) hash = (hash * Sed % Mod + ls[i]) % Mod;
  return mp[hash];
}
void Floyd() {
  for (int k = 1; k <= top; k++) {
    for (int i = 1; i <= top; i++) {
      if (i == k || dis[i][k] >= 100) continue;
      for (int j = 1; j <= top; j++) {
        if (i == j || j == k || dis[k][j] > 100) continue;
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1; i <= top; i++) {
    for (int j = 1; j <= top; j++) tmp[j] = dis[i][j], dis[i][j] = 1e9;
    for (int j = 1; j <= top; j++)
      dis[i][divd[j]] = min(dis[i][divd[j]], tmp[j]);
  }
  for (int i = 2, j; i < N; i++) {
    if (cnt[i]) continue;
    j = i;
    while (j + 5 < N) rec[++cnt[j]][j] = i, j += i;
  }
}
bool vis[N];
int sze;
void Init_Bef() {
  stk[0] = 30;
  Init(1, 1, 1);
  memset(dis, 63, sizeof(dis));
  for (int i = 1; i <= top; i++) dis[i][i] = 0;
  for (int i = 1; i <= top; i++) {
    for (int j = 1; j <= 8; j++) {
      if (num[j][i] + 1 > num[j - 1][i]) continue;
      long long hash = 0;
      ++num[j][i];
      for (int k = 1; k <= 8; k++)
        if (num[k][i]) hash = (hash * Sed % Mod + num[k][i]) % Mod;
      --num[j][i];
      if (mp.count(hash)) {
        int idx = mp[hash];
        dis[idx][i] = dis[i][idx] = 1;
      }
    }
  }
  Floyd();
  for (int i = 1; i <= top; i++)
    if (!vis[divd[i]]) vis[divd[i]] = 1, temp[++sze] = divd[i];
}
int T, x, y;
int main() {
  Init_Bef();
  for (scanf("%d", &T); T--;) {
    scanf("%d%d", &x, &y);
    x = GetIndex(x);
    y = GetIndex(y);
    int ans = 1e9;
    for (int i = 1; i <= sze; i++)
      ans = min(ans, dis[x][temp[i]] + dis[y][temp[i]]);
    printf("%d\n", ans);
  }
  return 0;
}
