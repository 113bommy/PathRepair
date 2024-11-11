#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
int n;
vector<long long> res;
long long l[N], t[N], r;
int main() {
  cin >> n >> r;
  for (int i = 1; i <= n; i++) scanf("%lld", l + i);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", t + i);
    if (t[i] < l[i]) {
      puts("-1");
      return 0;
    }
  }
  long long re = 0, cnt = 0, time = 0;
  for (int i = 1; i <= n; i++)
    if (re >= l[i])
      re -= l[i], time += l[i];
    else {
      l[i] -= re, t[i] -= re, time += re, re = 0;
      long long len = max(0LL, l[i] + l[i] - t[i]);
      if (len > 0) {
        cnt += (len - 1) / r + 1;
        if (cnt <= 100000) {
          for (long long j = time + t[i] - len; j < time + t[i]; j += r)
            res.push_back(j);
        }
        re = (r - len % r) % r;
        time += t[i];
      } else
        time += l[i] + l[i];
    }
  cout << cnt << endl;
  if (cnt <= 100000) {
    for (int i = 0; i < res.size(); i++)
      printf("%lld%c", res[i], " \n"[i + 1 == cnt]);
  }
}
