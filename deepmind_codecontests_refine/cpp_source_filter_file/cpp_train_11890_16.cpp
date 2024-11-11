#include <bits/stdc++.h>
using namespace std;
int n, oth, rr, nnmin;
int s[7][7], up[4], dn[4], ans[7], nmin, ss[110], tt[110], tot[2];
char ch[20], lst;
bool chk[210];
bool flag;
int work(int L, int R) {
  if (L == R) return L;
  int mid = (L + R) >> 1, l, r;
  l = work(L, mid);
  r = work(mid + 1, R);
  printf("? %d %d\n", l, r);
  fflush(stdout);
  scanf("%s", ch);
  if (ch[0] == '>') return r;
  return l;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (n == 3) {
      for (int i = 1; i <= 3; i++) {
        printf("? %d %d\n", i, i + 3);
        fflush(stdout);
        scanf("%s", ch);
        if (ch[0] == '>') {
          up[i] = i;
          dn[i] = i + 3;
        } else {
          up[i] = i + 3;
          dn[i] = i;
        }
      }
      printf("? %d %d\n", dn[1], dn[2]);
      fflush(stdout);
      scanf("%s", ch);
      lst = ch[0];
      if (ch[0] == '>')
        nmin = 2;
      else
        nmin = 1;
      printf("? %d %d\n", dn[nmin], dn[3]);
      fflush(stdout);
      scanf("%s", ch);
      if (ch[0] == '>') nmin = 3;
      ans[6] = nmin;
      if (nmin == 3) {
        if (lst == '>')
          ans[4] = 1, ans[5] = 2;
        else
          ans[4] = 2, ans[5] = 1;
      } else {
        oth = 3 - nmin;
        printf("? %d %d\n", dn[oth], dn[3]);
        fflush(stdout);
        scanf("%s", ch);
        if (ch[0] == '>')
          ans[4] = oth, ans[5] = 3;
        else
          ans[4] = 3, ans[5] = oth;
      }
      printf("? %d %d\n", dn[ans[5]], up[ans[6]]);
      fflush(stdout);
      scanf("%s", ch);
      if (ch[0] == '>') {
        puts("!");
        fflush(stdout);
        continue;
      }
      printf("? %d %d\n", up[ans[5]], up[ans[6]]);
      fflush(stdout);
      scanf("%s", ch);
      if (ch[0] == '<') {
        rr = ans[5];
        ans[5] = ans[6];
        ans[6] = rr;
      }
      printf("? %d %d\n", dn[ans[4]], up[ans[6]]);
      fflush(stdout);
      scanf("%s", ch);
      puts("!");
      fflush(stdout);
      continue;
    }
    nmin = work(1, n);
    flag = 0;
    for (int i = n + 1; i <= n * 2; i++) {
      printf("? %d %d\n", nmin, i);
      fflush(stdout);
      scanf("%s", ch);
      if (ch[0] == '<') {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      puts("!");
      fflush(stdout);
      continue;
    }
    ss[1] = nmin;
    for (int i = 1; i <= n * 2; i++) chk[i] = 0;
    chk[ss[1]] = 1;
    for (int i = 2; i <= n; i++) {
      nmin = 1;
      while (chk[nmin]) nmin++;
      for (int j = nmin + 1; j <= n; j++)
        if (!chk[j]) {
          printf("? %d %d\n", nmin, j);
          fflush(stdout);
          scanf("%s", ch);
          if (ch[0] == '>') nmin = j;
        }
      ss[i] = nmin;
      chk[nmin] = 1;
    }
    nnmin = work(n + 1, n * 2);
    printf("? %d %d\n", ss[n], nmin);
    fflush(stdout);
    scanf("%s", ch);
    if (ch[0] == '<') {
      puts("!");
      fflush(stdout);
      continue;
    }
    for (int i = n + 1; i <= n * 2; i++) {
      nmin = n + 1;
      while (chk[nmin]) nmin++;
      for (int j = nmin + 1; j <= n * 2; j++)
        if (!chk[j]) {
          printf("? %d %d\n", nmin, j);
          fflush(stdout);
          scanf("%s", ch);
          if (ch[0] == '>') nmin = j;
        }
      tt[i - n] = nmin;
      chk[nmin] = 1;
    }
    tot[0] = tot[1] = 1;
    for (int i = 1; i <= n; i++) {
      printf("? %d %d\n", ss[tot[0]], tt[tot[1]]);
      fflush(stdout);
      scanf("%s", ch);
      if (ch[0] == '>')
        tot[1]++;
      else
        tot[0]++;
    }
    puts("!");
    fflush(stdout);
  }
  return 0;
}
