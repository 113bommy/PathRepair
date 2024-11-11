#include <bits/stdc++.h>
using namespace std;
int setBit(int n, int pos) { return n = n | (1 << pos); }
int resetBit(int n, int pos) { return n = n & ~(1 << pos); }
bool checkBit(long long n, long long pos) { return (bool)(n & (1LL << pos)); }
struct data {
  int v, c;
};
bool operator<(data a, data b) { return a.c < b.c; }
vector<data> ed[105];
int dp[105][105][30][3];
bool vis[105][105][30][3];
int call(int x, int y, int last, int turn) {
  if (vis[x][y][last][turn]) return dp[x][y][last][turn];
  vis[x][y][last][turn] = true;
  int ret = 0;
  if (turn == 0) {
    for (int i = 0; i < ed[x].size(); i++) {
      if (ed[x][i].c >= last) {
        ret |= call(ed[x][i].v, y, ed[x][i].c, !turn);
      }
    }
  } else {
    for (int i = 0; i < ed[y].size(); i++) {
      if (ed[y][i].c >= last) {
        ret |= call(x, ed[y][i].v, ed[y][i].c, !turn);
      }
    }
  }
  return dp[x][y][last][turn] = !ret;
}
char str[5];
int main() {
  int n, m, c, u, v;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    scanf("%s", str);
    c = str[0];
    ed[u].push_back({v, c});
  }
  for (int i = 1; i <= n; i++) {
    sort(ed[i].begin(), ed[i].end());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (call(i, j, 0, 0))
        printf("B");
      else
        printf("A");
    }
    puts("");
  }
  return 0;
}
