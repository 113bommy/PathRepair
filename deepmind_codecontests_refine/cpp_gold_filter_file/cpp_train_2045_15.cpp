#include <bits/stdc++.h>
struct zxf {
  long x, y;
} ans[1000005] = {0, 0};
long hash[1000005] = {0}, a[1000005] = {0}, last[1000005] = {0},
     count[1000005] = {0}, now[1000005] = {0}, tot[1000005] = {0},
     pr[1000005] = {0}, yy[5][1000005] = {0};
int main() {
  long i, j, tota = 0, n, k, sumans, len, sum, o, l;
  scanf("%ld\n", &n);
  for (i = 1; i <= n; i++) scanf("%ld ", &a[i]);
  for (i = 1; i <= n; i++)
    if (!hash[i] && a[i] != i) {
      ++tota;
      now[tota] = i;
      for (j = i;; j = a[j])
        if (!hash[j]) {
          hash[j] = 1;
          count[tota]++;
          last[tota] = j;
        } else
          break;
    }
  sumans = 0;
  len = 0;
  for (i = 1; i <= tota;) {
    sum = 0;
    if (count[i] < 5) {
      yy[count[i]][++yy[count[i]][0]] = i;
      i++;
      continue;
    }
    sumans++;
    pr[sumans] = len;
    while (1) {
      if (i == tota + 1) goto de;
      if (count[i] < 5) {
        yy[count[i]][++yy[count[i]][0]] = i;
        i++;
        break;
      }
      if (sum == 4 || sum == 5) break;
      o = ((5 - sum) < (count[i]) ? (5 - sum) : (count[i]));
      tot[sumans] += o;
      for (k = last[i], j = 1; j < o; j++) {
        ++len;
        ans[len].x = k;
        ans[len].y = a[k];
        k = a[k];
      }
      ++len;
      ans[len].x = k;
      ans[len].y = last[i];
      a[last[i]] = a[k];
      count[i] -= o;
      sum += o;
      if (count[i] == 0)
        i++;
      else
        count[i]++;
    }
  }
de:;
  for (i = 1; i <= yy[4][0]; i++) {
    sumans++;
    pr[sumans] = len;
    l = yy[4][i];
    tot[sumans] = 4;
    for (k = last[l], j = 1; j < 4; j++) {
      ++len;
      ans[len].x = k;
      ans[len].y = a[k];
      k = a[k];
    }
    ++len;
    ans[len].x = k;
    ans[len].y = last[l];
  }
  for (i = 1; i <= ((yy[3][0]) < (yy[2][0]) ? (yy[3][0]) : (yy[2][0])); i++) {
    sumans++;
    pr[sumans] = len;
    l = yy[3][i];
    tot[sumans] = 5;
    for (k = last[l], j = 1; j < 3; j++) {
      ++len;
      ans[len].x = k;
      ans[len].y = a[k];
      k = a[k];
    }
    ++len;
    ans[len].x = k;
    ans[len].y = last[l];
    ++len;
    ans[len].x = last[yy[2][i]];
    ans[len].y = a[last[yy[2][i]]];
    ++len;
    ans[len].x = ans[len - 1].y;
    ans[len].y = ans[len - 1].x;
  }
  long i1 = i;
  for (j = i1; j <= yy[3][0];) {
    sumans++;
    pr[sumans] = len;
    sum = 5;
    while (1) {
      if (j == yy[3][0] + 1) goto de1;
      if (sum == 0) break;
      l = yy[3][j];
      o = ((count[l]) < (sum) ? (count[l]) : (sum));
      tot[sumans] += o;
      for (k = last[l], i = 1; i < o; i++) {
        ++len;
        ans[len].x = k;
        ans[len].y = a[k];
        k = a[k];
      }
      ++len;
      ans[len].x = k;
      ans[len].y = last[l];
      a[last[l]] = a[k];
      count[l] -= o;
      sum -= o;
      if (count[l] == 0)
        j++;
      else
        count[l]++;
    }
  }
  for (j = i1; j <= yy[2][0]; j++) {
    sumans++;
    pr[sumans] = len;
    tot[sumans] = 2;
    ++len;
    ans[len].x = last[yy[2][j]];
    ans[len].y = a[last[yy[2][j]]];
    ++len;
    ans[len].x = ans[len - 1].y;
    ans[len].y = ans[len - 1].x;
    if (j < yy[2][0]) {
      j++;
      tot[sumans] += 2;
      ++len;
      ans[len].x = last[yy[2][j]];
      ans[len].y = a[last[yy[2][j]]];
      ++len;
      ans[len].x = ans[len - 1].y;
      ans[len].y = ans[len - 1].x;
    }
  }
de1:;
  printf("%ld\n", sumans);
  for (i = 1; i <= sumans; i++) {
    printf("%ld\n", tot[i]);
    for (j = 1; j <= tot[i]; j++) printf("%ld ", ans[pr[i] + j].x);
    printf("\n");
    for (j = 1; j <= tot[i]; j++) printf("%ld ", ans[pr[i] + j].y);
    printf("\n");
  }
  return 0;
}
