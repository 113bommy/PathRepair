#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char ch[2005][2005];
int n, m, u, d, l, r;
int main() {
  n = read();
  m = read();
  u = 2147483647;
  d = -2147483647;
  l = 2147483647;
  r = -2147483647;
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ch[i][j] == 'w') {
        d = max(d, i);
        u = min(u, i);
        l = min(l, j);
        r = max(r, j);
      }
  if (r - l == d - u) {
    for (int i = l + 1; i <= r - 1; i++)
      for (int j = u + 1; j <= d - 1; j++)
        if (ch[j][i] == 'w') {
          puts("-1");
          return 0;
        }
    for (int i = l; i <= r; i++) {
      if (ch[u][i] == '.') ch[u][i] = '+';
      if (ch[d][i] == '.') ch[d][i] = '+';
    }
    for (int i = u; i <= d; i++) {
      if (ch[i][l] == '.') ch[i][l] = '+';
      if (ch[i][r] == '.') ch[i][r] = '+';
    }
    for (int i = 1; i <= n; i++) puts(ch[i] + 1);
  } else {
    for (int i = l + 1; i <= r - 1; i++)
      for (int j = u + 1; j <= d - 1; j++)
        if (ch[j][i] == 'w') {
          puts("-1");
          return 0;
        }
    if (r - l < d - u) {
      int now = d - u + 1;
      while (l == r) {
        bool fl = false;
        for (int i = u + 1; i <= d - 1; i++)
          if (ch[i][l] == 'w') fl = 1;
        if (!fl) break;
        if (l + now - 1 <= m) {
          for (int i = l; i <= l + now - 1; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
          for (int i = u; i <= d; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][l + now - 1] == '.') ch[i][l + now - 1] = '+';
          }
        } else if (r - now + 1 >= 1) {
          for (int i = r - now + 1; i <= r; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
          for (int i = u; i <= d; i++) {
            if (ch[i][r - now + 1] == '.') ch[i][r - now + 1] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
        } else {
          puts("-1");
          return 0;
        }
        for (int i = 1; i <= n; i++) puts(ch[i] + 1);
        return 0;
      }
      bool fl1 = false, fl2 = false;
      for (int j = u + 1; j <= d - 1; j++) {
        if (ch[j][l] == 'w') fl1 = true;
        if (ch[j][r] == 'w') fl2 = true;
      }
      if (fl1 && fl2) {
        puts("-1");
        return 0;
      } else if (fl1) {
        if (l + now - 1 > m) {
          puts("-1");
          return 0;
        }
        for (int i = l; i <= l + now - 1; i++) {
          if (ch[u][i] == '.') ch[u][i] = '+';
          if (ch[d][i] == '.') ch[d][i] = '+';
        }
        for (int i = u; i <= d; i++) {
          if (ch[i][l] == '.') ch[i][l] = '+';
          if (ch[i][l + now - 1] == '.') ch[i][l + now - 1] = '+';
        }
      } else if (fl2) {
        if (r - now + 1 < 1) {
          puts("-1");
          return 0;
        }
        for (int i = r - now + 1; i <= r; i++) {
          if (ch[u][i] == '.') ch[u][i] = '+';
          if (ch[d][i] == '.') ch[d][i] = '+';
        }
        for (int i = u; i <= d; i++) {
          if (ch[i][r - now + 1] == '.') ch[i][r - now + 1] = '+';
          if (ch[i][r] == '.') ch[i][r] = '+';
        }
      } else {
        if (l + now - 1 <= m) {
          for (int i = l; i <= l + now - 1; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
          for (int i = u; i <= d; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][l + now - 1] == '.') ch[i][l + now - 1] = '+';
          }
        } else if (r - now + 1 >= 1) {
          for (int i = r - now + 1; i <= r; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
          for (int i = u; i <= d; i++) {
            if (ch[i][r - now + 1] == '.') ch[i][r - now + 1] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
        } else if (m >= now) {
          for (int i = 1; i <= now; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
          for (int i = u; i <= d; i++) {
            if (ch[i][1] == '.') ch[i][1] = '+';
            if (ch[i][now] == '.') ch[i][now] = '+';
          }
        } else {
          puts("-1");
          return 0;
        }
      }
    } else {
      int now = r - l + 1;
      while (u == d) {
        bool fl = false;
        for (int i = l + 1; i <= r - 1; i++)
          if (ch[u][i] == 'w') fl = 1;
        if (!fl) break;
        if (u + now - 1 <= n) {
          for (int i = u; i <= u + now - 1; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
          for (int i = l; i <= r; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[u + now - 1][i] == '.') ch[u + now - 1][i] = '+';
          }
        } else if (d - now + 1 >= 1) {
          for (int i = d - now + 1; i <= d; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
          for (int i = l; i <= r; i++) {
            if (ch[d - now + 1][i] == '.') ch[d - now + 1][i] = '+';
            if (ch[u][i] == '.') ch[u][i] = '+';
          }
        } else {
          puts("-1");
          return 0;
        }
        for (int i = 1; i <= n; i++) puts(ch[i] + 1);
        return 0;
      }
      bool fl1 = false, fl2 = false;
      for (int i = l + 1; i <= r - 1; i++) {
        if (ch[u][i] == 'w') fl1 = true;
        if (ch[d][i] == 'w') fl2 = true;
      }
      if (fl1 && fl2) {
        puts("-1");
        return 0;
      } else if (fl1) {
        if (u + now - 1 > n) {
          puts("-1");
          return 0;
        }
        for (int i = u; i <= u + now - 1; i++) {
          if (ch[i][l] == '.') ch[i][l] = '+';
          if (ch[i][r] == '.') ch[i][r] = '+';
        }
        for (int i = l; i <= r; i++) {
          if (ch[u][i] == '.') ch[u][i] = '+';
          if (ch[u + now - 1][i] == '.') ch[u + now - 1][i] = '+';
        }
      } else if (fl2) {
        if (d - now + 1 < 1) {
          puts("-1");
          return 0;
        }
        for (int i = d - now + 1; i <= d; i++) {
          if (ch[i][l] == '.') ch[i][l] = '+';
          if (ch[i][r] == '.') ch[i][r] = '+';
        }
        for (int i = l; i <= r; i++) {
          if (ch[d - now + 1][i] == '.') ch[d - now + 1][i] = '+';
          if (ch[d][i] == '.') ch[d][i] = '+';
        }
      } else {
        if (u + now - 1 <= n) {
          for (int i = u; i <= u + now - 1; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
          for (int i = l; i <= r; i++) {
            if (ch[u][i] == '.') ch[u][i] = '+';
            if (ch[u + now - 1][i] == '.') ch[u + now - 1][i] = '+';
          }
        } else if (d - now + 1 >= 1) {
          for (int i = d - now + 1; i <= d; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
          for (int i = l; i <= r; i++) {
            if (ch[d - now + 1][i] == '.') ch[d - now + 1][i] = '+';
            if (ch[d][i] == '.') ch[d][i] = '+';
          }
        } else if (n >= now) {
          for (int i = 1; i <= now; i++) {
            if (ch[i][l] == '.') ch[i][l] = '+';
            if (ch[i][r] == '.') ch[i][r] = '+';
          }
          for (int i = l; i <= r; i++) {
            if (ch[1][i] == '.') ch[1][i] = '+';
            if (ch[now][i] == '.') ch[now][i] = '+';
          }
        } else {
          puts("-1");
          return 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) puts(ch[i] + 1);
  }
  return 0;
}
