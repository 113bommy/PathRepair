#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int prime[maxn];
bool mk[maxn];
int tot;
void init() {
  int i, j;
  int m = (int)sqrt(maxn * 1.0 + 0.5);
  for (i = 2; i <= m; i++) {
    if (!mk[i])
      for (j = i * i; j < maxn; j += i) mk[j] = 1;
  }
  tot = 0;
  for (i = 2; i < maxn; i++)
    if (!mk[i]) prime[tot++] = i;
}
int main() {
  int n, k;
  init();
  while (scanf("%d%d", &n, &k) != EOF) {
    n--;
    int num = 0;
    for (int i = 0; i < tot - 1 && prime[i] <= n; i++) {
      if (prime[i] + prime[i + 1] <= n && !mk[prime[i] + prime[i + 1] + 1]) {
        num++;
        if (num == k) break;
      }
    }
    if (num == k)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
