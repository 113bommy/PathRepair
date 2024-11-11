#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  long long f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const long long MAXN = 300005;
long long dis[MAXN][105], d[105][105], c[105][305], msk[MAXN], q[MAXN];
char a[MAXN];
long long n, ans;
long long cnt;
inline void bfs(long long x) {
  long long head = 0, tail = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] == 'a' + x) dis[i][x] = 0, q[tail++] = i;
  dis[x + n + 1][x] = 0;
  while (head != tail) {
    long long now = q[head];
    head++;
    if (now <= n)
      for (long long i = -1; i <= 1; i += 2) {
        long long t = now + i;
        if (dis[t][x] > 100 && 1 <= t && t <= n) {
          dis[t][x] = dis[now][x] + 1, q[tail++] = t;
          long long c = a[t] - 'a' + n + 1;
          if (dis[c][x] > 100) dis[c][x] = dis[now][x] + 1, q[tail++] = c;
        }
      }
    else
      for (long long i = 1; i <= n; i++)
        if (a[i] == 'a' + now - n - 1 && dis[i][x] > 100)
          dis[i][x] = dis[now][x] + 1, q[tail++] = i;
  }
}
int main(int argc, char const *argv[]) {
  n = read();
  scanf("%s", a + 1);
  memset(dis, 127 / 3, sizeof(dis));
  for (long long i = 0; i < 8; i++) {
    bfs(i);
    for (long long j = 0; j < 8; j++) d[j][i] = dis[j + n + 1][i];
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 0; j < 8; j++)
      msk[i] |= (dis[i][j] > d[a[i] - 'a'][j]) << j;
  for (long long i = 1; i <= n; i++) {
    for (long long j = max(i - 15, 1ll); j < i; j++) {
      long long tmp = i - j;
      for (long long k = 0; k < 8; k++)
        tmp = min(tmp, dis[j][k] + dis[i][k] + 1);
      if (tmp > ans) ans = tmp, cnt = 0;
      if (tmp == ans) cnt++;
    }
    long long t = i - 16;
    if (t >= 1) c[a[t] - 'a'][msk[t]]++;
    for (long long j = 0; j < 8; j++)
      for (long long k = 0; k < 256; k++)
        if (c[j][k]) {
          long long tmp = 100;
          for (long long p = 0; p < 8; p++)
            tmp = min(tmp, d[j][p] + 1 + dis[i][p] + (k & (1 << p)));
          if (tmp > ans) ans = tmp, cnt = 0;
          if (tmp == ans) cnt += c[j][k];
        }
  }
  printf("%d %d\n", ans, cnt);
  return 0;
}
