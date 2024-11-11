#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int n, x, sum;
int num[MAXN], belong[MAXN], front[MAXN], back[MAXN], size[MAXN];
bool f[MAXN];
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; ++i) scanf("%d", &front[i]), back[front[i]] = i;
  for (int i = 1; i <= n; ++i)
    if (!front[i]) {
      ++sum;
      for (int j = i; j; j = back[j]) belong[j] = sum, num[j] = ++size[sum];
    }
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (int i = 1; i <= sum; ++i)
    if (i != belong[x])
      for (int j = 100; j >= size[i]; --j) f[j] |= f[j - size[i]];
  for (int i = 0; i < 100; ++i)
    if (f[i]) printf("%d\n", i + num[x]);
  return 0;
}
