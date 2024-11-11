#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;
map<long long, int> mp;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  int ans = n - 1;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int tmp = a[1];
  for (int i = 1; i < n; ++i) a[i] = a[i + 1];
  a[n] = a[1];
  for (int i = 1; i <= n; ++i) {
    sum += a[i];
    ++mp[sum];
    ans = min(ans, n - mp[sum]);
  }
  printf("%d\n", ans);
  return 0;
}
