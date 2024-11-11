#include <bits/stdc++.h>
using namespace std;
long long int LONG_INT_MAX = 1000000000000005;
long long int mod = 998244353;
long long int mod1 = 1e9 + 7;
struct comp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
      return p1.second < p2.second;
    }
    return p1.first < p2.first;
  }
};
int a[200005];
long long int sum[200005];
int main() {
  int n, m, k;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  sum[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  long double ans = 0;
  for (int i = min(m, n - 1); i >= 0; i--) {
    double ops = m - i;
    double p = n - i;
    long double sum1 = sum[i] + min(ops, k * p);
    ans = max(ans, sum1 / p);
  }
  cout << setprecision(10);
  cout << ans << endl;
  return 0;
}
