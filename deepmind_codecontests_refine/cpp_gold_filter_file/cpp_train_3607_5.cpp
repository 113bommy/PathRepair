#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
char s[maxn], t[maxn];
char ss[maxn];
int num;
int cnt[27];
int ans[maxn << 2], tot;
int main() {
  int n = readint();
  scanf("%s%s", s + 1, t + 1);
  for (int i = 1; i <= n; i++) {
    cnt[s[i] - 'a']++;
    cnt[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
    if (cnt[i] != 0) return !printf("-1");
  for (int i = 1; i <= n; i++) {
    int now = n - i + 1;
    while (s[now] != t[i]) now--;
    if (now == n) continue;
    ans[++tot] = n - now;
    ans[++tot] = 1;
    ans[++tot] = n;
    num = 0;
    for (int j = now - 1; j >= 1; j--) ss[++num] = s[j];
    for (int j = now + 1; j <= n; j++) ss[++num] = s[j];
    ss[++num] = s[now];
    for (int j = 1; j <= n; j++) s[j] = ss[j];
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
