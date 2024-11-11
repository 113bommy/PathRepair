#include <bits/stdc++.h>
using namespace std;
vector<double> arr;
long long int power[20];
double dp[1001][1001];
long long int cal(long long int l) {
  long long int sum = 0, i;
  if (l == 0) return 0;
  long long int t = l;
  for (i = 0;; i++) {
    t /= 10;
    if (t == 0) break;
  }
  t = l;
  if (t / power[i] == 0)
    sum += cal(t % power[i]);
  else if (t / power[i] > 1)
    sum += cal(power[i] - 1) + power[i];
  else
    sum += (t % power[i]) + (t / power[i] > 0 ? 1 : 0) + cal(power[i] - 1);
  return sum;
}
long long int n;
double foo(long long int i, long long int k) {
  if (i == n && k > 0)
    return 0;
  else if (i == n || k == 0)
    return 1;
  if (dp[i][k] != -1) return dp[i][k];
  double ans = arr[i] * foo(i + 1, k - 1) + (1 - arr[i]) * foo(i + 1, k);
  return dp[i][k] = ans;
}
int main() {
  long long int i, l, r, k, j;
  scanf("%lld", &n);
  power[0] = 1;
  for (i = 1; i < 20; i++) power[i] = 10 * power[i - 1];
  for (i = 0; i < n; i++) {
    scanf("%lld%lld", &l, &r);
    arr.push_back((double)(cal(r) - cal(l - 1)) / (r - l + 1));
  }
  scanf("%lld", &k);
  if ((n * k) % 100)
    k = n * k / 100 + 1;
  else
    k = n * k / 100;
  for (i = 0; i < 1001; i++)
    for (j = 0; j < 1001; j++) dp[i][j] = -1;
  double ans = foo(0, k);
  printf("%.15lf\n", ans);
  return 0;
}
