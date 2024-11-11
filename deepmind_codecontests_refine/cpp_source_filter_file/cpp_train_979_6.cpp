#include <bits/stdc++.h>
using namespace std;
int n, m, c[150], s[150];
int main() {
  int cnt = 0, p = 0, q = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    int tmp = m / 2;
    for (int j = 0; j < m; j++) {
      scanf("%d", &c[j]);
      if (j <= tmp)
        p += c[j];
      else
        q += c[j];
    }
    if (m & 1) {
      p -= c[tmp];
      s[cnt++] = c[tmp];
    }
  }
  sort(s, s + cnt, greater<int>());
  for (int i = 0; i < cnt; i++) {
    if (i & 1)
      q += s[i];
    else
      p += s[i];
  }
  printf("%d %d\n", p, q);
  return 0;
}
