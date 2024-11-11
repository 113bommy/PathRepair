#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int sum[6][maxn];
char s[maxn], tmp[6][maxn];
int get_min(int l, int r) {
  int res = 1e9;
  for (int i = 0; i < 6; i++) res = min(res, sum[i][r] - sum[i][l]);
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  tmp[0][1] = 'a';
  tmp[0][2] = 'b';
  tmp[0][3] = 'c';
  tmp[1][1] = 'a';
  tmp[1][2] = 'c';
  tmp[1][3] = 'b';
  tmp[2][1] = 'b';
  tmp[2][2] = 'a';
  tmp[2][3] = 'c';
  tmp[3][1] = 'b';
  tmp[3][2] = 'c';
  tmp[3][3] = 'a';
  tmp[4][1] = 'c';
  tmp[4][2] = 'a';
  tmp[4][3] = 'b';
  tmp[5][1] = 'c';
  tmp[5][2] = 'b';
  tmp[5][3] = 'a';
  for (int j = 0; j < 6; j++)
    for (int i = 3; i <= n; i++) tmp[j][i] = tmp[j][i - 3];
  for (int j = 0; j < 6; j++)
    for (int i = 1; i <= n; i++) {
      sum[j][i] = sum[j][i - 1];
      if (s[i] != tmp[j][i]) ++sum[j][i];
    }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", get_min(l, r));
  }
  return 0;
}
