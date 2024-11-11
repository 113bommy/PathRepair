#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)2e18;
const string name = "c";
const int NMAX = 4011;
int ti, td, ts, tc, n1, n2;
char s1[NMAX], s2[NMAX];
int ans[NMAX][NMAX];
int last1[150], exist1[NMAX][150];
int last2[150], exist2[NMAX][150];
inline void update(int x, int y, int xx, int yy, int s) {
  ans[xx][yy] = min(ans[xx][yy], ans[x][y] + s);
}
int main() {
  cin >> ti >> td >> tc >> ts;
  cin >> s1 >> s2;
  n1 = strlen(s1);
  n2 = strlen(s2);
  s2[n2] = '@';
  s2[n2 + 1] = '\0';
  memset(exist1, 255, sizeof(exist1));
  memset(last1, 255, sizeof(last1));
  for (int i = n1 - 1; i >= 0; --i) {
    for (char ch = 'a'; ch <= 'z'; ch++) exist1[i][ch] = last1[ch];
    last1[s1[i]] = i;
  }
  memset(exist2, 255, sizeof(exist2));
  memset(last2, 255, sizeof(last2));
  for (int i = n2 - 1; i >= 0; --i) {
    for (char ch = 'a'; ch <= 'z'; ch++) exist2[i][ch] = last2[ch];
    last2[s2[i]] = i;
  }
  for (int i = 0; i < (int)n1 + 1; i++)
    for (int j = 0; j < (int)n2 + 1; j++) ans[i][j] = inf;
  ans[0][0] = 0;
  int x, y;
  for (int i = 0; i < (int)n1 + 1; i++)
    for (int j = 0; j < (int)n2 + 1; j++)
      if (ans[i][j] < inf) {
        if (i < n1) update(i, j, i + 1, j, td);
        if (j < n2) update(i, j, i, j + 1, ti);
        if (i < n1 && j < n2) {
          if (s1[i] == s2[j])
            update(i, j, i + 1, j + 1, 0);
          else
            update(i, j, i + 1, j + 1, tc);
        }
        if (i < n1 && j < n2) {
          x = exist1[i][s2[j]];
          y = exist2[j][s2[i]];
          if (x > -1 && y > -1)
            update(i, j, x + 1, y + 1,
                   ts + (y - j - 1) * ti + (x - i - 1) * td);
        }
      }
  cout << ans[n1][n2] << endl;
  return 0;
}
