#include <bits/stdc++.h>
using namespace std;
const int M = 801000;
int a[M], n, m, lenb, f[M];
char s[M];
struct node {
  int val, pl;
} b[M];
bool cmp(const node &x, const node &y) {
  if (x.val == y.val) return x.pl < y.pl;
  return x.val < y.val;
}
bool deal(char x) {
  for (int i = 1; i <= n; i++)
    if (b[i].val == x) a[b[i].pl] = 1;
  int ans = 0, k = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0)
      f[i] = f[i - 1] + 1;
    else
      f[i] = 0;
    ans = max(ans, f[i]);
  }
  return ans < m;
}
void solve(char x) {
  int st = 1, hh;
  for (int i = 1; i <= n; i++) {
    if (b[i].val > x) break;
    if (b[i].val == x) {
      hh = i;
      break;
    }
    printf("%c", (char)b[i].val);
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1)
      st = i;
    else if (i - st >= m) {
      while (b[hh].pl < i && b[hh + 1].val == x) hh++;
      if (b[hh].pl > i) hh--;
      num++;
      st = b[hh].pl;
    }
  }
  for (int i = 1; i <= num; i++) printf("%c", x);
  return;
}
int main() {
  scanf("%d%s", &m, s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    b[i].val = s[i];
    b[i].pl = i;
  }
  sort(b + 1, b + 1 + n, cmp);
  int k = 0;
  for (int i = 'a'; i <= 'z'; i++)
    if (deal(i)) {
      k = i - 1;
      break;
    }
  for (int i = 1; i <= n; i++) a[i] = 0;
  for (int i = 'a'; i <= k; i++) deal(i);
  solve(k + 1);
  return 0;
}
