#include <bits/stdc++.h>
using namespace std;
char ch[200005], s[200005], t[200005];
int f[200005], g[200005], ans[200005];
void kmp(int n) {
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1];
    while (f[i] && ch[f[i] + 1] != ch[i]) f[i] = f[f[i]];
    f[i] = (ch[f[i] + 1] == ch[i] ? f[i] + 1 : f[i]);
  }
}
void exkmp(int n) {
  int ms = 1;
  for (int i = 2; i <= n; i++) {
    g[i] = max(0, min(g[i - ms + 1], ms + g[ms] - i));
    while (i + g[i] <= n && ch[i + g[i]] == ch[1 + g[i]]) g[i]++;
    if (i + g[i] > ms + g[ms]) ms = i;
  }
  g[1] = n;
}
int main() {
  scanf("%s%s", t + 1, s + 1);
  int n = strlen(s + 1);
  int ls = n, lt = strlen(t + 1);
  for (int i = 1; i <= ls; i++) ch[i] = s[i];
  kmp(n);
  ch[++n] = '*';
  for (int i = 1; i <= lt; i++) ch[++n] = t[i];
  exkmp(n);
  for (int i = ls + 3; i <= n; i++) ans[g[i]]++;
  for (int i = ls; i >= 1; i--) ans[i] += ans[i + 1];
  long long fin = 1ll * lt * ls;
  for (int i = 1; i <= ls; i++)
    if (f[i]) fin -= ans[i - f[i]];
  printf("%I64d\n", fin);
  return 0;
}
