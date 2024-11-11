#include <bits/stdc++.h>
int a[30005][6];
char s[105][105];
int n, m, ans;
void solve(int i, int u) {
  if (s[i][u] == '0') {
    s[i][u] = '1';
  } else {
    s[i][u] = '0';
  }
}
void print() {
  printf("%d\n", ans);
  for (int i = 0; i < ans; i++) {
    for (int u = 0; u < 5; u++) {
      printf("%d ", a[i][u]);
    }
    printf("%d\n", a[i][5]);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    ans = 0;
    for (int i = 1; i <= n - 2; i++) {
      for (int u = 1; u <= m; u++) {
        if (s[i][u] == '0') {
          continue;
        } else {
          solve(i, u);
          a[ans][0] = i;
          a[ans][1] = u;
          if (u == m) {
            solve(i + 1, u);
            solve(i + 1, u - 1);
            a[ans][2] = i + 1;
            a[ans][3] = u;
            a[ans][4] = i + 1;
            a[ans][5] = u - 1;
          } else {
            solve(i + 1, u);
            solve(i + 1, u + 1);
            a[ans][2] = i + 1;
            a[ans][3] = u;
            a[ans][4] = i + 1;
            a[ans][5] = u + 1;
          }
        }
        ans++;
      }
    }
    for (int i = 1; i <= m - 2; i++) {
      for (int u = n - 1; u <= n; u++) {
        if (s[u][i] == '0') {
          continue;
        } else {
          solve(u, i);
          a[ans][0] = u;
          a[ans][1] = i;
          solve(u, i + 1);
          a[ans][2] = u;
          a[ans][3] = i + 1;
          if (u == n - 1) {
            solve(n, i + 1);
            a[ans][4] = n;
            a[ans][5] = i + 1;
          } else {
            solve(n - 1, i + 1);
            a[ans][4] = n - 1;
            a[ans][5] = i + 1;
          }
        }
        ans++;
      }
    }
    int num = 0;
    for (int i = n - 1; i <= n; i++) {
      for (int u = m - 1; u <= m; u++) {
        if (s[i][u] == '1') {
          num++;
        }
      }
    }
    if (num == 0) {
      print();
    } else if (num == 4) {
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n;
      a[ans][3] = m - 1;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m;
      a[ans][2] = n;
      a[ans][3] = m - 1;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n - 1;
      a[ans][3] = m;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n - 1;
      a[ans][3] = m;
      a[ans][4] = n;
      a[ans][5] = m - 1;
      ans++;
      print();
    } else if (num == 3) {
      int vis = 0;
      for (int i = n - 1; i <= n; i++) {
        for (int u = m - 1; u <= m; u++) {
          if (s[i][u] == '1') {
            a[ans][vis++] = i;
            a[ans][vis++] = u;
          }
        }
      }
      ans++;
      print();
    } else if (num == 2) {
      int vis = 0;
      int q = 1;
      int r, c;
      for (int i = n - 1; i <= n; i++) {
        if (!q) {
          break;
        }
        for (int u = m - 1; u <= m; u++) {
          if (s[i][u] == '1') {
            a[ans][vis++] = i;
            a[ans][vis++] = u;
            s[i][u] = '0';
            q = 0;
            r = i;
            c = u;
            break;
          }
        }
      }
      for (int i = n - 1; i <= n; i++) {
        for (int u = m - 1; u <= m; u++) {
          if (i == r && u == c) {
            continue;
          }
          if (s[i][u] == '0') {
            a[ans][vis++] = i;
            a[ans][vis++] = u;
            s[i][u] = '1';
          }
        }
      }
      ans++;
      vis = 0;
      for (int i = n - 1; i <= n; i++) {
        for (int u = m - 1; u <= m; u++) {
          if (s[i][u] == '1') {
            a[ans][vis++] = i;
            a[ans][vis++] = u;
          }
        }
      }
      ans++;
      print();
    } else {
      int vis = 0;
      for (int i = n - 1; i <= n; i++) {
        for (int u = m - 1; u <= m; u++) {
          if (s[i][u] != '1') {
            a[ans][vis++] = i;
            a[ans][vis++] = u;
            s[i][u] = 1;
          }
        }
      }
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n;
      a[ans][3] = m - 1;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m;
      a[ans][2] = n;
      a[ans][3] = m - 1;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n - 1;
      a[ans][3] = m;
      a[ans][4] = n;
      a[ans][5] = m;
      ans++;
      a[ans][0] = n - 1;
      a[ans][1] = m - 1;
      a[ans][2] = n - 1;
      a[ans][3] = m;
      a[ans][4] = n;
      a[ans][5] = m - 1;
      ans++;
      print();
    }
  }
}
