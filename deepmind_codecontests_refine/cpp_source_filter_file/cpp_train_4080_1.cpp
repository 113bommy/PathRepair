#include <bits/stdc++.h>
using namespace std;
const long long N = 200000;
long long cost(long long a) {
  long long cnt = 0;
  while (a) {
    cnt++;
    a /= 2;
  }
  return cnt;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  set<long long> s;
  vector<long long> f(N + 1);
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    s.insert(a);
    f[a]++;
  }
  long long ans = 0;
  long long cnt = k;
  long long c = 0;
  for (long long i = 1; i <= N; i++) {
    if (f[i] >= cnt) {
      ans += cnt * cost(i);
      cnt = 0;
    } else {
      ans += f[i] * cost(i);
      cnt -= f[i];
    }
    c += f[i];
    f[i] = c;
  }
  for (long long i = 1; i <= n; i++) {
    long long cnt = k;
    long long j = i;
    long long lans = 0;
    long long z = 0;
    long long b = 1;
    while (j <= N) {
      long long sum = f[min(N, j + b - 1)] - f[j - 1];
      if (sum >= cnt) {
        lans += cnt * z;
        cnt = 0;
        break;
      } else {
        lans += sum * z;
        cnt -= sum;
      }
      j *= 2;
      z++;
      b *= 2;
    }
    if (cnt == 0) {
      ans = min(lans, ans);
    }
  }
  cout << ans;
}
