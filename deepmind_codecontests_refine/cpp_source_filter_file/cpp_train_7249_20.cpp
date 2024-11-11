#include <bits/stdc++.h>
using namespace std;
int x, k, n, Q, nd, val[10], sp[500];
int cnt[256], id[256];
map<int, int> mp;
struct mat {
  long long a[75][75];
  mat() { memset(a, 30, sizeof(a)); }
  mat operator*(const mat &b) const {
    mat ans;
    for (int i = (int)(1); i <= (int)(nd); i++)
      for (int j = (int)(1); j <= (int)(nd); j++)
        for (int k = (int)(1); k <= (int)(nd); k++)
          ans.a[i][j] = min(ans.a[i][j], a[i][k] + b.a[k][j]);
    return ans;
  }
} ans, tr;
mat power(mat a, int b) {
  mat ans;
  for (int i = (int)(1); i <= (int)(nd); i++) ans.a[i][i] = 0;
  for (; b; b /= 2, a = a * a)
    if (b & 1) ans = ans * a;
  return ans;
}
int main() {
  scanf("%d%d%d%d", &x, &k, &n, &Q);
  for (int i = (int)(1); i <= (int)(k); i++) scanf("%d", &val[i]);
  for (int i = (int)(0); i <= (int)((1 << k) - 1); i++)
    cnt[i] = cnt[i / 2] + (i & 1);
  for (int i = (int)(0); i <= (int)((1 << k) - 1); i++)
    if (cnt[i] == x) id[i] = ++nd;
  for (int i = (int)(0); i <= (int)((1 << k) - 1); i++)
    if (id[i])
      if (!(i & 1))
        tr.a[id[i]][id[i / 2]] = 0;
      else
        for (int j = (int)(1); j <= (int)(k); j++)
          if (!(i & (1 << j))) tr.a[id[i]][id[(i + (1 << j)) / 2]] = val[j];
  for (int i = (int)(1); i <= (int)(Q); i++) {
    int x, v;
    scanf("%d%d", &x, &v);
    for (int j = (int)(1); j <= (int)(k); j++) sp[++*sp] = x - j;
    mp[x] = v;
  }
  sp[++*sp] = n - x + 1;
  sp[++*sp] = 0;
  sort(sp + 1, sp + *sp + 1);
  *sp = unique(sp + 1, sp + *sp + 1) - sp - 1;
  for (; sp[*sp] != n - x + 1; --*sp)
    ;
  mat ans;
  ans.a[1][id[(1 << x) - 1]] = 0;
  for (int p = (int)(2); p <= (int)(*sp); p++) {
    ans = ans * power(tr, sp[p] - sp[p - 1] - 1);
    if (p == *sp) break;
    mat ttmp;
    for (int i = (int)(0); i <= (int)((1 << k) - 1); i++)
      if (id[i])
        if (!(i & 1))
          ttmp.a[id[i]][id[i / 2]] = 0;
        else
          for (int j = (int)(1); j <= (int)(k); j++)
            if (!(i & (1 << j)))
              ttmp.a[id[i]][id[(i + (1 << j)) / 2]] = val[j] + mp[sp[p] + j];
    ans = ans * ttmp;
  }
  long long res = ans.a[1][id[(1 << x) - 1]];
  printf("%lld\n", res);
}
