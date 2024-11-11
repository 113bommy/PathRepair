#include <bits/stdc++.h>
using namespace std;
long long pile[100005];
long long n, m;
long long dis = 0;
inline bool check(long long x) {
  int k = m;
  long long s = 0;
  for (int i = 1; i <= dis; ++i) {
    s += pile[i];
    while (s + i >= x) {
      s -= x - i;
      if (--k < 0) return 0;
    }
  }
  if (k == 0) return s <= 0;
  return 1;
}
int main() {
  cin >> n >> m;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &pile[i]);
    sum += pile[i];
    if (pile[i] > 0) dis = i;
  }
  long long left = dis;
  long long right = dis + sum;
  long long res;
  long long mid = (left + right) / 2;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (check(mid)) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  printf("%lld\n", res);
}
