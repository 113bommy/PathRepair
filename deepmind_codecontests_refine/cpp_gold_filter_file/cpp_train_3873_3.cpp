#include <bits/stdc++.h>
using namespace std;
inline void in(int &x) {
  x = 0;
  int s = 1;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (s = -1), c = getchar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
  x *= s;
}
int t, n, s[27], ans, x[2007], y[2007];
char a[10005], b[10005];
int main() {
  in(t);
  while (t--) {
    memset(s, 0, sizeof(s));
    in(n);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++) {
      s[a[i] - 'a']++;
      s[b[i] - 'a']++;
    }
    bool flag = 1;
    for (int i = 0; i < 26 && flag; i++)
      if (s[i] % 2) flag = 0;
    if (!flag) {
      puts("No");
      continue;
    }
    puts("Yes");
    ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) continue;
      bool ok = 0;
      for (int j = i + 1; j < n && !ok; j++)
        if (a[j] == a[i]) {
          ans++;
          x[ans] = j + 1;
          y[ans] = i + 1;
          char t1 = a[j];
          a[j] = b[i];
          b[i] = t1;
          ok = 1;
        }
      if (!ok) {
        for (int j = i + 1; j < n && !ok; j++)
          if (b[j] == a[i]) {
            ans++;
            x[ans] = j + 1;
            y[ans] = j + 1;
            char t1 = a[j];
            a[j] = b[j];
            b[j] = t1;
            ans++;
            x[ans] = j + 1;
            y[ans] = i + 1;
            char t2 = a[j];
            a[j] = b[i];
            b[i] = t2;
            ok = 1;
          }
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++) printf("%d %d\n", x[i], y[i]);
  }
  return 0;
}
