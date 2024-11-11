#include <bits/stdc++.h>
const int N = 1e5 + 10;
const int P = 105;
long long f[P][N];
long long sum[N];
inline double getk(int k1, int k2, int i) {
  double dy = (double)(f[i - 1][k2] + sum[k2]) - (f[i - 1][k1] + sum[k1]);
  double dx = k2 - k1;
  return dy / dx;
}
long long sumd[N];
int n, m, p;
int q[N];
long long w[N];
long long t, h;
inline long long read() {
  long long r = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - '0';
    c = getchar();
  }
  return r;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (register int i = 2; i <= n; i++) {
    long long x = read();
    sumd[i] = sumd[i - 1] + x;
  }
  for (register int i = 1; i <= m; i++) {
    h = read();
    t = read();
    w[i] = t - sumd[h];
  }
  std::sort(w + 1, w + m + 1);
  for (register int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + w[i];
  }
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= p; i++) {
    int head = 1, tail = 1;
    q[1] = 0;
    for (int j = 1; j <= m; j++) {
      while (head < tail && getk(q[head], q[head + 1], i) <= w[j]) {
        head++;
      }
      f[i][j] =
          f[i - 1][q[head]] + w[j] * (j - q[head]) - (sum[j] - sum[q[head]]);
      while (head < tail &&
             getk(q[tail - 1], q[tail], i) >= getk(q[tail], j, i)) {
        tail--;
      }
      q[++tail] = j;
    }
  }
  printf("%lld\n", f[p][m]);
  return 0;
}
