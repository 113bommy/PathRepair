#include <bits/stdc++.h>
using namespace std;
int n, m, a[30], b[30];
long long sum, fact[30];
unordered_map<long long, long long> mp[2][30];
vector<int> vec[2];
int lg[1 << 20];
int f(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret++;
  return ret;
}
void find(int x) {
  vector<int> v = vec[x];
  int sz = v.size();
  for (int i = (0); i < (1 << sz); i++) {
    int cnt = f(i);
    for (int h = (0); h < (1 << cnt); h++) {
      int ok = 1, k = f(h);
      for (int t = (0); t < (sz); t++) b[t] = 0;
      for (int t = i, msk = h; t; t -= t & -t, msk >>= 1)
        b[lg[t & -t]] = 1 + (msk & 1);
      for (int j = (0); j < (sz); j++)
        if (v[j] >= 19 && b[j] == 2) ok = 0;
      if (!ok || k > m) continue;
      unsigned long long tsum = 0;
      for (int j = (0); j < (sz); j++)
        if (b[j]) tsum += b[j] == 1 ? v[j] : fact[v[j]];
      if (tsum > sum) continue;
      mp[x][k][tsum]++;
    }
  }
}
int main() {
  for (int i = (0); i < (20); i++) lg[1 << i] = i;
  fact[0] = fact[1] = 1;
  for (int i = (2); i < (20); i++) fact[i] = fact[i - 1] * i;
  scanf("%d%d%lld", &n, &m, &sum);
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  for (int i = (0); i < (n / 2); i++) vec[0].push_back(a[i]);
  for (int i = (n / 2); i < (n); i++) vec[1].push_back(a[i]);
  find(0);
  find(1);
  long long ans = 0;
  for (int i = (0); i <= (m); i++)
    for (__typeof__((mp[0][i]).begin()) it = (mp[0][i]).begin();
         it != (mp[0][i]).end(); it++) {
      if (it->first > sum) continue;
      for (int j = (0); j <= (m - i); j++)
        ans += mp[1][j][sum - it->first] * it->second;
    }
  cout << ans << '\n';
  return 0;
}
