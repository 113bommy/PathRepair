#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[2005], b[2005], c[2005][2];
int c1[26], c2[26];
int stk[100005], tp;
int pos, p, q;
void mv(int x) {
  int ct = 0;
  for (int i = n; i >= n - x + 1; i--) {
    c[++ct][q] = c[i][p];
  }
  for (int i = 1; i <= n - x; i++) {
    c[++ct][q] = c[i][p];
  }
  swap(p, q);
}
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) {
    c1[a[i] - 'a']++;
    c2[b[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (c1[i] != c2[i]) {
      printf("-1\n");
      return 0;
    }
  }
  pos = 0, p = 0, q = 1;
  for (int i = 1; i <= n; i++) {
    c[i][p] = a[i];
  }
  while (c[pos + 1][p] == b[pos + 1] && pos < n) pos++;
  if (pos == 0) {
    int t = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i][p] == b[1]) t = i;
    }
    if (t == n) {
      stk[++tp] = n;
      mv(n);
    } else {
      stk[++tp] = (n - t);
      mv(n - t);
      stk[++tp] = n;
      mv(n);
    }
  }
  while (c[pos + 1][p] == b[pos + 1] && pos < n) pos++;
  while (pos < n) {
    int t = 0, t2 = 0, t3 = 0;
    for (int i = pos + 1; i <= n; i++) {
      if (c[i][p] == b[pos + 1 + t])
        t++;
      else
        t = 0;
      if (t > t2) {
        t2 = t;
        t3 = i - t + 1;
      }
    }
    stk[++tp] = (n - t3 + 1);
    mv(n - t3 + 1);
    if (t3 - pos - 1) stk[++tp] = (t3 - pos - 1);
    if (t3 - pos - 1) mv(t3 - pos - 1);
    stk[++tp] = (pos + t2);
    mv(pos + t2);
    stk[++tp] = (n - pos);
    mv(n - pos);
    stk[++tp] = (pos + t2);
    mv(pos + t2);
    while (c[pos + 1][p] == b[pos + 1] && pos < n) pos++;
  }
  printf("%d\n", tp);
  for (int i = 1; i <= tp; i++) {
    printf("%d ", stk[i]);
  }
  return 0;
}
