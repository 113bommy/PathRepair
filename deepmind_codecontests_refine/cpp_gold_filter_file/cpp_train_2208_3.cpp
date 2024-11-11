#include <bits/stdc++.h>
char s[150010], t[150010];
int p[150010];
void solve() {
  scanf("%s", s);
  int l;
  for (l = 0; s[l]; l++)
    ;
  int c = 0;
  for (int i = 0; i < l - 4; i++) {
    if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' &&
        s[i + 4] == 'e') {
      s[i + 2] = 0;
      c++;
    }
  }
  int m = 0;
  for (int i = 0; i < l; i++) {
    if (s[i]) {
      p[m] = i;
      t[m++] = s[i];
    }
  }
  for (int i = 0; i < m - 2; i++) {
    if (t[i] == 't' && t[i + 1] == 'w' && t[i + 2] == 'o') {
      t[i + 1] = 0;
      c++;
    } else if (t[i] == 'o' && t[i + 1] == 'n' && t[i + 2] == 'e') {
      t[i + 1] = 0;
      c++;
    }
  }
  printf("%d\n", c);
  for (int i = 0; i < l; i++) {
    if (!s[i]) printf("%d ", i + 1);
  }
  for (int i = 0; i < m; i++) {
    if (!t[i]) printf("%d ", p[i] + 1);
  }
  printf("\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
