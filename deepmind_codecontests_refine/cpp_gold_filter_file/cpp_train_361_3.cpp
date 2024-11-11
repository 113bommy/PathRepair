#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16E5;
struct node {
  char choose[20];
  int s1, s2, s3;
  friend bool operator<(node n1, node n2) {
    if (n1.s2 != n2.s2)
      return n1.s2 < n2.s2;
    else if (n1.s3 != n2.s3)
      return n1.s3 < n2.s3;
    else
      return n1.s1 > n2.s1;
  }
  friend bool operator==(node n1, node n2) {
    if (n1.s2 == n2.s2 && n1.s3 == n2.s3)
      return true;
    else
      return false;
  }
  friend bool operator<=(node n1, node n2) {
    if (n1.s2 != n2.s2)
      return n1.s2 < n2.s2;
    else
      return n1.s3 < n2.s3;
  }
} s[MAXN], t[MAXN];
int n, cnt, sum1, sum2, sum3, flag, m;
int a[30], b[30], c[30];
char ch[20];
void make(node s[], int t, int k) {
  if (k == t) {
    int p;
    if (flag == 1)
      p = 0;
    else
      p = m;
    for (int i = p; i < t; i++) s[cnt].choose[i - p] = ch[i];
    s[cnt].choose[t - p] = 0;
    s[cnt].s1 = sum1;
    s[cnt].s2 = flag * (sum2 - sum1);
    s[cnt].s3 = flag * (sum3 - sum1);
    cnt++;
    return;
  }
  sum1 -= a[k];
  ch[k] = 'L';
  make(s, t, k + 1);
  sum1 += a[k];
  sum2 -= b[k];
  ch[k] = 'M';
  make(s, t, k + 1);
  sum2 += b[k];
  sum3 -= c[k];
  ch[k] = 'W';
  make(s, t, k + 1);
  sum3 += c[k];
}
int main() {
  int cnt1, cnt2, t1, t2, ans;
  char ret[30];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", a + i, b + i, c + i);
  m = n - n / 2;
  sum1 = sum2 = sum3 = 0;
  for (int i = 0; i < m; i++) {
    sum1 += a[i];
    sum2 += b[i];
    sum3 += c[i];
  }
  cnt = 0;
  flag = 1;
  make(s, m, 0);
  sort(s, s + cnt);
  cnt1 = cnt;
  sum1 = sum2 = sum3 = 0;
  for (int i = m; i < n; i++) {
    sum1 += a[i];
    sum2 += b[i];
    sum3 += c[i];
  }
  cnt = 0;
  flag = -1;
  make(t, n, m);
  sort(t, t + cnt);
  cnt2 = cnt;
  t1 = t2 = 0;
  flag = 0;
  ans = 0x80000000;
  while (t1 < cnt1 && t2 < cnt2) {
    if (s[t1] <= t[t2])
      t1++;
    else if (s[t1] == t[t2]) {
      flag = 1;
      if (s[t1].s1 + t[t2].s1 > ans) {
        ans = s[t1].s1 + t[t2].s1;
        strcpy(ret, s[t1].choose);
        strcat(ret, t[t2].choose);
      }
      t1++;
      t2++;
    } else
      t2++;
  }
  if (!flag)
    printf("Impossible\n");
  else {
    for (int i = 0; i < n; i++) {
      switch (ret[i]) {
        case 'L':
          puts("MW");
          break;
        case 'M':
          puts("LW");
          break;
        case 'W':
          puts("LM");
          break;
      }
    }
  }
}
