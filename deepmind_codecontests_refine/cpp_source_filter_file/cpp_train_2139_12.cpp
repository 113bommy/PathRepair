#include <bits/stdc++.h>
using namespace std;
const int maxn = 4003;
static int opt[maxn][maxn], t1, t2, t3, t4, N1[maxn][210], N2[maxn][210];
char S1[maxn], S2[maxn];
int main() {
  scanf("%d%d%d%d\n", &t1, &t2, &t3, &t4);
  gets(S1 + 1);
  gets(S2 + 1);
  int L1 = strlen(S1 + 1);
  int L2 = strlen(S2 + 1);
  memset(opt, 10, sizeof(opt));
  opt[0][0] = 0;
  for (int i = L1; i; i--) {
    memcpy(N1[i], N1[i + 1], sizeof(N1[i + 1]));
    N1[i][S1[i]] = i;
  }
  for (int i = L2; i; i--) {
    memcpy(N2[i], N2[i + 1], sizeof(N2[i + 1]));
    N2[i][S2[i]] = i;
  }
  for (int i = 0; i <= L1; i++)
    for (int j = 0; j <= L2; j++) {
      if (i) opt[i][j] = min(opt[i - 1][j] + t2, opt[i][j]);
      if (j) opt[i][j] = min(opt[i][j - 1] + t1, opt[i][j]);
      if (i && j) {
        opt[i][j] = min(opt[i][j], opt[i - 1][j - 1] + (S1[i] != S2[j]) * t3);
        if (N1[i][S2[j]] && N2[j][S1[i]] && (S1[i] != S2[j])) {
          int k1 = N1[i][S2[j]], k2 = N2[j][S1[i]];
          opt[k1][k2] = min(opt[k1][k2], opt[i - 1][j - 1] + (k1 - i - 1) * t1 +
                                             (k2 - j - 1) * t2 + t4);
        }
      }
    }
  printf("%d\n", opt[L1][L2]);
  return 0;
}
