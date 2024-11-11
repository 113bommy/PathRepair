#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, a[MAXN];
int ansn = 0, ans[MAXN][15];
bool u[MAXN];
int cirn = 0, cir[MAXN], size[MAXN];
int start2[MAXN], start3[MAXN];
int n2 = 0, n3 = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    if (!u[i]) {
      int j = i;
      int si = 1;
      while (a[j] != i) {
        j = a[j];
        u[j] = true;
        si++;
      }
      if (si != 1) {
        cirn++;
        cir[cirn] = i;
        size[cirn] = si;
      }
    }
  for (int i = 1; i <= cirn; i++)
    while (size[i] >= 4) {
      if (size[i] == 4) {
        int x = cir[i], y = a[x], z = a[y], w = a[z];
        ansn++;
        ans[ansn][0] = 4;
        ans[ansn][1] = x;
        ans[ansn][2] = y;
        ans[ansn][3] = z;
        ans[ansn][4] = w;
        ans[ansn][5] = y;
        ans[ansn][6] = z;
        ans[ansn][7] = w;
        ans[ansn][8] = x;
        a[x] = x;
        a[y] = y;
        a[z] = z;
        a[w] = w;
        size[i] = 1;
      } else {
        int x = cir[i], y = a[x], z = a[y], w = a[z], v = a[w];
        ansn++;
        ans[ansn][0] = 5;
        ans[ansn][1] = x;
        ans[ansn][2] = y;
        ans[ansn][3] = z;
        ans[ansn][4] = w;
        ans[ansn][6] = v;
        ans[ansn][6] = y;
        ans[ansn][7] = z;
        ans[ansn][8] = w;
        ans[ansn][9] = v;
        ans[ansn][10] = x;
        a[x] = a[v];
        a[y] = y;
        a[z] = z;
        a[w] = w;
        a[v] = v;
        size[i] -= 4;
      }
    }
  for (int i = 1; i <= cirn; i++) {
    if (size[i] == 2) {
      n2++;
      start2[n2] = cir[i];
    } else if (size[i] == 3) {
      n3++;
      start3[n3] = cir[i];
    }
  }
  while (n2 != 0 || n3 != 0) {
    if (n2 != 0 && n3 != 0) {
      int x = start2[n2], y = a[x], z = start3[n3], w = a[z], v = a[w];
      ansn++;
      ans[ansn][0] = 5;
      ans[ansn][1] = x;
      ans[ansn][2] = y;
      ans[ansn][3] = z;
      ans[ansn][4] = w;
      ans[ansn][5] = v;
      ans[ansn][6] = y;
      ans[ansn][7] = x;
      ans[ansn][8] = w;
      ans[ansn][9] = v;
      ans[ansn][10] = z;
      a[x] = x;
      a[y] = y;
      a[z] = z;
      a[w] = w;
      a[v] = v;
      n2--;
      n3--;
    } else if (n3 == 0 && n2 == 1) {
      int x = start2[n2], y = a[x];
      ansn++;
      ans[ansn][0] = 2;
      ans[ansn][1] = x;
      ans[ansn][2] = y;
      ans[ansn][3] = y;
      ans[ansn][4] = x;
      a[x] = x;
      a[y] = y;
      n2--;
    } else if (n3 == 0) {
      int x = start2[n2], y = a[x], z = start2[n2 - 1], w = a[z];
      ansn++;
      ans[ansn][0] = 4;
      ans[ansn][1] = x;
      ans[ansn][2] = y;
      ans[ansn][3] = z;
      ans[ansn][4] = w;
      ans[ansn][5] = y;
      ans[ansn][6] = x;
      ans[ansn][7] = w;
      ans[ansn][8] = z;
      a[x] = x;
      a[y] = y;
      a[z] = z;
      a[w] = w;
      n2 -= 2;
    } else if (n3 == 1) {
      int x = start3[n3], y = a[x], z = a[y];
      ansn++;
      ans[ansn][0] = 3;
      ans[ansn][1] = x;
      ans[ansn][2] = y;
      ans[ansn][3] = z;
      ans[ansn][4] = y;
      ans[ansn][5] = z;
      ans[ansn][6] = x;
      a[x] = x;
      a[y] = y;
      n3--;
    } else {
      int x = start3[n3], y = a[x], z = start3[n3 - 1], w = a[z], v = a[w];
      ansn++;
      ans[ansn][0] = 5;
      ans[ansn][1] = x;
      ans[ansn][2] = y;
      ans[ansn][3] = z;
      ans[ansn][4] = w;
      ans[ansn][5] = v;
      ans[ansn][6] = y;
      ans[ansn][7] = x;
      ans[ansn][8] = w;
      ans[ansn][9] = v;
      ans[ansn][10] = z;
      a[x] = a[y];
      a[y] = y;
      a[z] = z;
      a[w] = w;
      a[v] = v;
      n2++;
      start2[n2] = x;
      n3 -= 2;
    }
  }
  printf("%d\n", ansn);
  for (int i = 1; i <= ansn; i++) {
    printf("%d\n", ans[i][0]);
    for (int j = 1; j <= ans[i][0]; j++) printf("%d ", ans[i][j]);
    printf("\n");
    for (int j = 1; j <= ans[i][0]; j++) printf("%d ", ans[i][j + ans[i][0]]);
    printf("\n");
  }
  return 0;
}
