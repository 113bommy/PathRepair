#include <bits/stdc++.h>
using namespace std;
char ch;
bool ok;
void read(long long &x) {
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
const long long maxn = 1000005;
long long n, a[maxn], b[maxn], pos[maxn], nxt[maxn];
long long suma[maxn], sumb[maxn];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]), suma[i] = suma[i - 1] + a[i];
  for (int i = 1; i <= n; i++) read(b[i]), sumb[i] = sumb[i - 1] + b[i];
  memset(pos, -1, sizeof(pos)), pos[0] = 0;
  for (int i = 1; i <= n; i++) {
    nxt[i] = nxt[i - 1];
    while (nxt[i] < n && sumb[nxt[i] + 1] < suma[i]) nxt[i]++;
    long long d = suma[i] - sumb[nxt[i]];
    if (pos[d] != -1) {
      printf("%d\n", i - pos[d]);
      for (int j = pos[d] + 1; j <= i; j++) printf("%d ", j);
      puts("");
      printf("%d\n", nxt[i] - nxt[pos[d]]);
      for (int j = nxt[pos[d]] + 1; j <= nxt[i]; j++) printf("%d ", j);
      puts("");
      break;
    } else
      pos[d] = i;
  }
  return 0;
}
