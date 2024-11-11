#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = 5005, K = 26;
int n, m, ct[K], p[M], tot;
char a[N], b[N], c[N];
void cz(int x) {
  for (int i = n - x + 1, j = x; i <= n; i++, j--) c[j] = a[i];
  for (int j = x + 1, i = 1; j <= n; i++, j++) c[j] = a[i];
  memcpy(a, c, sizeof c);
  p[++tot] = x;
}
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) ct[a[i] - 'a']++;
  for (int i = 1; i <= n; i++) ct[b[i] - 'a']--;
  for (int i = 0; i < K; i++)
    if (ct[i] != 0) {
      puts("-1");
      return 0;
    }
  int l, r, x, y;
  l = r = (n + 1) >> 1;
  if (a[n] != b[l]) {
    for (int i = 1; i <= n; i++)
      if (a[i] == b[l]) {
        x = i;
        break;
      }
    cz(n - x);
  }
  bool fx = 0;
  for (l--, r++; l >= 1; l--, r++) {
    for (int i = 1; i <= n; i++)
      if (a[i] == b[l]) {
        x = i;
        break;
      }
    for (int i = 1; i <= n; i++)
      if (a[i] == b[r] && i != x) {
        y = i;
        break;
      }
    if (fx) swap(x, y);
    fx = !fx;
    char tp = a[y];
    cz(n - x);
    cz(n);
    cz(r - l - 1);
    for (int i = r - l + 1; i <= n; i++)
      if (a[i] == tp) {
        y = i;
        break;
      }
    int tmp = n - y;
    cz(n - y + 1);
    cz(n - tmp - (r - l + 1));
  }
  if ((n & 1) == 0 && !fx) {
    cz(n - 1);
    cz(1);
    fx = !fx;
  }
  if (fx) cz(n);
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d ", p[i]);
  puts("");
  return 0;
}
