#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long num[5100], sum[5100];
  cin >> num[0];
  sum[0] = 0;
  sum[1] = num[0];
  for (int i = 1; i < n; i++) {
    cin >> num[i];
    sum[i + 1] = sum[i] + num[i];
  }
  double ans = 0;
  for (int i = k; i <= n; i++)
    for (int j = 0; (i + j) < n; j++) {
      ans = max(ans, (double)(sum[i + j] - sum[j]) / (double)i);
    }
  printf("%.7lf", ans);
}
