#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[100011], b[100011];
int Pow(int a, int x, int m) {
  int res = 1;
  for (; x; x >>= 1, a = a * 1ll * a % m)
    if (x & 1) res = res * 1ll * a % m;
  return res;
}
int ans = -1, ansd;
int Add(int a, int b) {
  a += b;
  if (a >= m) a -= m;
  if (a < 0) a += m;
  return a;
}
void solve(int *a, int n) {
  int sd = a[1] - a[0], cnt = 0;
  a[n] = -1;
  for (int i = 0; i < n; i++)
    if (binary_search(a, a + n, Add(a[i], sd))) cnt++;
  int k = n - cnt, d = Pow(k, m - 2, m) * 1ll * sd % m;
  ans = -1, ansd = (m - d) % m;
  for (int i = 0; i < n; i++)
    if (!binary_search(a, a + n, Add(a[i], sd)))
      if (ans == -1)
        ans = a[i];
      else {
        ans = -1;
        return;
      }
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  if (n == 1) return printf("%d 0", a[0]), 0;
  if (n == m) return puts("0 1"), 0;
  if (n * 2 < m)
    solve(a, n);
  else {
    int t = 0;
    for (int i = 0; i < m; i++)
      if (!binary_search(a, a + n, i)) b[t++] = i;
    solve(b, t);
    if (ans != -1) {
      (ans += 1ll * ansd * t % m) %= m;
    }
  }
  if (ans == -1) return puts("-1"), 0;
  printf("%d %d\n", ans, ansd);
  return 0;
}
