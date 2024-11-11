#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 100505;
long long ans[maxn][3];
long long ansr[maxn][3];
int ansp[maxn][3][5];
struct node1 {
  int c, s, z;
} a[maxn], b[maxn];
bool cmp1(node1 a, node1 b) {
  if (a.s != b.s)
    return a.s < b.s;
  else
    return a.c < b.c;
}
void work() {
  int k, j = 1;
  for (int i = 1; i <= n; i++) {
    if (ans[i][0] < ans[i - 1][0]) {
      ans[i][0] = ans[i - 1][0];
      ansp[i][0][2] = i - 1;
      ansp[i][0][3] = 0;
      ansp[i][0][4] = ansp[i - 1][0][4];
    }
    if (ans[i][0] < ans[i - 1][1]) {
      ans[i][0] = ans[i - 1][1];
      ansp[i][0][2] = i - 1;
      ansp[i][0][3] = 1;
      ansp[i][0][4] = ansp[i - 1][1][4];
    }
    if (ans[i][0] < ans[i - 1][2]) {
      ans[i][0] = ans[i - 1][2];
      ansp[i][0][2] = i - 1;
      ansp[i][0][3] = 2;
      ansp[i][0][4] = ansp[i - 1][2][4];
    }
    while (a[i].s - 1 > b[j].s) j++;
    for (k = j; k <= m && a[i].s - 1 == b[k].s; k++)
      if (a[i].c <= b[k].c) {
        if (ans[i][1] < ans[i - 1][0] + a[i].c) {
          ans[i][1] = ans[i - 1][0] + a[i].c;
          ansr[i][1] = k;
          ansp[i][1][0] = b[k].z;
          ansp[i][1][1] = a[i].z;
          ansp[i][1][2] = i - 1;
          ansp[i][1][3] = 0;
          ansp[i][1][4] = ansp[i - 1][0][4] + 1;
        }
        if (ans[i][1] < ans[i - 1][1] + a[i].c) {
          ans[i][1] = ans[i - 1][1] + a[i].c;
          ansr[i][1] = k;
          ansp[i][1][0] = b[k].z;
          ansp[i][1][1] = a[i].z;
          ansp[i][1][2] = i - 1;
          ansp[i][1][3] = 1;
          ansp[i][1][4] = ansp[i - 1][1][4] + 1;
        }
        if (k > ansr[i - 1][2] && ans[i][1] < ans[i - 1][2] + a[i].c) {
          ans[i][1] = ans[i - 1][2] + a[i].c;
          ansr[i][1] = k;
          ansp[i][1][0] = b[k].z;
          ansp[i][1][1] = a[i].z;
          ansp[i][1][2] = i - 1;
          ansp[i][1][3] = 2;
          ansp[i][1][4] = ansp[i - 1][2][4] + 1;
        }
      }
    j = k;
    for (k = j; k <= m && a[i].s == b[k].s; k++)
      if (a[i].c <= b[k].c) {
        if (ans[i][2] < ans[i - 1][0] + a[i].c) {
          ans[i][2] = ans[i - 1][0] + a[i].c;
          ansr[i][2] = k;
          ansp[i][2][0] = b[k].z;
          ansp[i][2][1] = a[i].z;
          ansp[i][2][2] = i - 1;
          ansp[i][2][3] = 0;
          ansp[i][2][4] = ansp[i - 1][0][4] + 1;
        }
        if (ans[i][2] < ans[i - 1][1] + a[i].c) {
          ans[i][2] = ans[i - 1][1] + a[i].c;
          ansr[i][1] = k;
          ansp[i][2][0] = b[k].z;
          ansp[i][2][1] = a[i].z;
          ansp[i][2][2] = i - 1;
          ansp[i][2][3] = 1;
          ansp[i][2][4] = ansp[i - 1][1][4] + 1;
        }
        if (ans[i][2] < ans[i - 1][2] + a[i].c) {
          ans[i][2] = ans[i - 1][2] + a[i].c;
          ansr[i][1] = k;
          ansp[i][2][0] = b[k].z;
          ansp[i][2][1] = a[i].z;
          ansp[i][2][2] = i - 1;
          ansp[i][2][3] = 2;
          ansp[i][2][4] = ansp[i - 1][2][4] + 1;
        }
      }
  }
}
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].c, &a[i].s);
    a[i].z = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i].c, &b[i].s);
    b[i].z = i;
  }
  sort(a + 1, a + n + 1, cmp1);
  sort(b + 1, b + 1 + m, cmp1);
}
int main() {
  init();
  work();
  long long mm = 0;
  int m1 = 0, m2 = 0;
  for (int i = 0; i < 3; i++)
    if (ans[n][i] > mm) {
      mm = ans[n][i];
      m1 = n;
      m2 = i;
    }
  printf("%I64d\n", mm);
  if (mm != 0) {
    int l = ansp[m1][m2][4];
    printf("%d\n", l);
    while (l) {
      if (m2 != 0) {
        l--;
        printf("%d %d\n", ansp[m1][m2][0], ansp[m1][m2][1]);
      }
      int i, j;
      i = ansp[m1][m2][2];
      j = ansp[m1][m2][3];
      m1 = i;
      m2 = j;
    }
  } else
    printf("%d\n", 0);
  return 0;
}
