#include <bits/stdc++.h>
const long long MOD = 1000000007;
using namespace std;
int n, a[(100 + 10)];
vector<int> v;
long long goal, k;
int main() {
  scanf("%d", &n), scanf("%d", &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), goal += a[i], a[i]--;
  goal += k;
  for (int i = 1; i <= n; i++)
    for (int j = 1, d; j <= a[i]; j = d + 1)
      d = a[i] / (a[i] / j), v.push_back(j);
  for (int i = 1; i <= n; i++) v.push_back(a[i] + 1);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int td, last = 1 << 30;
  for (int s = v.size() - 1; ~s; s--) {
    int d = v[s];
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += d * (a[i] / d);
    }
    if (1LL * n * d + cur <= goal) {
      td = d;
      break;
    }
    last = d;
  }
  long long cur = 0;
  for (int i = 1; i <= n; i++) cur += (long long)(a[i] / td);
  printf("%lld\n", goal / ((long long)n + cur));
  return 0;
}
