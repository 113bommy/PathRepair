#include <bits/stdc++.h>
using namespace std;
int T, n;
set<long long> ss;
int main() {
  for (scanf("%d", &T); T--;) {
    scanf("%d", &n);
    long long l = 1, r = 0, k = 1, b = 0;
    int a, ans = n * 2;
    ss.clear();
    while (n--) {
      scanf("%d", &a);
      r = min(r, (long long)a - 1);
      if (k > 0)
        while (!ss.empty() && *(--ss.end()) + b >= a) ss.erase(--ss.end());
      else
        while (!ss.empty() && b - *(ss.begin()) >= a) ss.erase(ss.begin());
      int d = a / 2;
      if (l > r && ss.empty()) {
        k = l = 1, b = 0;
        if (a % 2 == 0) {
          r = 0, --ans;
          ss.insert(d);
        } else
          r = a - 1;
      } else if (a % 2 == 0 &&
                 ((l <= d && d <= r) || ss.find(k * (d - b)) != ss.end())) {
        k = l = 1, b = r = 0, ans -= 2;
        ss.clear(), ss.insert(d);
      } else {
        --ans;
        if (a % 2 == 0) ss.insert(k * (d - b));
      }
      k = -k, b = a - b;
      int nl = a - r, nr = a - l;
      l = nl, r = nr;
    }
    printf("%d\n", ans);
  }
  return 0;
}
