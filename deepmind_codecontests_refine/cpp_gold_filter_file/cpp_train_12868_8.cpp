#include <bits/stdc++.h>
using namespace std;
long long MAX(long long a, long long b) { return a > b ? a : b; }
long long MIN(long long a, long long b) { return a < b ? a : b; }
long long a[1000000], h1[1000000], h2[1000000], cost1[1000000], cost2[1000000];
long long sum1[1000000], sum2[1000000];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    h1[i] = MAX(a[i], h1[i - 1] + 1);
    cost1[i] = h1[i] - a[i];
    sum1[i] = sum1[i - 1] + cost1[i];
  }
  for (int i = n; i >= 1; i--) {
    h2[i] = MAX(a[i], h2[i + 1] + 1);
    cost2[i] = h2[i] - a[i];
    sum2[i] = sum2[i + 1] + cost2[i];
  }
  long long ans = 10000000000000000;
  for (int i = 1; i <= n; i++) {
    ans = MIN(ans, sum1[i - 1] + sum2[i + 1] + MAX(h1[i], h2[i]) - a[i]);
  }
  cout << ans << endl;
  return 0;
}
