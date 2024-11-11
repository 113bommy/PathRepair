#include <bits/stdc++.h>
struct node {
  int t, x, ans, id, index;
} s[100010];
int n, m, q, i, j, num, cnt, nowt;
int cmp(const void *a, const void *b) {
  node *aa = (node *)a;
  node *bb = (node *)b;
  if (aa->id != bb->id) return aa->id - bb->id;
  return bb->t - aa->t;
}
int cmppos(const void *a, const void *b) {
  node *aa = (node *)a;
  node *bb = (node *)b;
  if (aa->t != bb->t) return aa->t - bb->t;
  return aa->x - bb->x;
}
int cmpans(const void *a, const void *b) {
  node *aa = (node *)a;
  node *bb = (node *)b;
  return aa->index - bb->index;
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d %d", &s[i].t, &s[i].x);
      s[i].index = i;
    }
    num = 0;
    cnt = 1;
    while (num + m <= n) {
      for (int i = num; i < m + num; i++) s[i].id = cnt;
      cnt++;
      num += m;
    }
    for (i = num; i < n; i++) s[i].id = cnt++;
    qsort(s, n, sizeof s[0], cmp);
    cnt = 1;
    nowt = s[0].t;
    for (i = 0; i < n; i++) {
      if (s[i].id == cnt)
        s[i].t = nowt;
      else {
        nowt = s[i].t;
        cnt++;
      }
    }
    qsort(s, n, sizeof s[0], cmppos);
    nowt = 0, i = 0;
    int prex = 0, nowx;
    cnt = 1;
    while (i < n) {
      prex = 0;
      while (i < n && s[i].id == cnt) {
        if (nowt < s[i].t) nowt = s[i].t;
        int cntnum = 0;
        nowx = s[i].x;
        while (i < n && s[i].id == cnt && s[i].x == nowx) {
          s[i].ans = nowt + nowx - prex;
          i++;
          cntnum++;
        }
        nowt += nowx - prex;
        nowt += ((1 + cntnum / 2));
        if (s[i].id == cnt) prex = nowx;
      }
      nowt += nowx;
      cnt++;
    }
    qsort(s, n, sizeof s[0], cmpans);
    for (i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", s[i].ans);
    }
    printf("\n");
  }
  return 0;
}
