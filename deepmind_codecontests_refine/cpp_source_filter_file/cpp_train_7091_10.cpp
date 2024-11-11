#include <bits/stdc++.h>
using namespace std;
char c[1010];
int h[210], ck[210], d[1010];
long long l;
int st[210], p[1010], tr[210][210], rs[210][210], n, m, N, ans;
inline void Get_arr(int a) {
  for (int i = m; i >= 1; i--) st[i] = a / p[i], a %= p[i];
}
inline int Get_id(int *a) {
  int rs = 0;
  for (int i = 1; i <= m; i++) rs += a[i] * p[i];
  return (rs);
}
inline void Get_tran() {
  p[1] = 1;
  for (int i = 2; i <= m; i++) p[i] = p[i - 1] * d[i - 1];
  N = p[m] * d[m];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++)
      if (h[j]) {
        Get_arr(i);
        for (int k = 1; k <= m; k++)
          if (c[k] - 'A' == j) st[k] = (st[k] + 1) % d[k];
        tr[i][Get_id(st)]++;
      }
  }
}
int a[210], b[210][210];
inline void Pow() {
  for (int i = 0; i < N; i++) rs[i][i] = 1;
  while (l) {
    if (l & 1) {
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) b[i][j] = rs[i][j], rs[i][j] = 0;
      for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
          for (int j = 0; j < N; j++)
            rs[i][j] = (rs[i][j] + b[i][k] * tr[k][j] % 12345) % 12345;
    }
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) b[i][j] = tr[i][j], tr[i][j] = 0;
    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          tr[i][j] = (tr[i][j] + b[i][k] * b[k][j] % 12345) % 12345;
    l /= 2ll;
  }
}
int main() {
  scanf("%I64d%d", &l, &m);
  if (!l) {
    puts("0");
    return (0);
  }
  for (int i = 1; i <= m; i++) {
    c[i] = getchar();
    while ('A' > c[i] || c[i] > 'Z') c[i] = getchar();
    scanf("%d", &d[i]);
    h[c[i] - 'A'] = 1;
  }
  Get_tran();
  Pow();
  for (int i = 0; i < N; i++) {
    Get_arr(i);
    bool jd = 1;
    memset(ck, 0, sizeof(ck));
    for (int j = 1; j <= m; j++)
      if (!st[j]) ck[c[j] - 'A'] = 1;
    for (int j = 0; j < 26; j++)
      if (h[j] && !ck[j]) jd = 0;
    if (jd) ans = (ans + rs[0][i]) % 12345;
  }
  printf("%d\n", ans);
}
