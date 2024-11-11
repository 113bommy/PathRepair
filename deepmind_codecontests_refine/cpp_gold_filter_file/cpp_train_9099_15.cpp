#include <bits/stdc++.h>
using namespace std;
int n, m, ns, key, T, V;
int chosen[1000006];
int t[7005], l[7005], r[7005], x[7005];
int p[200000];
int id[200000];
int nn = 0, value[7005], f[7005][7005];
int pos[7005];
int get(int c, int k) {
  if (k > pos[c]) {
    for (int i = pos[c] + 1; i <= k; i++) f[c][i] = p[f[c][i - 1]];
    pos[c] = k;
  }
  return f[c][k];
}
int find(int x, int k) {
  if (k == 0) return x;
  int c = 0;
  if (id[x] == 0)
    nn++, id[x] = nn, c = nn, value[nn] = x, pos[nn] = 1, f[c][1] = p[x];
  else
    c = id[x];
  return get(c, k);
}
int main() {
  int k = 1, I = 0;
  for (int i = 1; i <= 110000; i++) {
    if (i == k)
      k *= 2, p[I + 1] = i, p[I + 2] = i, I += 2;
    else
      p[I + 1] = i, I++;
  }
  cin >> n >> m;
  ns = 0;
  key = 0;
  memset(chosen, 0, sizeof(chosen));
  for (int i = 1; i <= m; i++) {
    scanf("%d", &k);
    if (k == 1) {
      ns++;
      scanf("%d%d%d%d", &t[ns], &l[ns], &r[ns], &x[ns]);
    } else if (k == 2) {
      scanf("%d%d", &T, &V);
      int res = 0;
      key++;
      for (int i = 1; i <= ns; i++)
        if (t[i] >= T) {
          int L = find(l[i], t[i] - T);
          int R = find(r[i], t[i] - T);
          if (L <= V && V <= R) {
            if (chosen[x[i]] < key) res++, chosen[x[i]] = key;
          }
        }
      printf("%d\n", res);
    }
  }
  return 0;
}
