#include <bits/stdc++.h>
using namespace std;
int N, M, K, o, flagG, flagR, pG, pR, pK, flag;
char st[105];
int sm[105], a[105];
int main() {
  scanf("%d %d %d", &N, &M, &K);
  flagG = 0, flagR = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%s", st);
    pG = pR = pK = -1;
    for (int j = 0; j < M; j++) {
      if (st[j] == 'G') pG = j;
      if (st[j] == 'R') pR = j;
      if (st[j] == '-') pK = 1;
    }
    if ((pG == -1) && (pR != -1) && (pK != -1)) flagR = 1;
    if ((pG != -1) && (pR == -1) && (pK != -1)) flagG = 1;
    if ((pG != -1) && (pR != -1)) ++o, a[o] = int(abs(pG - pR)) - 1;
  }
  if ((flagR == 1) && (flagG == 1))
    cout << "Draw" << endl;
  else if (flagG == 1)
    cout << "First" << endl;
  else if (flagR == 1)
    cout << "Second" << endl;
  else {
    memset(sm, 0, sizeof(sm));
    for (int i = 1; i <= o; i++) {
      for (int j = 1; j <= 30; j++) sm[j] += a[i] % 2, a[i] /= 2;
    }
    flag = 1;
    for (int i = 1; i <= 30; i++)
      if (sm[i] % (K + 1) != 0) flag = 0;
    if (flag == 0)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
