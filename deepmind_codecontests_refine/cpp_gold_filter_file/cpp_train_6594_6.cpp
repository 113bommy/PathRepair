#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, u, r, k[35], b[35], p[35];
long long ans = -1e18;
vector<int> a;
void dfs(int num, bool lst) {
  if ((num & 1) == (u & 1)) {
    long long sum = 0;
    for (int(i) = (0); (i) < (n); (i)++) sum += (long long)k[i] * a[i];
    ans = max(ans, sum);
  }
  if (num == u) return;
  vector<int> org = a;
  vector<int> nw;
  for (int(i) = (0); (i) < (n); (i)++) nw.push_back(a[p[i]] + r);
  a = nw;
  nw.clear();
  dfs(num + 1, 0);
  a = org;
  if (lst) return;
  for (int(i) = (0); (i) < (n); (i)++) nw.push_back(a[i] ^ b[i]);
  a = nw;
  dfs(num + 1, 1);
  nw.clear();
  a = org;
}
int main() {
  scanf("%d%d%d", &n, &u, &r);
  a.resize(n);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", &a[i]);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", b + i);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", k + i);
  for (int(i) = (0); (i) < (n); (i)++) {
    scanf("%d", p + i);
    --p[i];
  }
  dfs(0, 0);
  printf("%I64d\n", ans);
  return 0;
}
