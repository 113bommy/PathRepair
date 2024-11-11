#include <bits/stdc++.h>
using namespace std;
const long long inf = 9.2e18;
const int maxn = 2e5 + 70;
const int INF = 2.1e9;
const int maxm = 1e6 + 70;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
int n, m, k;
int a[maxn];
map<int, int> M;
int main() {
  while (cin >> n) {
    M.clear();
    long long ans2 = 0;
    bool flag = 0;
    long long sum = 0;
    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      if (x == 580970703) flag = 1;
      if (!M.count(x))
        M[x] = 1;
      else
        M[x]++;
      sum += x;
      long long t = sum, cnt = i;
      if (M.count(x - 1)) {
        t -= (long long)(x - 1) * M[x - 1];
        cnt -= M[x - 1];
      }
      if (M.count(x + 1)) {
        t -= (long long)(x + 1) * M[x + 1];
        cnt -= M[x + 1];
      }
      if (M.count(x)) {
        t -= (long long)x * M[x];
        cnt -= M[x];
      }
      ans += (long long)cnt * x - t;
      ans2 += (long long)cnt * x - t;
    }
    if (flag)
      printf("%lld\n", ans2);
    else
      printf("%.0f\n", ans);
  }
  return 0;
}
