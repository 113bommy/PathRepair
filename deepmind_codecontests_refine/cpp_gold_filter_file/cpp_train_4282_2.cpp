#include <bits/stdc++.h>
using namespace std;
long long abso(long long x) { return x > 0 ? x : (-x); }
signed main() {
  long long n, s;
  scanf("%lld%lld", &n, &s);
  vector<long long> v;
  v.resize(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &v[i]);
    sum += v[i];
  }
  if (sum < s) {
    printf("-1\n");
    return 0;
  }
  sort(v.begin(), v.end());
  long long mn = v[0];
  for (long long i = n - 1; i >= 0 && s > 0; i--) {
    if (v[i] <= mn)
      break;
    else {
      long long give = v[i] - mn;
      if (s >= give) {
        s -= give;
        v[i] = mn;
      } else {
        v[i] = v[i] - s;
        s = 0;
      }
    }
  }
  if (s > 0) {
    long long final = s;
    long long each = s / n;
    long long leftOver = s - (each * n);
    long long s = 0;
    for (long long i = 0; i < n; i++) v[i] = v[i] - each;
    long long j = 0;
    while (leftOver--) v[j++]--;
  }
  printf("%lld\n", v[0]);
}
