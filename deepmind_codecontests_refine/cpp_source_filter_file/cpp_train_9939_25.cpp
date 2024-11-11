#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], b[maxn], c[maxn];
int main() {
  int n, tot = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    if (b[a[i]] % 2 == 1)
      tot++;
    else
      tot--;
  }
  if (tot > 1) {
    printf("0\n");
    return 0;
  }
  int i;
  for (i = 0; i <= n / 2; i++) {
    if (a[i] == a[n - 1 - i])
      b[a[i]] -= 2;
    else
      break;
  }
  if (i == n / 2) {
    printf("%I64d\n", (long long)n * (n - 1) / 2);
    return 0;
  }
  int l, r, cnt = 0;
  l = i;
  r = n - 1 - i;
  for (i = 0; i <= n; i++) c[i] = 0;
  for (i = l; i <= r; i++) {
    if (i < n / 2) {
      c[a[i]]++;
      if (c[a[i]] <= b[a[i]] / 2)
        cnt++;
      else
        break;
    } else {
      if (a[i] == a[n - 1 - i] && (b[a[i]] % 2 || n % 2 == 0))
        cnt++;
      else
        break;
    }
  }
  for (int i = 0; i <= n; i++) c[i] = 0;
  for (i = r; i >= l; i--) {
    if (i > n / 2 || (i == n / 2 && n % 2 == 0)) {
      c[a[i]]++;
      if (c[a[i]] <= b[a[i]] / 2)
        cnt++;
      else
        break;
    } else {
      if (a[i] == a[n - 1 - i] && (n % 2 == 0 || b[a[i]] % 2))
        cnt++;
      else
        break;
    }
  }
  printf("%I64d\n", (long long)(l + 1) * (l + cnt + 1));
  return 0;
}
