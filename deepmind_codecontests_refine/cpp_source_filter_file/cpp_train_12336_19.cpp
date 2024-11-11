#include <bits/stdc++.h>
using namespace std;
const int M = 1013;
int tt[M][M];
char pop[M][M], s[M], t[M];
vector<pair<string, pair<int, char> > > ret;
int main() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i < (n + 1); ++i)
    for (int j = 0; j < (m + 1); ++j) tt[i][j] = n + m + 7;
  tt[0][0] = 0;
  for (__typeof(0) i = (0); i <= (n); ++i)
    for (__typeof(0) j = (0); j <= (m); ++j) {
      if (i < n && tt[i + 1][j] > tt[i][j] + 1) {
        tt[i + 1][j] = tt[i][j] + 1;
        pop[i + 1][j] = 0;
      }
      if (i < n && j < m && tt[i + 1][j + 1] > tt[i][j] + (s[i] != t[j])) {
        tt[i + 1][j + 1] = tt[i][j] + (s[i] != t[j]);
        pop[i + 1][j + 1] = 2;
      }
      if (j < m && tt[i][j + 1] > tt[i][j] + 1) {
        tt[i][j + 1] = tt[i][j] + 1;
        pop[i][j + 1] = 1;
      }
    }
  printf("%d\n", tt[n][m]);
  while (n || m) {
    int p = pop[n][m];
    if (p == 2) {
      if (t[m - 1] != s[n - 1])
        ret.push_back(make_pair("REPLACE", make_pair(m, t[m - 1])));
      n--;
      m--;
    } else if (p) {
      ret.push_back(make_pair("INSERT", make_pair(m, t[m - 1])));
      m--;
    } else {
      ret.push_back(make_pair("DELETE", make_pair(m, ' ')));
      n--;
    }
  }
  reverse((ret).begin(), (ret).end());
  for (__typeof((ret).begin()) i = ((ret).begin()); i != (ret).end(); ++i)
    printf("%s %d %c\n", i->first.c_str(), i->second.first, i->second.second);
  return 0;
}
