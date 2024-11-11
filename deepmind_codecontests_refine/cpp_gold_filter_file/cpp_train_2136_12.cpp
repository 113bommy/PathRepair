#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn], t[maxn];
int n;
int f[500];
int fail[maxn];
int solve() {
  f['W'] = 'E', f['E'] = 'W', f['N'] = 'S', f['S'] = 'N';
  int len = n - 1;
  for (int i = 0; i < len; i++) s[i] = f[s[i]];
  int mid = len >> 1;
  for (int i = 0; i < mid; i++) swap(s[i], s[n - 2 - i]);
  fail[0] = fail[1] = 0;
  for (int i = 1; i < len; i++) {
    int j = fail[i];
    while (j && s[j] != s[i]) j = fail[j];
    fail[i + 1] = s[j] == s[i] ? j + 1 : 0;
  }
  int p = 0;
  for (int i = 0; i < len; i++) {
    while (p && t[i] != s[p]) p = fail[p];
    p = t[i] == s[p] ? 1 + p : 0;
  }
  return !p;
}
int main() {
  while (~scanf("%d", &n)) {
    scanf("%s%s", s, t);
    int ans = solve();
    puts(ans ? "YES" : "NO");
  }
  return 0;
}
