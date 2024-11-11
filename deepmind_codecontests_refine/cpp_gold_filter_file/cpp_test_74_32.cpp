#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 1.3e7 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, m;
int a[N], b[N];
int vis[M];
int v[2][N], g[N];
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(b[i]);
  sort(b + 1, b + n + 1);
  int tot = unique(b + 1, b + n + 1) - b - 1;
  if (tot < n) {
    for (int i = 1; i <= tot; i++) a[i] = b[i];
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (b[i] & 1) {
      int p1 = 0, p2 = 0;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1)) p1 = j;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1 ^ 1)) p2 = j;
      if (!p1 || !p2) continue;
      a[i] = (-b[i] + b[p1] + b[p2]) / 2;
      for (int j = 1; j <= n; j++)
        if (i != j) a[j] = b[j] - a[i];
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      puts("");
      return 0;
    } else {
      int p1 = 0, p2 = 0;
      for (int j = 1; j <= n; j++)
        if (i != j && (b[j] & 1)) {
          p1 = j;
          break;
        }
      for (int j = p1 + 1; j <= n; j++)
        if (i != j && (b[j] & 1)) {
          p2 = j;
          break;
        }
      if (!p1 || !p2) {
        p1 = 0, p2 = 0;
        for (int j = 1; j <= n; j++)
          if (i != j && (b[j] & 1 ^ 1)) {
            p1 = j;
            break;
          }
        for (int j = p1 + 1; j <= n; j++)
          if (i != j && (b[j] & 1 ^ 1)) {
            p2 = j;
            break;
          }
      }
      if (!p1 || !p2) continue;
      a[i] = (-b[i] + b[p1] + b[p2]) / 2;
      for (int j = 1; j <= n; j++)
        if (i != j) a[j] = b[j] - a[i];
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      puts("");
      return 0;
    }
  m = min(n, 26);
  int s1 = -1, s2 = -1;
  for (int S = 0; S < 1 << m; S++)
    if (__builtin_popcount(S) == m / 2) {
      int sum = 0;
      for (int i = 0; i < m; i++)
        if (S >> i & 1) sum += b[i + 1];
      if (vis[sum]) {
        s1 = S, s2 = vis[sum];
        break;
      }
      vis[sum] = S;
    }
  if (s1 == -1) return puts("NO"), 0;
  int s3 = s1 & s2;
  s1 ^= s3, s2 ^= s3;
  int tot1 = 0, tot2 = 0, tot3 = 0;
  for (int i = 0; i < m; i++)
    if (s1 >> i & 1) v[0][++tot1] = b[i + 1];
  for (int i = 0; i < m; i++)
    if (s2 >> i & 1) v[1][++tot2] = b[i + 1];
  for (int i = 1; i <= tot1; i++) g[++tot3] = v[0][i], g[++tot3] = v[1][i];
  for (int i = 2; i <= tot3; i++) a[i] = g[i - 1] - a[i - 1];
  for (int i = 0; i < n; i++)
    if (i > m || (s1 | s2) >> i & 1 ^ 1) a[++tot3] = b[i + 1];
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
  return 0;
}
