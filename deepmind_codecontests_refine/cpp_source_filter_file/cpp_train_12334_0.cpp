#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2005][2005];
int byl[2005][2005];
int deg[2005][2005];
int mate[2005][2005];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char sg[] = {'^', '>', '<', 'v'};
bool check(int a, int b) {
  return (a >= 0 && a < n && b >= 0 & b < m && s[a][b] == '.');
}
int main() {
  scanf("%d%d", &(n), &(m));
  ;
  for (int i = (0); i < (n); ++i) scanf("%s", s[i]);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) mate[i][j] = -1;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) deg[i][j] = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      for (int k = (0); k < (4); ++k)
        if (s[i][j] != '.')
          continue;
        else if (check(i + dx[k], j + dy[k]))
          deg[i][j]++;
  vector<pair<int, int> > kju;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) {
      if (s[i][j] == '.' && deg[i][j] == 0) {
        printf("Not unique\n");
        return 0;
      }
      if (s[i][j] == '.' && deg[i][j] == 1) {
        kju.push_back(make_pair(i, j));
      }
    }
  int i = 0;
  while (1) {
    if (i >= kju.size()) break;
    int ax = kju[i].first, ay = kju[i].second;
    i++;
    if (mate[ax][ay] != -1) continue;
    int bx = -1, by = -1;
    bool ok = false;
    for (int j = (0); j < (4); ++j) {
      bx = ax + dx[j], by = ay + dy[j];
      if (check(bx, by) && mate[bx][by] == -1) {
        mate[ax][ay] = j;
        mate[bx][by] = 3 - j;
        ok = true;
        break;
      }
    }
    if (!ok) {
      printf("Not unique\n");
      return 0;
    }
    for (int j = (0); j < (4); ++j) {
      int cx = bx + dx[j], cy = by + dy[j];
      if (check(cx, cy) && mate[cx][cy] == -1) {
        deg[cx][cy]--;
        if (deg[cx][cy] == 1) kju.push_back(make_pair(cx, cy));
      }
    }
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) {
      if (s[i][j] == '.' && mate[i][j] == -1) {
        printf("Not unique\n");
        return 0;
      }
    }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) {
      if (s[i][j] != '.')
        printf("%c", s[i][j]);
      else
        printf("%c", sg[mate[i][j]]);
    }
    printf("\n");
  }
}
