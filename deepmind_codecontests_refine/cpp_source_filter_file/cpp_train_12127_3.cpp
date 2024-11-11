#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 100;
char x[M], p[M];
int n, m, q;
const int maxN = 1e6 + 100;
int Z[maxN];
void ZF() {
  for (int i = 1, l = 0, r = 0; i < m; i++) {
    if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
    while (i + Z[i] < m && p[Z[i]] == p[i + Z[i]]) ++Z[i];
    if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
  }
}
int main() {
  scanf("%d", &n), scanf("%d", &q);
  scanf(" %s", p);
  m = strlen(p);
  ZF();
  int s = -1e9, e = -1e9;
  for (int i = 0; i < q; ++i) {
    int v;
    scanf("%d", &v);
    if (v <= e) {
      if (Z[v - s] < e - v + 1) return puts("0");
      for (int j = e + 1; j < v + m; j++) x[j] = p[j - v];
    } else
      for (int j = v; j < v + m; j++) x[j] = p[j - v];
    s = v;
    e = v + m - 1;
  }
  int out = 1, mod = 1e9 + 7;
  for (int i = 0; i < n; ++i)
    if (!x[i]) out = (1LL * out * 26) % mod;
  cout << out << endl;
}
