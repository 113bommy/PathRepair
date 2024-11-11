#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int N = 1e6 + 6;
char a[N];
char b[N];
char s[N];
int z[N];
int mod = 1e9 + 7;
long long g[N];
long long gg[N];
int main() {
  int n, m;
  gets(a);
  gets(b);
  n = strlen(a);
  m = strlen(b);
  int d = 0;
  for (int i = 0; i < m; ++i) s[d++] = b[i];
  s[d++] = '#';
  for (int i = 0; i < n; ++i) s[d++] = a[i];
  for (int i = 1; i < d; ++i) {
    int j = z[i - 1];
    while (j > 0 && s[i] != s[j]) j = z[j - 1];
    if (s[i] == s[j]) ++j;
    z[i] = j;
  }
  int pr = 0;
  for (int i = 1; i <= n; ++i) {
    if (z[i + m] == m) pr = i;
    if (pr) {
      g[i] = pr - m + 1;
      g[i] += gg[pr - m];
    }
    g[i] += g[i - 1];
    gg[i] = gg[i - 1] + g[i];
    g[i] %= mod;
    gg[i] %= mod;
  }
  cout << g[n] << endl;
  return 0;
}
