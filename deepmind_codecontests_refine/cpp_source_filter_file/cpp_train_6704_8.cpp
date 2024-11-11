#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
int main(void) {
  long long n;
  cin >> n;
  set<long long> ans;
  for (long long t = 0; t < 63; t++) {
    long long low = 1, high = 1000000000;
    while (low <= high) {
      long long mid = (low + high) >> 1;
      if (mid * ((1ll << t) - 1) < 0) {
        high = mid - 1;
        continue;
      }
      long long x = mid;
      if (x % 2 == 0)
        x = x / 2 * (x - 1);
      else
        x = (x - 1) / 2 * x;
      long long tmp = x + mid * ((1ll << t) - 1);
      if (tmp < 0 || tmp > n)
        high = mid - 1;
      else if (tmp == n) {
        if (mid % 2 != 0) ans.insert(mid * (1ll << t));
        break;
      } else
        low = mid + 1;
    }
  }
  if (ans.size() == 0)
    puts("-1");
  else {
    for (set<long long>::iterator it = ans.begin(); it != ans.end(); it++) {
      cout << *it << endl;
    }
  }
}
