#include <bits/stdc++.h>
using namespace std;
long long a[100005], sum[100005], dp[100005], d[100005];
int q[100005];
int n, m, p;
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i < n; i++) {
    cin >> d[i];
    sum[i + 1] = sum[i] + d[i];
  }
  for (int i = 1; i <= m; i++) {
    int num;
    cin >> num >> a[i];
    a[i] -= sum[num];
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    a[i] -= a[1];
  }
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + a[i];
    dp[i] = a[i] * i - sum[i];
  }
  for (int j = 1; j < p; j++) {
    for (int i = 1; i <= m; i++) {
      d[i] = dp[i] + sum[i];
    }
    int head = 0, tail = -1;
    for (int i = 1; i <= m; i++) {
      while (head < tail &&
             (d[q[head + 1]] - d[q[head]]) < a[i] * (q[head + 1] - q[head])) {
        head++;
      }
      while (head < tail && (d[q[tail]] - d[q[tail - 1]]) * (i - q[tail]) >
                                (d[i] - d[q[tail]]) * (q[tail] - q[tail - 1])) {
        tail--;
      }
      q[++tail] = i;
      dp[i] = d[q[head]] + a[i] * (i - q[head]) - sum[i];
    }
  }
  cout << dp[m] << endl;
  return 0;
}
