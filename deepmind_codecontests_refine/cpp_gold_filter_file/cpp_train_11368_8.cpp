#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;
char a[N];
int b[N], c[30], d[N], f[N], g[N], v[N];
int find(int x) {
  if (f[x] == x) return x;
  f[x] = find(f[x]);
  return f[x];
}
int main() {
  scanf("%s", a);
  n = strlen(a);
  for (int i = 1; i <= n; ++i) b[i] = a[i - 1] - 'a', ++c[b[i]];
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (int i = 2; i <= n; ++i)
    if (!v[i]) {
      int ii = find(i);
      for (int j = 1; j <= n / i; ++j) f[find(i * j)] = ii, v[i * j] = 1;
    }
  for (int i = 1; i <= n; ++i) ++d[find(i)];
  for (int i = 1; i <= n; ++i)
    if (f[i] == i) {
      int k = -1;
      for (int j = 0; j < 26; ++j)
        if (c[j] >= d[i])
          if (k == -1 || c[j] < c[k]) k = j;
      if (k == -1) {
        puts("NO");
        return 0;
      }
      c[k] -= d[i];
      g[i] = k;
    }
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%c", 'a' + (g[f[i]]));
  return 0;
}
