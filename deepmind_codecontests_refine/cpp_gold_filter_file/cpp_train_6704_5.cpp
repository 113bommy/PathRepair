#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  set<long long> ans;
  for (int i = 0; i < 63; i++) {
    long long D = pow(2, i) - 1;
    if (n == D) {
      ans.insert(D + 1);
      continue;
    }
    long long s = 0, e = 1e10;
    while (s <= e) {
      long long mid = s + (e - s) / 2;
      long long t = mid;
      t *= (mid - 1);
      t /= 2;
      if (D != 0 and mid > (LLONG_MAX / D)) {
        t = LLONG_MAX;
      } else {
        t += mid * D;
      }
      if (t == n) {
        if (mid & 1) {
          ans.insert(mid * (D + 1));
        } else {
          break;
        }
      }
      if (t < n) {
        s = mid + 1;
      } else
        e = mid - 1;
    }
  }
  if (ans.empty()) {
    cout << "-1\n";
  } else {
    for (long long i : ans) {
      cout << i << "\n";
    }
  }
  return 0;
}
