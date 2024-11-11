#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || '9' < c; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline void write(long long x) {
  static char buf[20];
  int len = 0;
  if (x < 0) putchar('-'), x = -x;
  for (; x; x /= 10) buf[len++] = x % 10 + '0';
  if (!len)
    putchar('0');
  else
    while (len) putchar(buf[--len]);
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
int mp[2010][2010];
std::bitset<2010> S[2010], T[2010];
int mark[2010], id[2010];
int n, m, tot;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int k = read();
    for (int j = 1; j <= k; j++) {
      int x = read();
      S[i].set(x);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      std::bitset<2010> tmp = S[i] & S[j];
      if (tmp.count() == 2) {
        int flag = 0, x = 0, y = 0;
        for (int j = 1; j <= n; j++)
          if (tmp[j]) {
            if (!flag)
              x = j, flag = 1;
            else
              y = j;
          }
        T[x].set(y);
        T[y].set(x);
        mark[x] = mark[y] = 1;
        if (!mp[x][y]) ++tot, mp[x][y] = mp[y][x] = 1;
      }
    }
  for (int i = 1; i <= n; i++) T[i].set(i);
  if (!tot) {
    for (int i = 1; i < n; i++) writesp(i), writeln(i + 1);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      id[i] = 0;
      for (int j = 1; j <= n; j++)
        if (S[j][i]) {
          if (!id[i] || S[j].count() < S[id[i]].count()) id[i] = j;
        }
    }
  if (tot == 1) {
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        if (mp[i][j]) x = i, y = j;
    int k = 1;
    while (mark[k]) ++k;
    for (int i = 1; i <= n; i++)
      if (S[id[k]][i] && !mark[i]) mark[i] = -1;
    writesp(x);
    writeln(y);
    for (int i = 1; i <= n; i++)
      if (mark[i] == -1)
        writesp(i), writeln(x);
      else if (!mark[i])
        writesp(i), writeln(y);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (mp[i][j]) writesp(i), writeln(j);
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      std::bitset<2010> tmp = S[id[i]];
      for (int j = 1; j <= n; j++)
        if (!mark[j]) tmp.reset(j);
      for (int j = 1; j <= n; j++)
        if (mark[j] && tmp == T[j]) writesp(i), writeln(j);
    }
  return 0;
}
