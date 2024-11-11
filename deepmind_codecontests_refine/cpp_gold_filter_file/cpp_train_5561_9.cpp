#include <bits/stdc++.h>
using namespace std;
long long odp = 0;
int n, m, k;
char a[2510][2510];
int S[2510][2510];
int g[2510][8], d[2510][8];
int l[2510][8], p[2510][8];
int Sum(int r1, int r2, int c1, int c2) {
  int s = S[r2][c2];
  if (r1 != 0) s -= S[r1 - 1][c2];
  if (c1 != 0) s -= S[r2][c1 - 1];
  if (r1 != 0 && c1 != 0) s += S[r1 - 1][c1 - 1];
  return s;
}
void rec(int r1, int r2, int c1, int c2) {
  if (r1 == r2 || c1 == c2) {
    vector<int> jed;
    if (r1 == r2) {
      jed.push_back(c1 - 1);
      for (int i = c1; i <= c2; ++i)
        if (a[r1][i] == '1') jed.push_back(i);
      jed.push_back(c2 + 1);
    } else {
      jed.push_back(r1 - 1);
      for (int i = r1; i <= r2; ++i)
        if (a[i][c1] == '1') jed.push_back(i);
      jed.push_back(r2 + 1);
    }
    if (k == 0) {
      for (int i = 0; i < jed.size() - 1; ++i) {
        int d = jed[i + 1] - jed[i] - 1;
        odp += d * (d - 1) / 2 + d;
      }
    } else {
      for (int i = 1; i < jed.size() - 1; ++i)
        if (i + k < jed.size())
          odp += (jed[i] - jed[i - 1]) * (jed[i + k] - jed[i + k - 1]);
    }
    return;
  }
  if (r2 - r1 >= c2 - c1) {
    int s = (r1 + r2) / 2;
    for (int i = c1; i <= c2; ++i) {
      for (int j = 0; j < k + 2; ++j) {
        g[i][j] = r1;
        d[i][j] = r2;
      }
    }
    for (int i = c1; i <= c2; ++i) {
      for (int j = c1; j <= i; ++j) {
        for (int o = 0; o <= k + 1; ++o) {
          while (g[j][o] <= s && Sum(g[j][o], s, j, i) >= o) ++g[j][o];
          --g[j][o];
          if (g[j][o] < r1) g[j][o] = r1;
          while (d[j][o] >= s + 1 && Sum(s + 1, d[j][o], j, i) >= o) --d[j][o];
          ++d[j][o];
          if (d[j][o] > r2) d[j][o] = r2;
        }
        for (int ilG = 0; ilG <= k; ++ilG) {
          int ilD = k - ilG;
          if (Sum(g[j][ilG], s, j, i) == ilG &&
              Sum(s + 1, d[j][ilD], j, i) == ilD) {
            int mnoG = (Sum(g[j][ilG + 1], s, j, i) != Sum(g[j][ilG], s, j, i))
                           ? g[j][ilG] - g[j][ilG + 1]
                           : g[j][ilG] - r1 + 1;
            int mnoD =
                (Sum(s + 1, d[j][ilD + 1], j, i) != Sum(s + 1, d[j][ilD], j, i))
                    ? d[j][ilD + 1] - d[j][ilD]
                    : r2 - d[j][ilD] + 1;
            odp += mnoG * mnoD;
          }
        }
      }
    }
    rec(r1, s, c1, c2);
    rec(s + 1, r2, c1, c2);
  } else {
    int s = (c1 + c2) / 2;
    for (int i = r1; i <= r2; ++i) {
      for (int j = 0; j < k + 2; ++j) {
        l[i][j] = c1;
        p[i][j] = c2;
      }
    }
    for (int i = r1; i <= r2; ++i) {
      for (int j = r1; j <= i; ++j) {
        for (int o = 0; o <= k + 1; ++o) {
          while (l[j][o] <= s && Sum(j, i, l[j][o], s) >= o) ++l[j][o];
          --l[j][o];
          if (l[j][o] < c1) l[j][o] = c1;
          while (p[j][o] >= s + 1 && Sum(j, i, s + 1, p[j][o]) >= o) --p[j][o];
          ++p[j][o];
          if (p[j][o] > c2) p[j][o] = c2;
        }
        for (int ilL = 0; ilL <= k; ++ilL) {
          int ilP = k - ilL;
          if (Sum(j, i, l[j][ilL], s) == ilL &&
              Sum(j, i, s + 1, p[j][ilP]) == ilP) {
            int mnoL = (Sum(j, i, l[j][ilL + 1], s) != Sum(j, i, l[j][ilL], s))
                           ? l[j][ilL] - l[j][ilL + 1]
                           : l[j][ilL] - c1 + 1;
            int mnoP =
                (Sum(j, i, s + 1, p[j][ilP + 1]) != Sum(j, i, s + 1, p[j][ilP]))
                    ? p[j][ilP + 1] - p[j][ilP]
                    : c2 - p[j][ilP] + 1;
            odp += mnoL * mnoP;
          }
        }
      }
    }
    rec(r1, r2, c1, s);
    rec(r1, r2, s + 1, c2);
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%s", a[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      S[i][j] = a[i][j] - '0';
      if (i != 0) S[i][j] += S[i - 1][j];
      if (j != 0) S[i][j] += S[i][j - 1];
      if (i != 0 && j != 0) S[i][j] -= S[i - 1][j - 1];
    }
  }
  rec(0, n - 1, 0, m - 1);
  printf("%I64d", odp);
  return 0;
}
