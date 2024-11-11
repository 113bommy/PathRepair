#include <bits/stdc++.h>
using namespace std;
const int LEN = 724;
const int BIT = 3020;
const int N = 50;
const long long LL = 10000000000000000;
char str[LEN];
long long s[LEN], a[BIT][BIT], mat[BIT][N], two[63], pivot[BIT];
int ans[BIT];
int main() {
  int i, j, k, n, num, len, r, p2, q2, maxnum, pnum;
  long long p, q, tmp;
  scanf("%d", &n);
  maxnum = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s", str);
    len = strlen(str);
    p = 1;
    num = 1;
    for (j = len - 1; j >= 0; j--) {
      q = (str[j] - '0') * p;
      s[num] += q;
      p *= 10;
      if (p >= LL) {
        num++;
        p = 1;
      }
    }
    if (s[num] > 0)
      len = num;
    else
      len = num - 1;
    num = 0;
    while (len > 0) {
      s[0] = 0;
      for (j = len; j >= 1; j--) {
        if (s[j] % 2 == 1) s[j - 1] += LL / 2;
        s[j] = s[j] / 2;
      }
      num++;
      if (s[0] > 0)
        a[num][i] = 1;
      else
        a[num][i] = 0;
      if (s[len] == 0) len--;
    }
    if (num > maxnum) maxnum = num;
  }
  two[0] = 1;
  for (i = 1; i <= 60; i++) two[i] = two[i - 1] * 2;
  for (i = 1; i <= n; i++) {
    p = (i - 1) / 60;
    q = (i - 1) % 60;
    for (j = 1; j <= maxnum; j++) mat[j][p] += a[j][i] * two[q];
  }
  len = (n - 1) / 60;
  pnum = 0;
  for (i = 1; i <= n; i++) {
    p = (i - 1) / 60;
    q = (i - 1) % 60;
    r = 0;
    for (j = pnum + 1; j <= maxnum; j++)
      if ((mat[j][p] & two[q]) > 0) {
        r = j;
        break;
      }
    if (r > 0) {
      pnum++;
      pivot[pnum] = i;
      for (j = 0; j <= len; j++) {
        tmp = mat[pnum][j];
        mat[pnum][j] = mat[r][j];
        mat[r][j] = tmp;
      }
      for (j = 1; j <= maxnum; j++) {
        if (j == pnum) continue;
        if ((mat[j][p] & two[q]) > 0) {
          for (k = 0; k <= len; k++) mat[j][k] ^= mat[pnum][k];
        }
      }
      printf("0\n");
    } else {
      num = 0;
      for (j = 1; j <= pnum; j++) {
        p2 = (pivot[j] - 1) / 60;
        q2 = (pivot[j] - 1) % 60;
        if ((mat[j][p2] & two[q2]) > 0 && (mat[j][p] & two[q]) > 0) {
          num++;
          ans[num] = pivot[j] - 1;
          mat[j][p] -= two[q];
        }
      }
      printf("%d", num);
      for (j = 1; j <= num; j++) printf(" %d", ans[j]);
      printf("\n");
    }
  }
  return 0;
}
