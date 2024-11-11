#include <bits/stdc++.h>
using namespace std;
char ar[505][505];
vector<pair<int, int> > v[505][505];
int vi[505][505], n, m, cn = 0;
void dfs(int i, int j, int le) {
  vi[i][j] = 1;
  cn++;
  int k, l = v[i][j].size();
  for (k = 0; k < l; k++) {
    int f = v[i][j][k].first, s = v[i][j][k].second;
    if (!vi[f][s]) dfs(f, s, 1);
  }
  if (le) {
    cn += 2;
  }
}
void dfsp(int i, int j, int le) {
  vi[i][j] = 1;
  printf("B %d %d\n", i + 1, j + 1);
  int k, l = v[i][j].size();
  for (k = 0; k < l; k++) {
    int f = v[i][j][k].first, s = v[i][j][k].second;
    if (!vi[f][s]) dfsp(f, s, 1);
  }
  if (le) {
    printf("B %d %d\n", i + 1, j + 1);
    printf("R %d %d\n", i + 1, j + 1);
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%*c");
    for (j = 0; j < m; j++) {
      scanf("%c", &ar[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ar[i][j] == '.') {
        if (i > 0 && ar[i - 1][j] == '.')
          v[i][j].push_back(make_pair(i - 1, j));
        if (j > 0 && ar[i][j - 1] == '.')
          v[i][j].push_back(make_pair(i, j - 1));
        if (i + 1 < n && ar[i + 1][j] == '.')
          v[i][j].push_back(make_pair(i + 1, j));
        if (j + 1 < m && ar[i][j + 1] == '.')
          v[i][j].push_back(make_pair(i, j + 1));
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ar[i][j] == '.' && !vi[i][j]) dfs(i, j, 0);
    }
  }
  printf("%d", cn);
  printf("\n");
  memset(vi, 0, sizeof(vi));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (ar[i][j] == '.' && !vi[i][j]) dfsp(i, j, 0);
    }
  }
  return 0;
}
