#include <bits/stdc++.h>
using namespace std;
int k, b, n;
int sum, cnt;
map<int, int> mp;
int main() {
  long long ans = 0;
  scanf("%d%d%d", &k, &b, &n);
  mp[0] = 1;
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    if (x == 0)
      cnt++;
    else
      cnt = 0;
    sum += x;
    sum %= (k - 1);
    int tmp = (sum - b + k - 1) % (k - 1);
    if (b == k - 1)
      ans += (long long)mp[tmp] - cnt;
    else if (b == 0)
      ans += (long long)cnt;
    else
      ans += (long long)mp[tmp];
    mp[sum]++;
  }
  printf("%I64d\n", ans);
  return 0;
}
