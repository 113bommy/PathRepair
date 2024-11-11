#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long n;
long long a[maxn], ans[maxn], q[maxn], t;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, l, r;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    long long summ = a[i], cnt = 1;
    while (t && ans[t] * cnt >= summ * q[t]) {
      summ += ans[t];
      cnt += q[t];
      t--;
    }
    t++;
    ans[t] = summ;
    q[t] = cnt;
  }
  for (i = 1; i <= t; i++) {
    for (j = 1; j <= q[i]; j++) {
      printf("%.9lf\n", (double)ans[i] / q[i]);
    }
  }
  return 0;
}
