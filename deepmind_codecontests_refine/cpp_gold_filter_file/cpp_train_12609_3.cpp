#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
char s[MAXN];
int a[MAXN], b[MAXN];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) b[i] = s[i] - 'a';
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  long long ans = 0;
  int st = n + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i])
      ans++;
    else {
      st = i;
      break;
    }
  }
  int tot = 0;
  for (int i = st; i <= n; i++) {
    int mid = max(0, tot - 2);
    if (b[i] == 1 && k) k--, tot++;
    if (a[i] == 0 && k) k--, tot++;
    int det = min(k, mid);
    k -= det;
    tot += det;
    ans += tot;
  }
  printf("%lld\n", ans);
  return 0;
}
