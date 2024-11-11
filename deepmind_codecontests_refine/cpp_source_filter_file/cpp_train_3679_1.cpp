#include <bits/stdc++.h>
using namespace std;
const int T = 10005, M = 100000, F = 27, INF = 1000000007;
int k, m, top, p[T], f[F + 5];
int x[10];
int d[T][F + 5];
char c[M];
int min(int x, int y) {
  if (x < y) return x;
  return y;
}
int max(int x, int y) {
  if (x > y) return x;
  return y;
}
int res[M];
char st[2 * M];
int z[3 * M], ar[T][5];
vector<char> s[T];
vector<char> t[F + 5];
int funktion(int u, int v, int in);
int solve(int a1, int a2, int q, int ar0, int ar1) {
  int j;
  x[0] = ar0;
  x[1] = ar1;
  res[1] = a1;
  res[2] = a2;
  for (j = 3; j <= q; ++j) {
    res[j] = (res[j - 1] + res[j - 2] + x[j]) % INF;
  }
  return res[q];
}
int main() {
  int i, j;
  scanf("%d%d", &k, &m);
  for (i = 1; i <= m; ++i) {
    c[0] = '\0';
    scanf("%s", c);
    p[i] = strlen(c);
    for (j = 0; j < p[i]; ++j) {
      s[i].push_back(c[j]);
    }
  }
  t[1].push_back('a');
  t[2].push_back('b');
  for (i = 1; i <= m; ++i) {
    if (p[i] == 1) {
      if (s[i][0] == t[1][0]) {
        d[i][1] = 1;
      }
      if (s[i][0] == t[2][0]) {
        d[i][2] = 1;
      }
    }
  }
  for (i = 3; i <= F; ++i) {
    t[i] = t[i - 1];
    for (j = 0; j < (int)t[i - 2].size(); ++j) {
      t[i].push_back(t[i - 2][j]);
    }
    for (j = 1; j <= m; ++j) {
      d[j][i] = d[j][i - 1] + d[j][i - 2] + funktion(i - 1, i - 2, j);
    }
  }
  for (i = 1; i <= m; ++i) {
    ar[i][0] = funktion(F, F, i);
    ar[i][1] = funktion(F - 1, F, i);
    ar[i][2] = funktion(F, F - 1, i);
  }
  for (i = 1; i <= m; ++i) {
    d[i][F + 1] = d[i][F] + d[i][F - 1] + ar[i][2];
  }
  if (k <= F + 1) {
    for (i = 1; i <= m; ++i) {
      printf("%d\n", d[i][k]);
    }
    return 0;
  }
  for (i = 1; i <= m; ++i) {
    res[F - 1] = d[i][F - 1];
    res[F] = d[i][F];
    res[F + 1] = d[i][F + 1];
    printf("%d\n", solve(res[F], res[F + 1], k - F + 1, ar[i][0], ar[i][1]));
  }
  return 0;
}
int funktion(int u, int v, int e) {
  int j, i, q;
  top = 0;
  for (j = 0; j < (int)s[e].size(); ++j) {
    st[top] = s[e][j];
    top++;
  }
  st[top] = '#';
  top++;
  for (j = max(t[u].size() - s[e].size() + 1, 0); j < (int)t[u].size(); ++j) {
    st[top] = t[u][j];
    top++;
  }
  for (j = 0; j < min(t[v].size(), s[e].size() - 1); ++j) {
    st[top] = t[v][j];
    top++;
  }
  for (i = 1; i < top; ++i) {
    j = z[i - 1];
    while (j > 0 && st[j] != st[i]) {
      j = z[j - 1];
    }
    if (st[i] == st[j]) {
      j++;
    }
    z[i] = j;
  }
  q = 0;
  for (i = s[e].size(); i < top; ++i) {
    if (z[i] == s[e].size()) q++;
  }
  return q;
}
