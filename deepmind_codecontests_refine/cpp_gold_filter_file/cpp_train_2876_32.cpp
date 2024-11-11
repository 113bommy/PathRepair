#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int mod = 1e9 + 7;
int n, m, a[N], presum[N], inv2[N], f[N], len[N], sum[N], preans[N], out[N];
vector<pair<int, int> > q[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int calc(int l, int r) {
  return (long long)(presum[r] - presum[l - 1] + mod) * inv2[l - 1] % mod;
}
int main() {
  scanf("%d%d", &n, &m);
  inv2[0] = 1;
  for (int i = 1, two = 1; i <= n; ++i, two = two * 2 % mod) {
    scanf("%d", a + i);
    inv2[i] = (long long)inv2[i - 1] * (mod + 1) / 2 % mod;
    presum[i] = (presum[i - 1] + (long long)two * a[i] % mod + mod) % mod;
  }
  for (int i = 1; i <= m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    q[r].push_back(pair<int, int>(l, i));
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
    len[i] = 1;
    sum[i] = a[i];
    while (find(i) > 1 && sum[find(i)] > 0) {
      int x = find(i);
      int y = find(x - 1);
      if (len[y] >= 15 || (((long long)sum[x]) << len[y]) + sum[y] > 1e9)
        sum[y] = 1e9;
      else
        sum[y] += sum[x] << len[y];
      len[y] += len[x];
      f[x] = y;
    }
    preans[find(i)] =
        (preans[find(find(i) - 1)] + 2ll * calc(find(i), i)) % mod;
    for (int j = 0; j < q[i].size(); ++j) {
      int l = q[i][j].first;
      int id = q[i][j].second;
      out[id] = (0ll + preans[find(i)] - preans[find(l)] + mod +
                 calc(l, find(l) + len[find(l)] - 1)) %
                mod;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", out[i]);
  return 0;
}
