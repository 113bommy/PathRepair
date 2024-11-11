#include <bits/stdc++.h>
using namespace std;
vector<int> v[3000];
int bd[1000][1000];
int w[1000][1000];
int a[3000];
int aa[3000];
int cnt;
int n, m;
bool dfs(int vv, int k) {
  if (vv == 1 && k == m + 1) return true;
  int e;
  for (int i = 0; i < (int)v[vv].size(); i++) {
    e = v[vv][i];
    if (bd[vv][e] != cnt) {
      bd[vv][e] = cnt;
      bd[e][vv] = cnt;
      aa[k] = e;
      if (dfs(e, k + 1)) {
        return true;
      }
      bd[vv][e] = cnt - 1;
      bd[e][vv] = cnt - 1;
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &a[0]);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i + 1]);
    w[a[i]][a[i + 1]] = i + 1;
    w[a[i + 1]][a[i]] = i + 1;
    v[a[i]].push_back(a[i + 1]);
    v[a[i + 1]].push_back(a[i]);
  }
  for (int i = 0; i <= n; i++) {
    sort(v[i].begin(), v[i].end());
  }
  cnt = 0;
  for (int i = m - 1; i >= 1; i--) {
    for (int nx = a[i] + 1; nx <= n; nx++)
      if (w[a[i - 1]][nx] >= i) {
        cnt++;
        aa[0] = a[0];
        for (int j = 1; j <= i - 1; j++) {
          aa[j] = a[j];
          bd[a[j - 1]][a[j]] = cnt;
          bd[a[j]][a[j - 1]] = cnt;
        }
        aa[i] = nx;
        bd[a[i - 1]][nx] = cnt;
        bd[nx][a[i - 1]] = cnt;
        if (dfs(nx, i + 1)) {
          for (int i = 0; i <= m; i++) {
            cout << aa[i] << " ";
          }
          cout << endl;
          return 0;
        }
      }
  }
  cout << "No solution" << endl;
  return 0;
}
