#include <bits/stdc++.h>
using namespace std;
int n, m, d[1111 << 1];
char s[1111][1111];
int main() {
  scanf(" %d %d ", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %s ", &s[i]);
  for (int i = 0; i < 1111; i++) d[i] = 1000111222;
  queue<int> q;
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u < n) {
      for (int j = 0; j < m; j++)
        if (s[u][j] == '#' && d[j + n] == 1000111222) {
          d[j + n] = d[u] + 1;
          q.push(j + n);
        }
    } else {
      for (int i = 0; i < n; i++)
        if (s[i][u - n] == '#' && d[i] == 1000111222) {
          d[i] = d[u] + 1;
          q.push(i);
        }
    }
  }
  if (d[n - 1] == 1000111222) d[n - 1] = -1;
  printf("%d\n", d[n - 1]);
  return 0;
}
