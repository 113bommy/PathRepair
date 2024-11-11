#include <bits/stdc++.h>
using namespace std;
long long n, a[100005];
long long p[100005];
long long is[100005];
long long ck[100005];
vector<long long> bro[100005];
map<long long, long long> yo;
long long tot, so;
long long dfs(long long u) {
  long long ret = 1;
  for (long long i = 0; i < bro[u].size(); i++) {
    return (1 ^ dfs(bro[u][i]));
  }
  return ret;
}
void go(long long u, long long h) {
  if (h == 0)
    yo[a[u]]++;
  else
    tot ^= a[u], so++;
  for (long long i = 0; i < bro[u].size(); i++) {
    go(bro[u][i], h ^ 1);
  }
}
long long ans;
void gogo(long long u, long long h) {
  if (h == 1) {
    long long tem = tot ^ a[u];
    ans += yo[tem];
  }
  for (long long i = 0; i < bro[u].size(); i++) {
    gogo(bro[u][i], h ^ 1);
  }
}
int main() {
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (long long i = 2; i <= n; i++)
    scanf("%I64d", &p[i]), bro[p[i]].push_back(i);
  long long h = dfs(1);
  go(1, h);
  gogo(1, h);
  long long soso = n - so;
  if (tot == 0) ans = ans + (so) * (so - 1) / 2 + (soso) * (soso - 1) / 2;
  cout << ans;
  return 0;
}
