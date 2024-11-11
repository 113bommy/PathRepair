#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n, a[N], pre[N], suf[N], prenum[N], sufnum[N], premax[N], sufmax[N];
char s[N];
int p = 1;
int check() {
  if (prenum[p] || sufnum[p] || pre[p] + suf[p + 1]) return -1;
  return max(premax[p], sufmax[p]);
}
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (p > 1) p--;
    } else if (s[i] == 'R') {
      p++;
    } else if (s[i] == '(') {
      a[p] = 1;
    } else if (s[i] == ')') {
      a[p] = -1;
    } else
      a[p] = 0;
    pre[p] = pre[p - 1] + a[p];
    suf[p] = suf[p + 1] + a[p];
    prenum[p] = prenum[p - 1] + (pre[p] < 0 ? 1 : 0);
    sufnum[p] = sufnum[p + 1] + (suf[p] > 0 ? 1 : 0);
    premax[p] = max(premax[p - 1], pre[p]);
    sufmax[p] = max(sufmax[p + 1], suf[p]);
    printf("%d%c", check(), i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
