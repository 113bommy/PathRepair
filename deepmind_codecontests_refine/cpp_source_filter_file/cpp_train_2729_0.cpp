#include <bits/stdc++.h>
using namespace std;
int n, a[65];
int mask[65], cnt[1 << 10];
bool bl[65];
int fa[65];
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % 1000000007;
    y >>= 1;
    x = (long long)x * x % 1000000007;
  }
  return ret;
}
int C(int n, int m) {
  if (m > n) return 0;
  int a = 1, b = 1;
  for (int i = n - m + 1; i <= n; i++) a = (long long)a * i % 1000000007;
  for (int i = 1; i <= m; i++) b = (long long)b * i % 1000000007;
  return (long long)a * qpow(b, 1000000007 - 2) % 1000000007;
}
int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) fa[fx] = fy;
}
int f[65][1 << 10];
int rk[65];
pair<int, int> calc(int x) {
  int num = 0, m = 0;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    if (find(i) == x && bl[i]) rk[i] = ++m;
  for (int i = 1; i <= n; i++)
    if (find(i) == x && !bl[i]) {
      num++;
      for (int j = 1; j <= n; j++)
        if (bl[j] && a[i] % a[j] == 0) mask[i] |= 1 << (rk[j] - 1);
    }
  if (num == 0) return make_pair(1, 0);
  for (int i = 0; i <= (1 << m) - 1; i++) {
    cnt[i] = 0;
    for (int j = 1; j <= n; j++)
      if (find(j) == x && !bl[j] && (mask[j] | i) == i) cnt[i]++;
  }
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++)
    if (find(i) == x && !bl[i]) f[1][mask[i]]++;
  for (int i = 1; i <= num - 1; i++)
    for (int j = 0; j <= (1 << m) - 1; j++)
      if (f[i][j]) {
        (f[i + 1][j] += (long long)f[i][j] * (cnt[j] - i) % 1000000007) %=
            1000000007;
        for (int k = 1; k <= n; k++)
          if (find(k) == x && !bl[k] && (mask[k] & j) != 0 &&
              (mask[k] | j) != j) {
            (f[i + 1][mask[k] | j] += f[i][j]) %= 1000000007;
          }
      }
  return make_pair(f[num][(1 << m) - 1], num - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++)
      if (i != j && a[i] % a[j] == 0) {
        merge(i, j);
        flag = false;
      }
    bl[i] = flag;
  }
  int ans = 1, tot_cnt = 0;
  for (int i = 1; i <= n; i++)
    if (find(i) == i) {
      pair<int, int> tmp = calc(i);
      ans = (long long)ans * tmp.first % 1000000007 *
            C(tot_cnt + tmp.second, tot_cnt) % 1000000007;
      tot_cnt += tmp.second;
    }
  printf("%d\n", ans);
  return 0;
}
