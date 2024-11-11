#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int mod = 998244353;
int t[maxn], q[maxn];
int main() {
  int n;
  long long a, b, c, d, start;
  int len;
  scanf("%d%lld%lld%lld%lld%lld%d", &n, &a, &b, &c, &d, &start, &len);
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i], &q[i]);
  t[0] = -1;
  long long sum = 0, minn = mod, rating = start;
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    while (pos <= n && t[pos] - t[i] < len) {
      sum += q[pos] ? c : -d;
      minn = min(minn, sum);
      pos++;
    }
    if (minn + rating >= 0) {
      printf("%d\n", t[i - 1] + 1);
      return 0;
    }
    sum -= q[i] ? c : -d;
    minn -= q[i] ? c : -d;
    rating += q[i] ? a : -b;
    if (rating < 0) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", t[n] + 1);
  return 0;
}
