#include <bits/stdc++.h>
using namespace std;
int n, arr[120000];
long long sum[120000];
map<long long, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  sum[1] = arr[1];
  mp[sum[1]]++;
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + arr[i];
    mp[sum[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, n - mp[sum[i]]);
  }
  printf("%d\n", ans);
}
