#include <bits/stdc++.h>
using namespace std;
int d[2][100000];
int cnt[100000];
vector<int> a[100000];
int p[100000][2];
int ans[100000][2];
int main() {
  int i, j, k, tot, max, idmax, n, x, tmp, tmp1, last, tmp2, tmp3, prev, pv;
  vector<int> aa;
  vector<pair<int, int> > a1;
  scanf("%d%d", &n, &tot);
  memset(cnt, 0, sizeof(cnt));
  for (i = 0; i <= 70000; i++) a[i].clear();
  max = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    cnt[x]++;
    a[x].push_back(i);
    if (x > max) max = x;
  }
  cnt[max]--;
  idmax = a[max][a[max].size() - 1];
  a[max].pop_back();
  memset(d, 0, sizeof(d));
  d[0][max] = 1;
  p[max][0] = -1;
  for (i = 1; i <= 70000; i++) {
    if (d[0][tot] == 1) break;
    if (cnt[i] > 0) {
      memset(d[1], 0, sizeof(d[1]));
      for (j = 70000; j >= max + i; j--) {
        if (j + i > 70000) {
          tmp = 0;
          tmp1 = j;
          for (k = 0; k < cnt[i]; k++) {
            tmp1 -= i;
            if ((tmp1 >= 0) && (d[0][tmp1] > 0)) tmp++;
          }
          d[1][j] = tmp;
        } else {
          tmp = d[1][j + i];
          if (d[0][j] > 0) tmp--;
          tmp1 = j - cnt[i] * i;
          if ((tmp1 >= 0) && (d[0][tmp1] > 0)) tmp++;
          d[1][j] = tmp;
        }
      }
      for (j = 0; j < i; j++) {
        last = -1;
        for (k = max + j; k <= 70000; k += i) {
          if (d[0][k] == 1) last = k;
          if ((d[0][k] == 0) && (d[1][k] > 0)) {
            d[0][k] = 1;
            p[k][0] = last;
            p[k][1] = i;
          }
        }
      }
    }
  }
  if (d[0][tot] == 1) {
    tmp = tot;
    while (p[tmp][0] != -1) {
      tmp1 = (tmp - p[tmp][0]) / p[tmp][1];
      for (i = 0; i < tmp1; i++) {
        tmp2 = a[p[tmp][1]][a[p[tmp][1]].size() - 1];
        a[p[tmp][1]].pop_back();
        ans[tmp2][0] = -1;
        ans[tmp2][1] = p[tmp][1];
      }
      tmp = p[tmp][0];
    }
    prev = idmax;
    pv = max;
    for (i = 70000; i >= 0; i--) {
      for (j = 0; j < a[i].size(); j++) {
        ans[prev][0] = a[i][j];
        ans[prev][1] = pv - i;
        pv = i;
        prev = a[i][j];
      }
    }
    ans[prev][0] = -1;
    ans[prev][1] = pv;
    for (i = 0; i < n; i++) {
      printf("%d ", ans[i][1]);
      if (ans[i][0] == -1)
        printf("0\n");
      else
        printf("1 %d\n", ans[i][0] + 1);
    }
  } else {
    printf("-1\n");
  }
}
