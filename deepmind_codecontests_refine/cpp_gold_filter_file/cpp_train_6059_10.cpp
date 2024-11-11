#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
long long n, ans;
long long a[10010], b[10010], vis[10010];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    mp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= n; i++)
    if (mp[a[i]] >= 2)
      for (int j = 1; j <= n; j++)
        if ((a[j] | a[i]) == a[i]) vis[j] = 1;
  for (int i = 1; i <= n; i++)
    if (vis[i]) ans += b[i];
  printf("%lld\n", ans);
}
