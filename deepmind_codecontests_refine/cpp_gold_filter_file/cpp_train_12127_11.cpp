#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, MOD = 7 + 1e9;
char p[maxn];
int nxt[maxn];
int a[maxn], len;
void Next() {
  int i = 0, j = -1;
  nxt[0] = -1;
  while (i < len) {
    if (j == -1 || p[i] == p[j]) {
      i++, j++;
      nxt[i] = j;
    } else
      j = nxt[j];
  }
}
int main() {
  int n, m;
  long long ans;
  scanf("%d%d", &n, &m);
  scanf("%s", p);
  len = strlen(p);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  if (m == 0) {
    ans = 1LL;
    for (int i = 0; i < n; i++) {
      ans = (ans * 26) % MOD;
    }
    printf("%I64d\n", ans);
    return 0;
  }
  Next();
  int last = a[0] + len - 1;
  int kong = a[0] - 1;
  bool ok = 1;
  for (int i = 1; i < m; i++) {
    if (a[i] > last)
      kong += a[i] - last - 1, last = a[i] + len - 1;
    else {
      int tmp = len, gth = last - a[i] + 1;
      while (tmp != 0 && nxt[tmp] != gth) {
        tmp = nxt[tmp];
      }
      if (tmp != 0)
        last = a[i] + len - 1;
      else {
        ok = 0;
        break;
      }
    }
  }
  if (!ok)
    puts("0");
  else {
    kong += n - last;
    ans = 1LL;
    for (int i = 0; i < kong; i++) {
      ans = (ans * 26) % MOD;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
