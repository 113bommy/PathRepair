#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
int mask1[50][50], mask2[50][50], f3[50][50];
bool f1[50][50][26], f2[50][50][26];
vector<pair<int, int> > trans[26];
char s1[51], s2[51];
int main() {
  int n;
  scanf("%s%s%d", s1, s2, &n);
  for (int i = 0; i < n; i++) {
    char tmp[6];
    scanf("%s", tmp);
    int x = tmp[0] - 'a';
    int y = tmp[3] - 'a';
    int z = tmp[4] - 'a';
    trans[x].push_back(make_pair(y, z));
  }
  int l1 = strlen(s1);
  memset(f1, false, sizeof(f1));
  for (int i = l1 - 1; i >= 0; i--) {
    f1[i][i][s1[i] - 'a'] = true;
    for (int j = i + 1; j < l1; j++)
      for (int k = 0; k < 26; k++)
        for (int t = i; t < j; t++) {
          if (f1[i][j][k]) break;
          for (int p = 0; p < trans[k].size(); p++) {
            int x = trans[k][p].first;
            int y = trans[k][p].second;
            if (f1[i][t][x] && f1[t + 1][j][y]) f1[i][j][k] = true;
          }
        }
  }
  int l2 = strlen(s2);
  memset(f2, false, sizeof(f2));
  for (int i = l2 - 1; i >= 0; i--) {
    f2[i][i][s2[i] - 'a'] = true;
    for (int j = i + 1; j < l2; j++)
      for (int k = 0; k < 26; k++)
        for (int t = i; t < j; t++) {
          if (f2[i][j][k]) break;
          for (int p = 0; p < trans[k].size(); p++) {
            int x = trans[k][p].first;
            int y = trans[k][p].second;
            if (f2[i][t][x] && f2[t + 1][j][y]) f2[i][j][k] = true;
          }
        }
  }
  memset(mask1, 0, sizeof(mask1));
  for (int i = 0; i < l1; i++)
    for (int j = i; j < l1; j++)
      for (int k = 0; k < 26; k++)
        if (f1[i][j][k]) mask1[i][j] += 1 << k;
  memset(mask2, 0, sizeof(mask2));
  for (int i = 0; i < l2; i++)
    for (int j = i; j < l2; j++)
      for (int k = 0; k < 26; k++)
        if (f2[i][j][k]) mask2[i][j] += 1 << k;
  for (int i = 0; i < l1; i++)
    for (int j = 0; j < l2; j++)
      if ((mask1[0][i] & mask2[0][j]) != 0) {
        f3[i][j] = 1;
      } else {
        f3[i][j] = inf;
        for (int x = 0; x < i; x++)
          for (int y = 0; y < j; y++)
            if ((mask1[x + 1][i] & mask2[y + 1][j]) != 0)
              f3[i][j] = min(f3[i][j], f3[x][y] + 1);
      }
  int ans = f3[l1 - 1][l2 - 1];
  if (ans == inf) ans = -1;
  printf("%d\n", ans);
  return 0;
}
