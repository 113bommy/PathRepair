#include <bits/stdc++.h>
using namespace std;
int leap_year(int second) {
  if (second % 400 == 0) return 1;
  if (second % 100 == 0) return 0;
  if (second % 4 == 0) return 1;
  return 0;
}
int first[12000100], ti[99999];
int a[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int s, m, h, day, date, month;
  scanf("%d%d%d%d%d%d", &s, &m, &h, &date, &day, &month);
  int n = 0, j = -1, dd = 3;
  for (int i = 1970; i < 32709; i++) {
    for (int mm = 0; mm < 12; mm++) {
      int d = a[mm];
      if (mm == 1 && leap_year(i)) d++;
      for (int k = 1; k <= d; k++) {
        j++;
        dd++;
        if (dd > 7) dd = 1;
        if (month == -1) {
          if (date == -1) {
            if (day == -1) {
              first[n++] = j;
            } else {
              if (day == k) first[n++] = j;
            }
          } else {
            if (day == -1) {
              if (date == dd) first[n++] = j;
            } else {
              if (date == dd || day == k) first[n++] = j;
            }
          }
        } else if (month == mm + 1) {
          if (date == -1) {
            if (day == -1) {
              first[n++] = j;
            } else {
              if (day == k) first[n++] = j;
            }
          } else {
            if (day == -1) {
              if (date == dd) first[n++] = j;
            } else {
              if (date == dd || day == k) first[n++] = j;
            }
          }
        }
      }
    }
  }
  int mm = 0, r = 0;
  for (int i = 0; i < 24; i++)
    for (int j = 0; j < 60; j++)
      for (int k = 0; k < 60; k++) {
        if ((s == -1 || s == k) && (m == -1 || m == j) && (h == -1 || h == i))
          ti[mm++] = r;
        r++;
      }
  int N;
  long long t, e;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &t);
    t++;
    e = t / 86400;
    int u = lower_bound(first, first + n, e) - first;
    if (first[u] > e) {
      printf("%I64d\n", first[u] * 86400LL + ti[0]);
      continue;
    }
    int v = lower_bound(ti, ti + mm, t % 86400) - ti;
    if (v == mm) {
      printf("%I64d\n", first[u + 1] * 86400LL + ti[0]);
    } else {
      printf("%I64d\n", first[u] * 86400LL + ti[v]);
    }
  }
  return 0;
}
