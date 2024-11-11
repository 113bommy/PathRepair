#include <bits/stdc++.h>
int fa[28], a[28], n, cnt;
char s[55];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 26; i++) fa[i] = i;
  while (n--) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) a[s[i] - 'a' + 1] = 1;
    for (int i = 1; s[i]; i++) {
      int p = find(s[i] - 'a' + 1), q = find(s[i - 1] - 'a' + 1);
      if (p != q) fa[p] = q, cnt++;
    }
  }
  for (int i = 1; i <= 26; i++) cnt -= a[i];
  printf("%d", -cnt);
}
