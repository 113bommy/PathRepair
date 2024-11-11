#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 1123;
void out(long long arr[maxn][maxn], int n, int m) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      printf("%lld\t", arr[i][j]);
    }
    puts("");
  }
  puts("_____________");
  return;
}
void integral(long long arr[maxn][maxn], int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i][j] += arr[i - 1][j];
      arr[i][j] += arr[i][j - 1];
      arr[i][j] -= arr[i - 1][j - 1];
    }
  }
}
void derivative(long long arr[maxn][maxn], int n, int m) {
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      arr[i][j] -= arr[i - 1][j];
      arr[i][j] -= arr[i][j - 1];
      arr[i][j] += arr[i - 1][j - 1];
    }
  }
}
void add(long long arr[maxn][maxn], int sx, int mx, int sy, int my) {
  arr[mx + 1][my + 1]++;
  arr[mx + 1][sy + 1]--;
  arr[sx + 1][my + 1]--;
  arr[sx + 1][sy + 1]++;
}
long long sum(long long arr[maxn][maxn], int sx, int mx, int sy, int my) {
  return arr[mx][my] - arr[mx][sy] - arr[sx][my] + arr[sx][sy];
}
long long cnt[26][maxn][maxn], times[maxn][maxn];
long long que(int c, int sx, int mx, int sy, int my) {
  long long ret = 0;
  for (int z = 0; z < 26; z++) {
    ret += abs(c - z) * sum(cnt[z], sx, mx, sy, my);
  }
  return ret;
}
long long val[maxn][maxn];
int inp[maxn][maxn];
char input[maxn];
const int maxm = 112345;
int a[maxm], b[maxn], c[maxm], d[maxm], e[maxm];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", input + 1);
    for (int j = 1; j <= m; j++) {
      inp[i][j] = input[j] - 'a';
    }
  }
  memset(times, 0, sizeof(times));
  for (int i = 0; i < k; i++) {
    scanf("%d %d %d %d %s", &a[i], &b[i], &c[i], &d[i], input);
    a[i]--, b[i]--;
    e[i] = *input - 'a';
    add(times, a[i], c[i], b[i], d[i]);
  }
  integral(times, n, m);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt[inp[i][j]][i][j] += k - times[i][j];
    }
  }
  for (int z = 0; z < 26; z++) derivative(cnt[z], n, m);
  for (int i = 0; i < k; i++) add(cnt[e[i]], a[i], c[i], b[i], d[i]);
  for (int z = 0; z < 26; z++) integral(cnt[z], n, m);
  memset(val, 0, sizeof(val));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int z = 0; z < 26; z++) {
        val[i][j] += cnt[z][i][j] * abs(z - inp[i][j]);
      }
    }
  }
  integral(val, n, m);
  for (int z = 0; z < 26; z++) integral(cnt[z], n, m);
  long long ans = INF;
  for (int i = 0; i < k; i++) {
    ans = min(ans, val[n][m] - sum(val, a[i], c[i], b[i], d[i]) +
                       que(e[i], a[i], c[i], b[i], d[i]));
  }
  printf("%I64d\n", ans);
  return 0;
}
