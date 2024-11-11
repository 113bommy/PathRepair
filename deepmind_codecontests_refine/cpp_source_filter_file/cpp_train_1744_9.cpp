#include <bits/stdc++.h>
using namespace std;
bool f[10000];
long long bfs(int x) {
  memset(f, false, sizeof(f));
  for (int i = 0; i <= x; i++)
    for (int j = 0; j + i <= x; j++)
      for (int k = 0; k + i + j <= x; k++)
        f[50 * i + 10 * j + 5 * k + x - i - j - k] = true;
  long long ans = 0LL;
  for (int i = 1; i < 10000; i++)
    if (f[i]) ans++;
  return ans;
}
int main() {
  long long n;
  scanf("%lld", &n);
  if (n > 200LL)
    printf("%lld\n", 49LL * (n - 200LL) + bfs(200));
  else
    printf("%lld\n", bfs(n));
  return 0;
}
