#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n, a[N], b[N], f[N], c[N];
inline bool cmp1(int x, int y) { return a[x] > a[y]; }
inline bool cmp2(int x, int y) { return a[x] < a[y]; }
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (a[i] < b[i]) {
      f[i] = 1;
      cnt++;
    }
  }
  int flag = 1;
  if (2 * cnt < n) {
    flag = 0;
    cnt = n - cnt;
  }
  printf("%d\n", cnt);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == flag) {
      c[++tot] = i;
    }
  }
  if (flag)
    sort(c + 1, c + 1 + tot, cmp1);
  else
    sort(c + 1, c + 1 + tot, cmp2);
  for (int i = 1; i <= tot; i++) printf("%d ", c[i]);
  return 0;
}
