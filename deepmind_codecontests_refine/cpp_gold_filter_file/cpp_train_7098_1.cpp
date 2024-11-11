#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int T, n, k;
int to[N << 1], lnk[N], nxt[N << 1], val[N << 1], cnt;
long long f[N][2];
void add(int x, int y, int z) {
  to[++cnt] = y, nxt[cnt] = lnk[x], lnk[x] = cnt, val[cnt] = z;
}
bool cmp(long long x, long long y) { return x > y; }
void dfs(int x, int fa) {
  vector<long long> v;
  long long sum = 0;
  for (int i = lnk[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    dfs(y, x);
    v.push_back(f[y][1] + val[i] - f[y][0]);
    sum += f[y][0];
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) {
    if ((i + 1) > k) break;
    if (v[i] > 0) sum += v[i];
  }
  f[x][0] = f[x][1] = sum;
  if (v.size() >= k)
    if (v[k - 1] > 0) f[x][1] -= v[k - 1];
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) lnk[i] = 0;
    cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      add(x, y, z), add(y, x, z);
    }
    dfs(1, 0);
    printf("%lld\n", max(f[1][0], f[1][1]));
  }
  return 0;
}
