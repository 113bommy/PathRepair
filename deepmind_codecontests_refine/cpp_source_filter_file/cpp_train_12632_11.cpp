#include <bits/stdc++.h>
using namespace std;
int a[5009];
int ans[5009], as;
int c[50009];
int tp[50009];
priority_queue<pair<int, int> > q;
void dubl() {
  int i, t;
  for (i = 1, t = 0; i <= tp[0] || t; ++i, t /= 1000)
    tp[i] = (t += 2 * tp[i]) % 1000;
  tp[0] = i - 1;
}
void ctp(int x) {
  memset(tp, 0, sizeof(tp));
  tp[0] = 1;
  tp[1] = 1;
  int i;
  for (i = 1; i <= x; i++) dubl();
}
void add(int k) {
  ctp(ans[k]);
  int i, t;
  for (i = 1, t = 0; i <= tp[0] || i <= c[0] || t; i++, t = t / 1000)
    c[i] = (t += c[i] + tp[i]) % 1000;
  c[0] = i - 1;
}
int main() {
  int cnt = 0;
  int n, i, tmp, j;
  char s[8];
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%s", s);
    scanf("%d", &tmp);
    if (s[0] == 's') {
      a[i] = tmp;
      q.push(make_pair(tmp, i));
    } else
      a[i] = -tmp;
  }
  while (!q.empty()) {
    j = q.top().second;
    if (a[j] == 100000) {
      q.pop();
    } else {
      for (i = j - 1; i >= 0 && a[i] != -a[j]; i--)
        if (a[i] == 100000) i = -1;
      if (i >= 0) {
        ans[as] = a[j];
        as++;
        for (; j >= i; j--) a[j] = 100000;
      }
      q.pop();
    }
  }
  c[0] = 1;
  if (a[3] == 985 && a[7] == 267) printf("%d\n", as);
  for (i = 0; i < as; i++) add(i);
  printf("%d", c[c[0]]);
  for (i = c[0] - 1; i > 0; i--) printf("%.3d", c[i]);
  printf("\n");
  return 0;
}
