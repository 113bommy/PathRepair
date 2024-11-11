#include <bits/stdc++.h>
int dd[3000][3000], DFN[1000000], LOW[1000000], Dindex, Stap[1000000], Bcnt,
    Belong[1000000], instack[1000000], Stop, n, x, y;
void tarjan(int i) {
  int j;
  DFN[i] = LOW[i] = ++Dindex;
  instack[i] = true;
  Stap[++Stop] = i;
  for (int j = 1; j <= n; j++)
    if (i != j && dd[i][j]) {
      if (!DFN[j]) {
        tarjan(j);
        if (LOW[j] < LOW[i]) LOW[i] = LOW[j];
      } else if (instack[j] && DFN[j] < LOW[i])
        LOW[i] = DFN[j];
    }
  if (DFN[i] == LOW[i]) {
    Bcnt++;
    do {
      j = Stap[Stop--];
      instack[j] = false;
      Belong[j] = Bcnt;
    } while (j != i);
  }
}
void solve() {
  int i;
  Stop = Bcnt = Dindex = 0;
  memset(DFN, 0, sizeof(DFN));
  for (i = 1; i <= n; i++)
    if (!DFN[i]) tarjan(i);
  if (Bcnt == 1)
    puts("YES");
  else
    puts("No");
}
int main() {
  scanf("%d", &n);
  for (x = 1; x <= n; x++)
    for (y = 1; y <= n; y++) scanf("%d", &dd[x][y]);
  solve();
}
