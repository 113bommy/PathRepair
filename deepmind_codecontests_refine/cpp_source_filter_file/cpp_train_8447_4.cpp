#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[201][201];
int aa[201][201];
int ansr[201], ansc[201];
void swichr(int x) {
  int i;
  for (i = 1; i <= m; i++) aa[x][i] = 1 - aa[x][i];
}
void swichc(int x) {
  int i;
  for (i = 1; i <= n; i++) aa[i][x] = 1 - aa[i][x];
}
int badr(int x) {
  int swich = 0;
  int i;
  for (i = 2; i <= m; i++)
    if (aa[x][i] != aa[x][i - 1]) swich++;
  return swich;
}
int ck(int x) {
  int i, j, k;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) aa[i][j] = a[i][j];
  for (i = 1; i <= n; i++) ansr[i] = 0;
  for (i = 1; i <= m; i++) ansc[i] = 0;
  for (i = 1; i <= x; i++)
    if (aa[1][i] != 0) {
      ansc[i] = 1;
      swichc(i);
    }
  for (i = x + 1; i <= m; i++)
    if (aa[1][i] != 1) {
      ansc[i] = 1;
      swichc(i);
    }
  bool app = false;
  for (i = 1; i <= n; i++) {
    int f = badr(i);
    if (f >= 2) return 0;
    if (!app && a[i][1] == 1) {
      ansr[i] = 1;
      swichr(i);
    }
    if (app && a[i][1] == 0) {
      ansr[i] = 1;
      swichr(i);
    }
    if (app && f) return 0;
    if (f) app = true;
  }
  return 1;
}
int main() {
  int i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> a[i][j];
  for (j = 0; j <= n; j++) {
    if (ck(j)) {
      cout << "YES" << endl;
      for (i = 1; i <= n; i++) cout << ansr[i];
      cout << endl;
      for (i = 1; i <= m; i++) cout << ansc[i];
      cout << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
