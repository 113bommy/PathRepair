#include <bits/stdc++.h>
using namespace std;
long long arr[1002][1002];
int main() {
  long long n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  priority_queue<long long> Q;
  for (int i = 0; i < n; i++) {
    long long sumforRow = 0;
    for (int j = 0; j < m; j++) sumforRow += arr[i][j];
    Q.push(sumforRow);
  }
  long long res = -1 * 100000000000000000;
  vector<long long> BestforRow(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    long long best = Q.top();
    Q.pop();
    BestforRow[i] = best;
    BestforRow[i] += BestforRow[i - 1];
    best -= m * p;
    Q.push(best);
  }
  while (!Q.empty()) Q.pop();
  for (int i = 0; i < m; i++) {
    long long sumforCol = 0;
    for (int j = 0; j < n; j++) sumforCol += arr[j][i];
    Q.push(sumforCol);
  }
  vector<long long> BestforCol(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    long long best = Q.top();
    Q.pop();
    BestforCol[i] = best;
    BestforCol[i] += BestforCol[i - 1];
    best -= n * p;
    Q.push(best);
  }
  for (long long i = 0; i <= k; i++) {
    res = max(res, BestforRow[i] + BestforCol[k - i] - (1LL * (k - i) * i * p));
  }
  cout << res;
}
