#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[1000005];
vector<int> v;
long long ans;
long long cal(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long t = cal(x, y / 2);
  t = t * t % 1000000007;
  if (y % 2 == 0)
    return t;
  else
    return t * (long long)x % 1000000007;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m = max(m, a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    v.clear();
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        v.push_back(j);
        if (i / j != j) v.push_back(i / j);
      }
    }
    sort(v.begin(), v.end());
    int pre = lower_bound(a + 1, a + n + 1, 1) - a;
    long long sum = 1;
    for (int j = 1; j < (int)v.size(); j++) {
      int pos = lower_bound(a + 1, a + n + 1, v[j]) - a;
      sum = sum * cal(j, pos - pre) % 1000000007;
      pre = pos;
    }
    int ss = (int)v.size();
    sum = sum * (cal(ss, n - pre + 1) - cal(ss - 1, n - pre + 1) + 1000000007) %
          1000000007 % 1000000007;
    ans = (ans + sum) % 1000000007;
  }
  printf("%I64d\n", ans);
  return 0;
}
