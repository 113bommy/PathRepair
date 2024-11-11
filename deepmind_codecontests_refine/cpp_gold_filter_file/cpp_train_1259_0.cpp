#include <bits/stdc++.h>
int t, n;
char s[105];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    bool suc = true;
    for (int i = 1, j = n; i < j; i++, j--) {
      bool f = false;
      for (int p = -1; p <= 1 && !f; p++)
        if (p && s[i] + p >= 'a' && s[i] + p <= 'z')
          for (int q = -1; q <= 1 && !f; q++)
            if (q && s[j] + q >= 'a' && s[i] + p <= 'z' && s[i] + p == s[j] + q)
              f = true;
      if (!f) {
        suc = false;
        break;
      }
    }
    printf("%s\n", suc ? "YES" : "NO");
  }
}
