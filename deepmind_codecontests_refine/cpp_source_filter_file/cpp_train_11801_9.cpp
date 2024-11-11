#include <bits/stdc++.h>
using namespace std;
int dy[1 << 16][300];
int n, K, m;
int nxt[500010][20];
string ch[20];
string prob[500010];
int inv[1 << 16][20];
int answer[1], pos, sim;
bool flag;
int main(void) {
  int i, j, k, r;
  cin >> n;
  for (i = 0; i < n; i++) cin >> ch[i];
  cin >> K;
  for (i = 0; i < (1 << n); i++) {
    for (j = 0; j < n; j++) {
      for (k = j + 1; k < n; k++) {
        if (i & (1 << k)) inv[i][j]++;
      }
    }
  }
  memset(answer, 63, sizeof(answer));
  for (r = 1; r <= K; r++) {
    cin >> m;
    for (i = 1; i <= m; i++) cin >> prob[i];
    memset(nxt, 63, sizeof(nxt));
    for (i = m; i >= 1; i--) {
      for (j = 0; j < n; j++) {
        if (ch[j] == prob[i])
          nxt[i][j] = i;
        else
          nxt[i][j] = nxt[i + 1][j];
      }
    }
    memset(dy, 63, sizeof(dy));
    dy[0][0] = 0;
    for (i = 0; i <= (1 << n) - 1; i++) {
      for (j = 0; j <= n * (n - 1) / 2; j++) {
        if (dy[i][j] == 1061109567) continue;
        for (k = 0; k < n; k++) {
          if (i & (1 << k)) continue;
          if (dy[i | (1 << k)][j + inv[i][k]] > nxt[dy[i][j] + 1][k]) {
            dy[i | (1 << k)][j + inv[i][k]] = nxt[dy[i][j] + 1][k];
          }
        }
      }
    }
    for (i = 0; i < n * (n - 1) / 2; i++) {
      if (dy[(1 << n) - 1][i] != 1061109567 && answer[0] > i) {
        answer[0] = i;
        pos = r;
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    printf("%d\n[:", pos);
    sim = n * (n - 1) / 2 - answer[0] + 1;
    for (; sim--;) {
      printf("|");
    }
    printf(":]\n");
  } else {
    printf("Brand new problem!\n");
  }
  return false;
}
