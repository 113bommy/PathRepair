#include <bits/stdc++.h>
using namespace std;
const int N = 404;
char s[N][N + N], ps[N];
bitset<N> G[26][N], ans[N];
int n, m;
bitset<N> shf(bitset<N> &x, int p) { return (x << (m - p)) | (x >> p); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) ans[i] = ~ans[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) G[s[i][j] - 'a'][i].set(j);
  int pn, pm;
  scanf("%d%d", &pn, &pm);
  for (int pi = 0; pi < pn; pi++) {
    scanf("%s", ps);
    for (int pj = 0; pj < pm; pj++)
      if (ps[pj] != '?')
        for (int i = 0; i < n; i++)
          ans[i] &= shf(G[ps[pj] - 'a'][(i + pi) % n], pj);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d", int(ans[i][j]));
    printf("\n");
  }
  return 0;
}
