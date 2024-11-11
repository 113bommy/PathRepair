#include <bits/stdc++.h>
int graph[1005][1005], H[1005][1005], W[10005];
int n, m, i, a, b, j, parca, t;
void push(int a, int b) {
  for (int i = 1; i <= n; i++)
    if (i != a and H[i][b]) graph[a][i] = graph[i][a] = 1;
}
void parcaBul(int a) {
  for (int j = 1; j <= n; j++)
    if (graph[a][j] and !W[j]) W[j] = 1, parcaBul(j);
}
int main() {
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    t += !a;
    for (j = 1; j <= a; j++) {
      scanf("%d", &b);
      H[i][b] = 1;
      push(i, b);
    }
  }
  for (i = 1; i <= n; i++)
    if (!W[i]) {
      parca++;
      W[i] = 1;
      parcaBul(i);
    }
  printf("%d\n", t != m ? parca - 1 : n);
  return 0;
}
