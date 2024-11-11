#include <bits/stdc++.h>
using namespace std;
long long x, y, z;
deque<long long> q, p;
bool rec(long long c) {
  long long a = -2e18;
  for (auto i : q) {
    auto it = upper_bound(p.begin(), p.end(), a);
    if (it != p.end() && i + c > a && c >= abs(i - *it)) {
      if (*it > i) {
        a = i + c;
      } else {
        a = i + max((c - (i - *it)) / 2, c - (i - *it) * 2);
      }
    }
  }
  return (p.end() == upper_bound(p.begin(), p.end(), a));
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  scanf("%I64d%I64d", &x, &y);
  for (int i = 0; i < x; i++) {
    scanf("%I64d", &z);
    q.push_back(z);
  }
  for (int i = 0; i < y; i++) {
    scanf("%I64d", &z);
    p.push_back(z);
  }
  long long s = 0, ss = 1e11, mid;
  while (s <= ss) {
    mid = (s + ss) / 2;
    if (!rec(mid)) {
      s = mid + 1;
    } else {
      ss = mid - 1;
    }
  }
  printf("%I64d\n", ss + 1);
  return 0;
}
