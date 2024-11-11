#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int qq = 1e5 + 10;
const long long INF = 1e18 + 10;
long long n, m;
long long a[105], b[105];
vector<int> x, y;
void Solve(int l, int r) {
  for (int i = 0; i < (1 << l); ++i) {
    long long sum = 0;
    for (int j = 0; j < l; ++j) {
      if (i & (1 << j)) sum += a[j];
    }
    x.push_back(sum % m);
  }
  for (int i = 0; i < (1 << r); ++i) {
    long long sum = 0;
    for (int j = 0; j < r; ++j) {
      if (i & (1 << j)) sum += b[j];
    }
    y.push_back(sum % m);
  }
  sort(y.begin(), y.end());
  long long maxn = 0;
  for (int i = 0; i < x.size(); ++i) {
    int k = lower_bound(y.begin(), y.end(), m - 1 - x[i]) - y.begin();
    if (k > 0 && y[k] > (m - 1 - x[i])) k--;
    maxn = max(maxn, max((x[i] + y[k]) % m, (x[i] + y[y.size() - 1]) % m));
  }
  printf("%lld\n", maxn);
}
int main() {
  scanf("%lld%lld", &n, &m);
  if (n == 1) {
    scanf("%lld", &a[0]);
    printf("%lld\n", a[0]);
  } else {
    int l = n / 2, r = n - l;
    for (int i = 0; i < l; ++i) {
      scanf("%lld", a + i);
    }
    for (int i = 0; i < r; ++i) {
      scanf("%lld", b + i);
    }
    Solve(l, r);
  }
  return 0;
}
