#include <bits/stdc++.h>
using namespace std;
struct SAM_node {
  int minlen, maxlen, slink;
  int trans[4];
  inline void reset(int _minlen, int _maxlen, int _slink, int *_trans) {
    minlen = _minlen, maxlen = _maxlen, slink = _slink;
    for (int i = 0; i < 4; i++) trans[i] = _trans[i];
    return;
  }
};
struct matrix {
  long long g[4][4];
};
SAM_node SAM[300000];
matrix basic, result;
int g[300000], h[300000], p[300000];
char c[120000];
int i, j, k, n, head, tail, sum_node;
long long m, t, l, r, mid;
char cc, cd;
inline matrix operator*(matrix x, matrix y) {
  matrix z;
  memset(z.g, 63, sizeof(z.g));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        z.g[i][j] = min(z.g[i][j], x.g[i][k] + y.g[k][j]);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (z.g[i][j] > 1e18) z.g[i][j] = 1e18 + 1;
  return z;
}
inline void buildSAM() {
  scanf("%I64d", &m);
  scanf("%s", c + 1);
  n = strlen(c + 1);
  SAM[0].slink = -1;
  for (i = 1; i <= n; i++) {
    sum_node++;
    SAM[sum_node].maxlen = i;
    p[i] = sum_node;
    for (j = p[i - 1]; (j != -1) && (!SAM[j].trans[c[i] - 65]);
         j = SAM[j].slink)
      SAM[j].trans[c[i] - 65] = sum_node;
    if (j == -1) {
      SAM[sum_node].slink = 0;
      SAM[sum_node].minlen = 1;
      continue;
    }
    k = SAM[j].trans[c[i] - 65];
    if (SAM[j].maxlen + 1 == SAM[k].maxlen) {
      SAM[sum_node].slink = k;
      SAM[sum_node].minlen = SAM[k].maxlen + 1;
      continue;
    }
    sum_node++;
    SAM[sum_node].reset(-1, SAM[j].maxlen + 1, SAM[k].slink, SAM[k].trans);
    SAM[sum_node].minlen = SAM[SAM[sum_node].slink].maxlen + 1;
    SAM[p[i]].slink = sum_node;
    SAM[p[i]].minlen = SAM[sum_node].maxlen + 1;
    SAM[k].slink = sum_node;
    SAM[k].minlen = SAM[sum_node].maxlen + 1;
    for (; (j != -1) && (SAM[j].trans[c[i] - 65] == k); j = SAM[j].slink)
      SAM[j].trans[c[i] - 65] = sum_node;
  }
  return;
}
inline void buildfirstmatrix() {
  for (cc = 'A'; cc <= 'D'; cc++) {
    if (!SAM[0].trans[cc - 65]) {
      for (cd = 'A'; cd <= 'D'; cd++) basic.g[cc - 65][cd - 65] = 1;
      continue;
    }
    for (cd = 'A'; cd <= 'D'; cd++) basic.g[cc - 65][cd - 65] = n + 1;
    memset(h, 0, sizeof(h));
    tail = 1, g[tail] = SAM[0].trans[cc - 65], h[g[tail]] = 1;
    for (head = 1; head <= tail; head++)
      for (cd = 'A'; cd <= 'D'; cd++)
        if (!SAM[g[head]].trans[cd - 65])
          basic.g[cc - 65][cd - 65] =
              min(basic.g[cc - 65][cd - 65], 1LL * h[g[head]]);
        else if (!h[SAM[g[head]].trans[cd - 65]])
          tail++, g[tail] = SAM[g[head]].trans[cd - 65],
                  h[g[tail]] = h[g[head]] + 1;
  }
  return;
}
inline matrix matrixpower(long long m) {
  if (m == 1) return basic;
  matrix z = matrixpower(m / 2);
  z = z * z;
  if (m & 1) z = z * basic;
  return z;
}
inline void getans() {
  l = 1, r = 1e18;
  while (l < r) {
    mid = (l + r) / 2;
    result = matrixpower(mid);
    t = 1e18 + 1;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) t = min(t, result.g[i][j]);
    if (t >= m)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d", l);
  return;
}
int main() {
  buildSAM();
  buildfirstmatrix();
  getans();
  return 0;
}
