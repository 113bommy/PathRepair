#include <bits/stdc++.h>
using namespace std;
int g[1010];
int mark[2010];
int save[1010];
int bin[1100];
int num[1100];
int find(int x) {
  if (x == bin[x]) return x;
  return bin[x] = find(bin[x]);
}
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &g[i]);
  }
  for (int i = 0; i <= n; i++) {
    num[i] = 1;
    bin[i] = i;
  }
  int flag = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i] != 0) {
      int a = find(i);
      int b = find(g[i]);
      bin[a] = b;
      num[b] = num[a] + num[b];
      num[a] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (bin[i] == i && find(x) != i) {
      save[cnt++] = num[i];
    }
  }
  memset(mark, 0, sizeof(mark));
  mark[0] = 1;
  for (int i = 0; i < cnt; i++) {
    for (int j = 1000; j >= 0; j--) {
      if (mark[j] == 1) {
        mark[j + save[i]] = 1;
      }
    }
  }
  int sum = 0;
  while (g[x]) {
    sum++;
    x = g[x];
  }
  for (int i = 0; i <= n; i++)
    if (mark[i] == 1) printf("%d\n", sum + i + 1);
  return 0;
}
