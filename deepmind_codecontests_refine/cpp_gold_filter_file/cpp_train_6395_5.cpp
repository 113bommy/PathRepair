#include <bits/stdc++.h>
using namespace std;
int n, p;
bool ver[30][30];
void sol() {
  int i, j;
  cin >> n >> p;
  for (i = 0; i < 30; ++i)
    for (j = 0; j < 30; ++j) ver[i][j] = 0;
  for (i = 1; i <= n; ++i) {
    int nex1 = i + 1, nex2 = i + 2;
    if (nex1 > n) nex1 = 1;
    if (nex2 > n) nex2 -= n;
    ver[i][nex1] = ver[nex1][i] = 1;
    ver[i][nex2] = ver[nex2][i] = 1;
  }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if (i != j && !ver[i][j] && p) {
        ver[i][j] = ver[j][i] = 1;
        p--;
      }
  for (i = 0; i < 30; ++i)
    for (j = 0; j < 30; ++j)
      if (i < j && ver[i][j]) cout << i << " " << j << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
