#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;
inline int comp(const double &a, const double &b) {
  if (fabs(a - b) < eps) return 0;
  return a > b ? 1 : -1;
}
int di[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dj[] = {0, 0, 1, -1, 1, -1, -1, 1};
int diK[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int djK[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int I, J;
inline bool val(const int &i, const int &j) {
  if (i < 0 || j < 0 || i >= I || j >= J) return false;
  return true;
}
int N;
int n;
int ret[109][109];
bool val() {
  for (int i = 0; i < (int)(I); i++)
    for (int j = 0; j < (int)(J); j++)
      for (int k = 0; k < (int)(4); k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (val(ni, nj) && abs(ret[i][j] - ret[ni][nj] == 1)) return 0;
      }
  return 1;
}
bool vis[10009];
bool dfs(int i, int j) {
  if (i == I) return 1;
  if (j == J) return dfs(i + 1, 0);
  for (int a = 1; a <= I * J; a++)
    if (!vis[a]) {
      if (i && abs(a - ret[i - 1][j]) == 1) continue;
      if (j && abs(a - ret[i][j - 1]) == 1) continue;
      vis[a] = 1;
      ret[i][j] = a;
      if (dfs(i, j + 1)) return 1;
      vis[a] = 0;
    }
  return 0;
}
int main() {
  cin >> I >> J;
  if (I * J <= 1000000) {
    if (dfs(0, 0)) {
      for (int i = 0; i < (int)(I); i++) {
        for (int j = 0; j < (int)(J); j++) {
          if (j) printf(" ");
          printf("%d", ret[i][j]);
        }
        printf("\n");
      }
    } else
      cout << -1 << endl;
    return 0;
  }
  vector<pair<int, int> > v;
  for (int i = 0; i < (int)(I); i++)
    for (int j = 0; j < (int)(J); j++) v.push_back(make_pair(i, j));
  int cc = 1;
  for (int i = 1; i < I * J; i += 2) ret[v[i].first][v[i].second] = cc++;
  for (int i = 0; i < I * J; i += 2) ret[v[i].first][v[i].second] = cc++;
  if (!val()) {
    cc = 1;
    for (int i = 0; i < I * J; i += 2) ret[v[i].first][v[i].second] = cc++;
    for (int i = 1; i < I * J; i += 2) ret[v[i].first][v[i].second] = cc++;
    if (!val()) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < (int)(I); i++) {
    for (int j = 0; j < (int)(J); j++) {
      if (j) printf(" ");
      printf("%d", ret[i][j]);
    }
    printf("\n");
  }
  return 0;
}
