#include <bits/stdc++.h>
using namespace std;
int cur, num, msk;
bool adj[250][250];
void dfs(int nd, int dep, int sep) {
  if (dep > 30) return;
  adj[nd][cur] = true;
  adj[cur][nd] = true;
  adj[nd][cur + 1] = true;
  adj[cur + 1][nd] = true;
  adj[cur][cur + 2] = true;
  adj[cur + 2][cur] = true;
  adj[cur + 1][cur + 2] = true;
  adj[cur + 2][cur + 1] = true;
  if (msk & (1 << dep)) {
    adj[nd][sep] = true;
    adj[sep][nd] = true;
  }
  nd = cur + 2;
  cur += 3;
  dfs(nd, dep + 1, sep + 2);
}
int main() {
  scanf("%d", &num);
  cur = 3;
  for (int i = 0; i < (int)100; i++) {
    adj[cur][cur + 1] = true;
    adj[cur + 1][cur] = true;
    cur++;
  }
  adj[cur][2] = true;
  adj[2][cur] = true;
  cur++;
  for (int i = 30; i >= 0; i--) {
    if (num > (1 << i)) continue;
    num -= (1 << i);
    msk |= (1 << i);
  }
  dfs(1, 0, 3);
  printf("249\n");
  for (int i = 1; i < (int)250; i++) {
    for (int j = 1; j < (int)250; j++) printf("%c", adj[i][j] ? 'Y' : 'N');
    puts("");
  }
  return 0;
}
