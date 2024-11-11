#include <bits/stdc++.h>
using namespace std;
int e[300005][3];
int b[300005], s[300005];
int q[10000006];
int n, m, a, c;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a, &c);
    e[a][s[a]++] = c;
    e[c][s[c]++] = a;
  }
  int h = 0, t = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] > 1) q[t++] = i;
  }
  int i, cnt;
  for (; h < t; ++h) {
    i = q[h];
    cnt = 0;
    for (int j = 0; j < s[i]; ++j)
      if (b[e[i][j]] == b[i]) ++cnt;
    if (cnt <= 1) continue;
    b[i] = 1 ^ b[i];
    for (int j = 0; j < s[i]; ++j)
      if (s[e[i][j]] > 1 && b[e[i][j]] == b[i]) {
        q[t++] = e[i][j];
      }
  }
  for (int i = 1; i <= n; ++i) cout << b[i];
  cout << endl;
  return 0;
}
