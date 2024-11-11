#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
char a[N], b[N], c[N];
int n;
int z[N], p[N], nxt[N], d[N];
int main() {
  gets(a);
  gets(b);
  n = strlen(a);
  if (strlen(b) != n) {
    puts("-1 -1");
    return 0;
  }
  int lst = 0, l = 0;
  z[0] = n;
  for (int i = 1; i < n; i++) {
    z[i] = lst >= i ? min(lst - i + 1, z[i - l]) : 0;
    while (i + z[i] < n && b[i + z[i]] == b[z[i]]) z[i]++;
    if (i + z[i] - 1 > lst) lst = i + z[i] - 1, l = i;
  }
  lst = -1;
  l = -1;
  for (int i = 0; i < n; i++) {
    p[i] = lst >= i ? min(lst - i + 1, z[i - l]) : 0;
    while (i + p[i] < n && a[i + p[i]] == b[p[i]]) p[i]++;
    if (i + p[i] - 1 > lst) lst = i + p[i] - 1, l = i;
  }
  int tot = 0;
  for (int i = n - 1; ~i; i--) c[++tot] = a[i];
  c[++tot] = 128;
  for (int i = 0; i < n; i++) c[++tot] = b[i];
  nxt[1] = 0;
  for (int i = 2; i <= tot; i++) {
    nxt[i] = nxt[i - 1];
    while (nxt[i] && c[i] != c[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
    if (c[i] == c[nxt[i] + 1]) nxt[i]++;
  }
  int x = -1, y = -1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != b[n - i - 1]) break;
    if (p[i + 1] && i + p[i + 1] + 1 >= n - nxt[n + n - i])
      x = i, y = min(n - nxt[n + n - i] - 1, n - 1);
  }
  printf("%d %d\n", x, y);
  return 0;
}
