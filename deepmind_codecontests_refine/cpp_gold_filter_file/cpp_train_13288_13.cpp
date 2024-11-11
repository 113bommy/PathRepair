#include <bits/stdc++.h>
using namespace std;
long long gi() {
  long long ret = 0;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  char c = ch == '-' ? getchar() : ch;
  while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
  return ch == '-' ? -ret : ret;
}
const int N = 2000000 + 10;
const int mo = 1e9 + 7;
int n, last, len[N], fail[N], slink[N], link[N], diff[N], allc;
char t[N], s[N];
long long f[N], g[N];
map<int, int> tr[N];
int ins(int x) {
  int p = last, c = s[x] - 'a';
  while (p && s[x - len[p] - 1] != s[x]) p = fail[p];
  if (s[x - len[p] - 1] != s[x]) return last = 0;
  if (!tr[p][c]) {
    int k = fail[p];
    while (k && s[x - len[k] - 1] != s[x]) k = fail[k];
    if (s[x - len[k] - 1] != s[x])
      fail[++allc] = 0;
    else
      fail[++allc] = tr[k][c];
    tr[p][c] = allc;
    len[allc] = len[p] + 2;
    diff[allc] = len[allc] - len[fail[allc]];
    if (diff[allc] == diff[fail[allc]])
      slink[allc] = slink[fail[allc]], g[allc] = g[fail[allc]];
    else
      slink[allc] = fail[allc];
  }
  return last = tr[p][c];
}
int main() {
  scanf("%s", t + 1);
  n = strlen(t + 1);
  int p = n;
  for (int i = 1; i <= n / 2; i += 1) s[i * 2 - 1] = t[i], s[i * 2] = t[p--];
  f[0] = 1;
  for (int i = 1; i <= n; i += 1) {
    for (int o = ins(i); o; o = slink[o]) {
      if (i & 1) break;
      g[o] = f[i - len[slink[o]] - diff[o]];
      if (diff[o] == diff[fail[o]]) (g[o] += g[fail[o]]) %= mo;
      (f[i] += g[o]) %= mo;
    }
  }
  cout << f[n];
  return 0;
}
