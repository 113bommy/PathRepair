#include <bits/stdc++.h>
using namespace std;
const double pi = 2.0 * acos(0.0);
const double eps = 1.0e-9;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
const int dr6[] = {1, 1, 0, -1, -1, 0}, dc6[] = {0, 1, 1, 0, -1, -1};
const int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool t[64][64][64][64];
int main(void) {
  int kase = 1000000000;
  for (int ks = 1, n; ks <= kase && 1 == scanf("%d", &n); ++ks) {
    char s[64][4] = {{0}};
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    memset(t, false, sizeof(t));
    t[n][n > 0 ? (n - 1) : n][n > 1 ? (n - 2) : n][n > 2 ? (n - 3) : n] = true;
    for (int i = n; i-- > 1;)
      for (int u = 0; u <= n; ++u)
        for (int v = 0; v <= n; ++v)
          for (int w = 0; w <= n; ++w)
            if (t[i + 1][u][v][w]) {
              int j = i > 2 ? (i - 3) : n;
              if (s[u][0] == s[v][0] || s[u][1] == s[v][1])
                t[i][u][w][j] = true;
              if (s[u][0] == s[j][0] || s[u][1] == s[v][1])
                t[i][v][w][u] = true;
            }
    bool yes = false;
    for (int i = 0; i < n; ++i)
      if (t[1][i][n][n]) yes = true;
    puts(yes ? "YES" : "NO");
  }
  return 0;
}
