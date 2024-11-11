#include <bits/stdc++.h>
using namespace std;
const int M = 1 << 16;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
map<long long, int> m;
int a[20][M], path[1 << 16], c[M], head[M], loop[M], v[16], p[M], f[M];
long long sum[M];
int main() {
  int n;
  scanf("%d", &n);
  long long s = 0;
  memset(head, inf, sizeof(head));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    for (int j = 1; j <= c[i]; j++) {
      scanf("%d", &a[i][j]);
      s += a[i][j];
      sum[i] += a[i][j];
      m[a[i][j]] = i;
    }
  }
  if (s % n) {
    puts("No");
    return 0;
  }
  s /= n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= c[i]; j++) {
      long long now = s - sum[i] + a[i][j];
      int f = 1;
      int st = 0;
      if (m.count(now)) {
        st |= (1 << (i - 1));
        while (m[now] != i) {
          if ((st >> (m[now] - 1)) & 1) {
            f = 0;
            break;
          }
          st |= (1 << (m[now] - 1));
          now = s - sum[m[now]] + now;
        }
        if (f && now == a[i][j]) {
          head[st] = a[i][j];
          path[st] = 1;
        }
      }
    }
  int k = (1 << n) - 1;
  path[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j; j = (j - 1) & i) {
      if (head[j] < inf && path[j ^ i]) {
        path[i] = 1;
        loop[i] = j;
        break;
      }
    }
  }
  if (!path[k]) {
    puts("No");
    return 0;
  }
  int nowc = k;
  while (nowc) {
    int nowr = loop[nowc];
    nowc ^= nowr;
    long long now = head[nowr];
    while (!v[m[now]]) {
      v[m[now]] = 1;
      p[m[now]] = now;
      long long to = s - sum[m[now]] + now;
      f[m[to]] = m[now];
      now = to;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", p[i], f[i]);
  }
  return 0;
}
