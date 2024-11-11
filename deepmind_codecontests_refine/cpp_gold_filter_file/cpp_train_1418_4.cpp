#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, li, ns, i, j, k, l, mod = 1e9 + 7, x, y, dp[123456][12][3],
                                    vis[123456];
vector<long long> e[123456];
void dfs(int x, int fa) {
  long long i;
  if (vis[x]) return;
  vis[x] = 1;
  dp[x][0][2] = ns - 1;
  dp[x][1][1] = 1;
  dp[x][0][0] = m - ns;
  for (i = 0; i < e[x].size(); i++) {
    if (e[x][i] == fa) continue;
    dfs(e[x][i], x);
    for (j = li; ~j; j--) {
      long long mem[3] = {0, 0, 0};
      for (k = 0; k <= j; k++) {
        (mem[0] +=
         (dp[x][j - k][0] * (dp[e[x][i]][k][0] + dp[e[x][i]][k][2]))) %= mod;
        (mem[1] += (dp[x][j - k][1] * (dp[e[x][i]][k][2]))) %= mod;
        (mem[2] += (dp[x][j - k][2] * (dp[e[x][i]][k][0] + dp[e[x][i]][k][1] +
                                       dp[e[x][i]][k][2]))) %= mod;
      }
      for (k = 0; k < 3; k++) dp[x][j][k] = mem[k];
    }
  }
}
int main() {
  readll(n);
  readll(m);
  for (i = 1; i < n; i++) {
    readll(x);
    readll(y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  readll(ns);
  readll(li);
  dfs(1, 0);
  long long res = 0;
  for (i = 0; i <= li; i++)
    (res += dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) %= mod;
  writell(res);
  return 0;
}
