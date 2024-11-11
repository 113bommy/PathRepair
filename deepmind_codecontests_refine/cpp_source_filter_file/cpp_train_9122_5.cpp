#include <bits/stdc++.h>
using namespace std;
int mic[105][105][27][2];
int g[105][105];
int n, m, u, v;
char c;
int dp(int ma, int lu, int la, int tu) {
  if (mic[ma][lu][la][tu] != -1) return mic[ma][lu][la][tu];
  set<int> ava;
  for (int i = 1; i <= n; i++) {
    if (tu == 0) {
      if (g[ma][i] >= la) ava.insert(i);
    } else {
      if (g[lu][i] >= la) ava.insert(i);
    }
  }
  if (ava.empty()) {
    if (tu == 0)
      return mic[ma][lu][la][tu] = 1;
    else
      return mic[ma][lu][la][tu] = 0;
  }
  int k;
  if (tu == 0) {
    k = 1;
    for (int i : ava) {
      k = (k && (dp(i, lu, g[ma][i], 1)));
    }
  } else {
    k = 0;
    for (int i : ava) {
      k = (k || (dp(ma, i, g[lu][i], 0)));
    }
  }
  return mic[ma][lu][la][tu] = k;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(g, -1, sizeof g);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %c", &u, &v, &c);
    g[u][v] = c;
  }
  memset(mic, -1, sizeof mic);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp(i, j, 0, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (mic[i][j][0][0] == 0)
        putchar('A');
      else if (mic[i][j][0][0] == 1)
        putchar('B');
    }
    printf("\n");
  }
}
