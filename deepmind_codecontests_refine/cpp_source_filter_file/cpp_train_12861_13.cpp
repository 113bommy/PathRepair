#include <bits/stdc++.h>
using namespace std;
long long ans[100020];
long long cum[100020];
long long cub(long long x) { return (x * x * x); }
long long m;
long long solve(long long mid) {
  long long i;
  long long sum = 0;
  for (i = 2; i <= 100020; i++) {
    sum += (mid / cub(i));
  }
  return sum;
}
set<int> s;
int main() {
  long long i, j, t;
  cin >> m;
  long long low = 8, high = 1000000000000000LL;
  long long mid;
  while ((high - low) >= 20) {
    mid = (low + high) / 2;
    if (solve(mid) < m) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int flag = 0;
  for (i = low; i <= high; i++) {
    if (solve(i) == m) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    printf("%lld\n", i);
  } else {
    printf("-1\n");
  }
  return 0;
}
