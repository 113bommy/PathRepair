#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[500010], y[500010];
bitset<2010> A[2010];
void Work() {
  for (int i = 1; i <= n; i++) {
    int t = i;
    for (int j = i + 1; j <= n; j++)
      if (A[j][i]) t = j;
    swap(A[i], A[t]);
    for (int j = 1; j <= n; j++)
      if (A[j][i] && j != i) A[j] ^= A[i];
  }
  for (int i = 1; i <= m; i++)
    if (A[y[i]][x[i] + n])
      puts("NO");
    else
      puts("YES");
}
void Init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    A[x[i]][y[i]] = 1;
  }
  for (int i = 1; i <= n; i++) A[i][i + n] = 1;
}
int main() {
  Init();
  Work();
  return 0;
}
