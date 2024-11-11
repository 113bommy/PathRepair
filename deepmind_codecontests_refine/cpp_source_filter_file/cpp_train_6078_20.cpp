#include <bits/stdc++.h>
using namespace std;
int p[10];
long long f(long long x, long long n) {
  if (x == 0) return 0;
  if (n == 1) return x;
  if (n & 1) return (x * f(x, n - 1)) % 1000000007ll;
  long long t = f(x, n / 2);
  return (t * t) % 1000000007ll;
}
bool dfs(int x, int r) {
  if (x == 1) return 1;
  if ((1 << x) & r) return 0;
  r |= 1 << x;
  dfs(p[x], r);
}
long long s = 0;
void dfs1(int x, int k) {
  int i, j;
  if (x == k + 1) {
    for (i = 2; i <= k; i++)
      if (!dfs(i, 0)) return;
    s++;
    return;
  }
  for (i = 1; i <= k; i++) {
    p[x] = i;
    dfs1(x + 1, k);
  }
}
int main() {
  int i, j, k, n, m;
  scanf("%d%d", &n, &k);
  long long ans = 0;
  ans += f(n - k, n - k);
  dfs1(2, k);
  ans = (ans * k) % 1000000007ll;
  ans = (ans * s) % 1000000007ll;
  cout << ans << endl;
  return 0;
}
