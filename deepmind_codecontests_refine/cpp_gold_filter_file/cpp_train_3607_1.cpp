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
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  for (int i = 1; i <= n; i++) {
    cnt[s[i] - 'a']++;
    cnt[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
    if (cnt[i]) return !printf("-1");
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = n - i + 1; j >= 1; j--) {
      if (s[j] == t[i]) {
        now = j + 1;
        break;
      }
    }
    int len = n - now + 1;
    if (len) ans[++tot] = len;
    ans[++tot] = 1;
    ans[++tot] = n - 1;
    num = 0;
    for (int j = n - len - 1; j >= 1; j--) ss[++num] = s[j];
    for (int j = now; j <= n; j++) ss[++num] = s[j];
    ss[++num] = s[now - 1];
    for (int j = 1; j <= n; j++) s[j] = ss[j];
  }
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
