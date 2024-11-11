#include <bits/stdc++.h>
using namespace std;
const int nmax = 1 << 12;
const int vmax = 100;
int w[20];
char s[20];
int f[nmax + 1];
pair<int, int> v[nmax + 1];
int sol[nmax + 1][vmax + 2];
int main() {
  int n, m, q;
  fscanf(stdin, "%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) fscanf(stdin, "%d", &w[i]);
  for (int i = 1; i <= m; ++i) {
    fscanf(stdin, "%s", s);
    int x = 0;
    for (int j = 0; j < n; ++j) x += (1 << j) * (s[j] - '0');
    ++f[x];
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      int sum = 0;
      for (int k = 0; k < n; ++k) {
        if ((i & (1 << k)) == (j & (1 << k))) sum += w[k];
      }
      sol[i][min(sum, vmax + 1)] += f[j];
    }
    for (int j = 1; j <= vmax; ++j) sol[i][j] += sol[i][j - 1];
  }
  for (int i = 1; i <= q; ++i) {
    int k;
    fscanf(stdin, "%s%d", s, &k);
    int x = 0;
    for (int j = 0; j < n; ++j) x += (1 << j) * (s[j] - '0');
    fprintf(stdout, "%d\n", sol[x][k]);
  }
  return 0;
}
