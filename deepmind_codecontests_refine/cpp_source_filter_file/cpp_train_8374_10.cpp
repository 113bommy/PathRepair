#include <bits/stdc++.h>
using namespace std;
const int N = 100010, mod = 1000000000 + 7;
int f[N << 1], r[N << 1], val[N];
void find(int x) {
  if (f[x] == x) return;
  find(f[x]);
  r[x] = r[x] ^ r[f[x]];
  f[x] = f[f[x]];
}
char s[10];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n * 2 - 1; i++) f[i] = i, r[i] = 0, val[i] = -1;
  for (int i = 1; i <= n / 2; i++) f[i] = (n - i + 1), r[i] = 0;
  for (int i = 1; i <= (n - 1) / 2; i++)
    f[n + i] = n + ((n - 1) - i + 1), r[i] = 0;
  for (int i = 1; i <= k; i++) {
    int a, b, c;
    scanf("%d%d%s", &a, &b, s + 1);
    if (s[1] == 'o')
      c = 1;
    else
      c = 0;
    if (a < b) swap(a, b);
    if (a - b + 1 == 2) {
      if (val[n + b] == -1 || val[n + b] == c)
        val[n + b] = c;
      else {
        printf("0\n");
        return 0;
      }
    } else if (a - b + 1 == 1) {
      if (val[a] == -1 || val[a] == c)
        val[a] = c;
      else {
        printf("0\n");
        return 0;
      }
    } else if ((a - b + 1) & 1) {
      int x = (a - b) / 2, y = (a + b) / 2;
      find(x), find(y);
      if (f[x] == f[y]) {
        if (r[x] ^ r[y] != c) {
          printf("0\n");
          return 0;
        }
      } else {
        r[f[x]] = r[x] ^ c ^ r[y];
        f[f[x]] = f[y];
      }
    } else {
      int x = n + (a - b - 1) / 2, y = n + (a + b - 1) / 2;
      find(x), find(y);
      if (f[x] == f[y]) {
        if (r[x] ^ r[y] != c) {
          printf("0\n");
          return 0;
        }
      } else {
        r[f[x]] = r[x] ^ c ^ r[y];
        f[f[x]] = f[y];
      }
    }
  }
  for (int i = 1; i <= n * 2 - 1; i++)
    if (val[i] != -1) {
      find(i);
      if (val[f[i]] != -1 && val[f[i]] != val[i] ^ r[i]) {
        printf("0\n");
        return 0;
      } else
        val[f[i]] = val[i] ^ r[i];
    }
  int ans = 1;
  for (int i = 1; i <= n * 2 - 1; i++)
    if (f[i] == i && val[i] == -1) ans = (ans << 1) % mod;
  printf("%d\n", ans);
  return 0;
}
