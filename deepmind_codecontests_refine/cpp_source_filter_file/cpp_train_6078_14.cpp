#include <bits/stdc++.h>
using namespace std;
int mo = 1000000007;
long long ans;
int p[10], v[10], n, k;
template <class T>
void up(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void down(T& a, T b) {
  if (a > b) a = b;
}
long long fang(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) b ? ans = ans * a % mo : 0, a = a * a % mo;
  return ans;
}
bool work(int x) {
  if (x == 1) return 1;
  if (v[x]) return v[x] == 1;
  v[x] = 2;
  return v[x] = work(p[x]);
}
void check() {
  memset(v, 0, sizeof(v));
  for (int i = 2; i <= k; i++)
    if (!v[i])
      if (!work(i)) return;
  ans++;
}
void dfs(int x) {
  if (x > k) return check();
  for (int i = 1; i <= k; i++) p[x] = i, dfs(x + 1);
}
int main() {
  scanf("%d%d", &n, &k);
  dfs(2);
  ans %= mo;
  ans = ans * fang(n - k, n - k) % mo;
  ans = ans * k % mo;
  printf("%I64d", ans);
  return 0;
}
