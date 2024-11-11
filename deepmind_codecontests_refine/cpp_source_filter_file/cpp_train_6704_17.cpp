#include <bits/stdc++.h>
using namespace std;
long long P2[66];
long long up = 1000000000000000000LL;
void init() {
  for (int i = 0; (1LL << i) <= up; ++i) {
    P2[i] = (1LL << i);
  }
}
int count_cnt(long long n) {
  int ret = 0;
  while (n > 0) {
    ++ret;
    n /= 10;
  }
  return ret;
}
set<long long> get_res(long long n) {
  set<long long> sn;
  sn.clear();
  for (int i = 0; P2[i] - 1 <= n; ++i) {
    long long l = 1, r = 1500000001LL, ans = -1, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      long long tmp = mid * (mid - 1) / 2 + mid * (P2[i] - 1);
      if (count_cnt(mid) + count_cnt((P2[i])) > 18) {
        r = mid - 1;
        continue;
      }
      if (tmp <= n) {
        l = mid + 1;
        if (tmp == n) {
          ans = mid;
        }
      } else {
        r = mid - 1;
      }
    }
    if (~ans && ans % 2 == 1) {
      sn.insert(ans * P2[i]);
    }
  }
  return sn;
}
int main() {
  long long n, m;
  init();
  while (cin >> n) {
    set<long long> ret = get_res(n);
    if (ret.size() == 0) {
      cout << -1 << endl;
    } else {
      for (set<long long>::iterator it = ret.begin(); it != ret.end(); ++it) {
        cout << *it << endl;
      }
    }
  }
  return 0;
}
