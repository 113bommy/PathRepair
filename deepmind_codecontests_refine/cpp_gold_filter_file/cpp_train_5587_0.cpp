#include <bits/stdc++.h>
using namespace std;
int cond = 1;
const int M = 33;
char s[M][M];
int c[M][M], t[M][M];
int szuk(const vector<int>& a, int cc) {
  for (int i = 0; i < (((int)((a).size()))); i++)
    if (a[i] == cc) return i;
  return 0;
}
int main() {
  int n, m, w = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (n); i++) scanf("%s", s[i]);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (s[i][j] != '.' && !c[i][j]) {
        ++w;
        c[i][j] = c[i + 1][j] = c[i][j + 1] = c[i + 1][j + 1] = w;
      }
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (s[i][j] != '.') {
        if (i < n - 1 && s[i + 1][j] == s[i][j]) t[c[i][j]][c[i + 1][j]] = 1;
        if (j < m - 1 && s[i][j + 1] == s[i][j]) t[c[i][j]][c[i][j + 1]] = 1;
      }
  for (typeof(1) i = (1); i <= (w); ++i)
    for (typeof(1) j = (1); j <= (w); ++j)
      if (t[i][j]) t[j][i] = 1;
  vector<int> zz, bezz;
  for (typeof(1) i = (1); i <= (w); ++i)
    if (t[i][i])
      zz.push_back(i);
    else
      bezz.push_back(i);
  int ret = 0;
  vector<int> oz, odp;
  assert(w == 14 && ((int)((zz).size())) <= 7);
  for (int mask = 0; mask < (1 << ((int)((bezz).size()))); mask++)
    if (__builtin_popcount(mask) == 7) {
      vector<int> z, bez;
      for (typeof((zz).begin()) i = ((zz).begin()); i != (zz).end(); ++i)
        z.push_back(*i);
      for (int i = 0; i < (((int)((bezz).size()))); i++)
        if (mask & (1 << i))
          bez.push_back(bezz[i]);
        else
          z.push_back(bezz[i]);
      do {
        int ok = 1;
        for (int i = 0; i < (7); i++)
          for (int j = 0; j < (7); j++)
            if (t[z[i]][z[j]] + t[bez[i]][z[j]] + t[z[i]][bez[j]] +
                    t[bez[i]][bez[j]] ==
                0)
              ok = 0;
        ret += ok;
        if (ok && odp.empty()) odp = bez, oz = z;
      } while (next_permutation((bez).begin(), (bez).end()));
    }
  printf("%d\n", ret / (1 << (((int)((bezz).size())) - 7)) * 5040);
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (s[i][j] != '.')
        s[i][j] = '0' + szuk(oz, c[i][j]) + szuk(odp, c[i][j]);
  for (int i = 0; i < (n); i++) puts(s[i]);
  return 0;
}
