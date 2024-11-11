#include <bits/stdc++.h>
using namespace std;
const int M = 400005;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, a[M], b[M], s[M], f[M];
vector<int> t;
void manacher() {
  for (int i = 1; i <= n; i++) s[i * 2] = b[i];
  for (int i = 1; i <= n; i++) s[i * 2 - 1] = -1;
  s[2 * n + 1] = -1;
  int r = 0, c = 0;
  for (int i = 1; i <= 2 * n + 1; i++) {
    f[i] = r > i ? min(r - i + 1, f[2 * c - i]) : 1;
    while (i + f[i] <= 2 * n + 1 && i - f[i] >= 1 && s[i - f[i]] == s[i + f[i]])
      f[i]++;
    if (i + f[i] - 1 > r) {
      r = i + f[i] - 1;
      c = i;
    }
  }
}
int chk(int l, int r) {
  if (l >= r) return 1;
  int p = l + r;
  int ll = p - f[p] + 1, rr = p + f[p] - 1;
  return ll <= 2 * l && rr >= 2 * r;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
  if (n == 1) {
    printf("%d\n", (a[1] + a[1]) % m);
    return 0;
  }
  manacher();
  for (int i = 1; i < n; i++) {
    if ((a[1] + a[i]) % m == (a[i + 1] + a[n]) % m)
      if (chk(2, i) && chk(i + 2, n)) t.push_back((a[1] + a[i]) % m);
  }
  if (chk(2, n)) t.push_back((a[1] + a[n]) % m);
  sort(t.begin(), t.end());
  printf("%d\n", t.size());
  for (int i = 0; i < t.size(); i++) printf("%d ", t[i]);
}
