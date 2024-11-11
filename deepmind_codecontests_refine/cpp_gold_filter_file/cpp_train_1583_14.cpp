#include <bits/stdc++.h>
bool judge(int x) {
  int k = sqrt(x);
  for (int i = 2; i <= k; i++)
    if (x % i == 0) return false;
  return true;
}
char s[1010], t[1010];
int a[30];
int main(int argc, const char* argv[]) {
  int ans = 1, len, flag;
  scanf("%s", s);
  len = strlen(s);
  t[1] = '1';
  for (int i = 2; i <= len; i++) {
    if (judge(i) && i * 2 > len) {
      ans++;
      t[i] = '1';
    }
  }
  for (int i = 0; i < len; i++) a[s[i] - 'a' + 1]++;
  for (int i = 1; i <= 26; i++) {
    if (a[i] > a[0]) {
      a[0] = a[i];
      flag = i;
    }
  }
  if (a[0] >= len - ans) {
    printf("YES\n");
    for (int i = 1; i <= len; i++)
      if (t[i] != '1' && a[flag]) {
        t[i] = flag - 1 + 'a';
        a[flag]--;
      }
    for (int i = 1; i <= len; i++)
      if (t[i] != flag - 1 + 'a') {
        int j = 1;
        while (a[j] == 0) j++;
        t[i] = j - 1 + 'a';
        a[j]--;
      }
    for (int i = 1; i <= len; i++) printf("%c", t[i]);
  } else
    printf("NO\n");
  return 0;
}
