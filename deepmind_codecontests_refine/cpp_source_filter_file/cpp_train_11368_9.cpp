#include <bits/stdc++.h>
char buf[1024];
int cnt[128], p[1024];
int main() {
  scanf("%s", buf);
  int n = strlen(buf), max = 0;
  for (int i = 0; i < n; i++) {
    cnt[buf[i]]++;
    if (cnt[buf[i]] > cnt[max]) {
      max = buf[i];
    }
  }
  for (int i = 2; i <= n; i++) {
    if (p[i]) continue;
    if (i * 2 > n) continue;
    for (int j = i; j <= n; j += i) {
      p[j] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += p[i];
  if (ans > cnt[max]) {
    return puts("NO");
  }
  for (int i = 0; i < n; i++)
    if (p[i]) {
      buf[i] = max;
      cnt[max]--;
    }
  char s = 'a';
  for (int i = 0; i < n; i++)
    if (!p[i]) {
      if (cnt[s]) {
        buf[i] = s;
        cnt[s]--;
      } else {
        s++;
        i--;
      }
    }
  puts("YES");
  printf("%s\n", buf);
  return 0;
}
