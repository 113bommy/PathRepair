#include <bits/stdc++.h>
using namespace std;
int main() {
  tuple<long long, long long, long long> p[200010];
  int n;
  cin >> n;
  long long k, a, x, y, m;
  long long b;
  long long ans = 0;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> k >> a >> x >> y >> m;
    long long t = 0;
    for (int j = 0; j < k; j++) {
      p[cnt++] = {t, a, i};
      b = (a * x + y) % m;
      if (b < a && j != k - 1) t++;
      a = b;
    }
    ans = max(ans, t);
  }
  cout << ans << endl;
  sort(p, p + cnt,
       [](tuple<long long, long long, long long> &a,
          tuple<long long, long long, long long> &b) -> bool {
         if (get<0>(a) == get<0>(b)) {
           return get<1>(a) < get<1>(b) ||
                  (get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b));
         }
         return get<0>(a) < get<0>(b);
       });
  for (int i = 0; i < cnt; i++) {
    cout << get<1>(p[i]) << " " << get<2>(p[i]) + 1 << endl;
  }
}
