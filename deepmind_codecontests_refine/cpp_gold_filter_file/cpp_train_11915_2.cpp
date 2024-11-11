#include <bits/stdc++.h>
using namespace std;
void fun() {
  long long i, j, n, m, x, y, k, p;
  cin >> n >> m >> k >> p;
  long long c[n][m];
  priority_queue<long long> pq, pq2;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  long long sum = 0;
  for (i = 0; i < n; i++) {
    sum = 0;
    for (j = 0; j < m; j++) {
      sum += c[i][j];
    }
    pq.push(sum);
  }
  for (i = 0; i < m; i++) {
    sum = 0;
    for (j = 0; j < n; j++) {
      sum += c[j][i];
    }
    pq2.push(sum);
  }
  long long z = 0;
  y = 0;
  long long sumz[k + 1][2];
  sumz[0][0] = 0;
  sumz[0][1] = 0;
  for (i = 1; i <= k; i++) {
    long long r = pq.top();
    pq.pop();
    pq.push(r - m * p);
    sumz[i][0] = sumz[i - 1][0] + r;
    sum += pq2.top();
    r = pq2.top();
    pq2.pop();
    pq2.push(r - n * p);
    sumz[i][1] = sumz[i - 1][1] + r;
  }
  long long ans = -10000000000000000;
  for (long long i = 0; i <= k; i++) {
    sum = sumz[i][0] + sumz[k - i][1];
    long long f = (max(i, k - i) - min(i, k - i)) * (min(i, k - i)) +
                  (((min(i, k - i)) * (min(i, k - i) + 1)) / 2);
    if (min(i, k - i) >= 1) {
      f += (min(i, k - i) * (min(i, k - i) - 1)) / 2;
    }
    if (sum - f * p > ans) ans = sum - f * p;
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  fun();
}
