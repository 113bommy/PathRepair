#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:500000000")
using namespace std;
int A[2002][2002];
bool used[2002][2002];
int _i[] = {0, 0, 1, -1};
int _j[] = {1, -1, 0, 0};
int n;
pair<int, int> c[2002 * 2002];
int size = 0;
void dfs(int i, int j) {
  used[i][j] = 1;
  c[size++] = pair<int, int>(i, j);
  for (int k = 0; k < 4; k++) {
    if (i + _i[k] < n && j + _j[k] < n && !used[i + _i[k]][j + _j[k]] &&
        A[i + _i[k]][j + _j[k]]) {
      dfs(i + _i[k], j + _j[k]);
    }
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &A[i][j]);
  int cnt = 0, ccl = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (!used[i][j] && A[i][j]) {
        size = 0;
        dfs(i, j);
        sort(c, c + size);
        double R = c[size - 1].first - c[0].first + 1;
        R /= 2;
        double s = acos(-1.0) * R * R;
        if (s > size - 220 && s < size + 220) ccl++;
        cnt++;
      }
    }
  }
  printf("%d %d\n", ccl, cnt - ccl);
}
