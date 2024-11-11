#include <bits/stdc++.h>
using namespace std;
long long int rose, n, k;
long long int getVal(int level) {
  long long int temp = 0;
  int cnt = 0;
  for (int i = level; i <= n; i++) {
    temp += (1 << cnt);
    cnt++;
  }
  return temp;
}
long long int dfs(long long int l, long long int r, int level, int arah) {
  if (l == r) return 0;
  long long int sum = 0, mid = (l + r) / 2;
  sum++;
  if (arah == 0) {
    if (k > mid) {
      sum += getVal(level + 1);
      arah ^= 1;
      sum += dfs(mid + 1, r, level + 1, arah ^= 1);
    } else {
      sum += dfs(l, mid, level + 1, arah ^= 1);
    }
  } else {
    if (k <= mid) {
      sum += getVal(level + 1);
      arah ^= 1;
      sum += dfs(l, mid, level + 1, arah ^= 1);
    } else {
      sum += dfs(mid + 1, r, level + 1, arah ^= 1);
    }
  }
  return sum;
}
int main() {
  long long int i, j, m, x, y, ans, curr, res, now;
  scanf("%lld %lld", &n, &k);
  long long int low, high;
  low = 1;
  high = 1 << n;
  rose = dfs(low, high, 0, 0);
  printf("%lld\n", rose);
  return 0;
}
