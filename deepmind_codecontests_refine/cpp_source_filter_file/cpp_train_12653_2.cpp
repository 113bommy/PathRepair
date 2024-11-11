#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long st1[210000][30];
long long st2[210000][30];
long long lg[210000];
long long find1(long long l, long long r) {
  long long len = r - l + 1;
  return max(st1[l][lg[len]], st1[r - (1 << lg[len]) + 1][lg[len]]);
}
long long find2(long long l, long long r) {
  long long len = r - l + 1;
  return min(st2[l][lg[len]], st2[r - (1 << lg[len]) + 1][lg[len]]);
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &st1[i][0]);
    lg[i] = lg[i - 1];
    if (i == (2 << lg[i - 1])) lg[i]++;
  }
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &st2[i][0]);
  }
  for (long long j = 1; (1 << j) <= n; j++) {
    for (long long i = 1; (i + (1 << (j)) - 1) <= n; i++) {
      st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (long long j = 1; (1 << j) <= n; j++) {
    for (long long i = 1; (i + (1 << (j)) - 1) <= n; i++) {
      st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long l = 1;
    long long r = i;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      if (find1(mid, i) > find2(mid, i)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    long long tmp = l;
    l = 1;
    r = i;
    while (l < r) {
      long long mid = (l + r + 1) >> 1;
      if (find1(mid, i) >= find2(mid, i)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    ans += l - tmp;
  }
  cout << ans << endl;
  return 0;
}
