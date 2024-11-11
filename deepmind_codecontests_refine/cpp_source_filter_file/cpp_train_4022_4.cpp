#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long t[maxn];
long long n, m, a, d;
long long cnt, ed, nt;
int main() {
  cin >> n >> m >> a >> d;
  for (int i = 1; i <= m; ++i) scanf("%lld", &t[i]);
  int idx = 1;
  while (idx <= m) {
    long long k = ed / a;
    if (k >= n)
      ed = t[idx] + d, cnt++;
    else {
      if (t[idx] > (k + 1) * a) {
        long long tmp = t[idx] / a;
        long long times =
            (tmp - k) / (d / a + 1) + ((tmp - k) % (d / a + 1) > 0);
        cnt += times;
        ed = (k + (times - 1) * (d / a + 1) + 1) * a + d;
      } else
        ed = t[idx] + d, cnt++;
    }
    for (; t[idx] <= ed && idx <= m; idx++)
      ;
  }
  long long pre = ed / a;
  if (pre < n)
    cnt += (n - pre) / ((d / a) + 1) + ((n - pre) % ((d / a) + 1) > 0);
  cout << cnt << endl;
  return 0;
}
