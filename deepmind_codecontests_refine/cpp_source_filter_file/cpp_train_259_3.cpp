#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 30100;
pair<long long, int> a[maxn];
long long fib[maxn];
int main() {
  {
    srand(time(0));
    const string file = "";
    if (!file.empty()) {
      freopen((file + ".in").c_str(), "r", stdin);
      freopen((file + ".out").c_str(), "w", stdout);
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i].first);
    a[i].second = i + 1;
  }
  sort(&a[0], &a[n]);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fib[i] -= fib[i] >= m ? m : 0;
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < n; ++i) {
    long long ans = 0;
    int l, r, lst = -1;
    scanf("%d%d", &l, &r);
    for (int j = 0, k = 0; j < n; ++j) {
      if (a[j].second >= l && a[j].second <= r && a[j].first != lst) {
        lst = a[j].first;
        ans += fib[k++] * a[j].first;
      }
    }
    ans %= m;
    printf("%lld\n", ans);
  }
  return (0);
}
