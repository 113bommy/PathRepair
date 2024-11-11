#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
bool check(long long n, int i, long long x) {
  x = x << 1 | 1LL;
  if ((x << i) <= n - x * (x - 3) / 2) {
    return true;
  } else {
    return false;
  }
}
int main() {
  long long n;
  scanf("%I64d", &n);
  ans.clear();
  for (int i = 0; i < 63 && (1LL << i) <= n + 1LL; i++) {
    if (((1LL << i) == n + 1LL)) {
      ans.push_back(1LL << i);
    }
    if ((1LL << i) > n) {
      continue;
    }
    long long l = 1, r = n / (1LL << i);
    r = min(r, n >> i);
    r = min(r, (long long)sqrt(n) + 3);
    r = (r - 1) >> 1;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      if (check(n, i, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    l = l << 1 | 1LL;
    if ((l << i) == n - l * (l - 3) / 2) {
      ans.push_back(l << i);
    }
  }
  if (!ans.size()) {
    puts("-1");
    return 0;
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    printf("%I64d\n", ans[i]);
  }
  return 0;
}
