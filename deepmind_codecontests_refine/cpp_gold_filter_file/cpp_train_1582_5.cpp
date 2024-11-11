#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int M = 2005;
int n, k, a[N], sum, cnt, b[N];
bitset<M> f[1 << N];
void work(int tot) {
  if (tot == n) return;
  int B = 0;
  for (int i = 0; i <= n - tot; i++) B = max(B, b[i]);
  int t1 = 0, t2 = 0;
  for (int i = 0; i <= n - tot; i++)
    if (b[i] == B) {
      if (!t1)
        t1 = i;
      else {
        t2 = i;
        break;
      }
    }
  printf("%d %d\n", a[t1], a[t2]);
  int cnt = 0, tmp;
  for (tmp = a[t1] + a[t2]; !(tmp % k); tmp /= k) cnt++;
  b[t1] = B - cnt, a[t1] = tmp;
  for (int i = t2; i < n - tot; i++) a[i] = a[i + 1], b[i] = b[i + 1];
  work(tot + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
  f[0][0] = 1;
  for (int S = 0; S < (1 << n); S++)
    if (f[S].count()) {
      for (int i = sum; i >= 1; i--)
        if (!(i % k)) f[S][i / k] = f[S][i / k] | f[S][i];
      for (int i = 0; i < n; i++)
        if (!((S >> i) & 1)) f[S | (1 << i)] = f[S | (1 << i)] | (f[S] << a[i]);
    }
  if (f[(1 << n) - 1][1]) {
    puts("YES");
    int S = (1 << n) - 1, x = 1, cnt = 0;
    for (int i = 1; i <= n; i++) {
      while (x * k <= sum && f[S][x * k]) x *= k, cnt++;
      for (int j = 0; j < n; j++)
        if (x >= a[j] && (S & (1 << j)) && f[S ^ (1 << j)][x - a[j]]) {
          b[j] = cnt;
          S ^= 1 << j, x -= a[j];
          break;
        }
    }
    work(1);
  } else
    puts("NO");
  return 0;
}
