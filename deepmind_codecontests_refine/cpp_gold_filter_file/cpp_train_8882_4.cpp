#include <bits/stdc++.h>
using namespace std;
int n, m, d[1111 << 1];
char s[1111][1111];
int main() {
  scanf(" %d %d ", &n, &m);
  for (int i = 0; i < n; i++) scanf(" %s ", &s[i]);
  for (int i = 0; i < 1111 * 2; i++) d[i] = 1000111222;
  set<pair<int, int> > q;
  d[0] = 0;
  q.insert(pair<int, int>(0, 0));
  while (!q.empty()) {
    pair<int, int> u = *q.begin();
    q.erase(u);
    int k = u.second;
    if (k < n) {
      for (int j = 0; j < m; j++)
        if (s[k][j] == '#' && d[j + n] > d[k] + 1) {
          if (d[j + n] != 1000111222) q.erase(pair<int, int>(d[j + n], j + n));
          d[j + n] = d[k] + 1;
          q.insert(pair<int, int>(d[j + n], j + n));
        }
    } else {
      for (int i = 0; i < n; i++)
        if (s[i][k - n] == '#' && d[i] > d[k] + 1) {
          if (d[i] != 1000111222) q.erase(pair<int, int>(d[i], i));
          d[i] = d[k] + 1;
          q.insert(pair<int, int>(d[i], i));
        }
    }
  }
  if (d[n - 1] == 1000111222) d[n - 1] = -1;
  printf("%d\n", d[n - 1]);
  return 0;
}
