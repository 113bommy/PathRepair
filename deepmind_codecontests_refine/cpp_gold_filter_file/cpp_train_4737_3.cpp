#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int p[maxn];
bool f[maxn];
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("YES");
    return 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  vector<int> v;
  int minlen = 0x7FFFFFFF;
  int minp = -1;
  for (int i = 1; i <= n; i++)
    if (!f[i]) {
      int len = 1;
      f[i] = 1;
      int w = i;
      while (!f[p[w]]) {
        w = p[w];
        f[w] = 1;
        len++;
      }
      v.push_back(len);
      if (len < minlen) {
        minlen = len;
        minp = i;
      }
    }
  if (minlen >= 3) {
    puts("NO\n");
    return 0;
  }
  for (int i = 0; i < v.size(); i++)
    if (v[i] % minlen) {
      puts("NO\n");
      return 0;
    }
  printf("YES\n");
  memset(f, 0, sizeof(f));
  f[minp] = 1;
  while (!f[p[minp]]) {
    printf("%d %d\n", minp, p[minp]);
    minp = p[minp];
    f[minp] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!f[i]) {
      int w = i;
      f[i] = 1;
      printf("%d %d\n", minp, i);
      while (!f[p[w]]) {
        w = p[w];
        minp = p[minp];
        printf("%d %d\n", minp, w);
        f[w] = 1;
      }
    }
  return 0;
}
