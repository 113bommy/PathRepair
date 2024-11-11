#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, p;
  cin >> n >> m >> k >> p;
  long long ar[1002][1002];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> ar[i][j];
      ar[i][0] += ar[i][j];
      ar[0][j] += ar[i][j];
    }
  }
  priority_queue<long long> pr;
  priority_queue<long long> pc;
  for (int i = 1; i <= n; ++i) {
    pr.push(ar[i][0]);
  }
  for (int i = 1; i <= m; ++i) {
    pc.push(ar[0][i]);
  }
  vector<long long> rsum(1000001);
  vector<long long> csum(1000001);
  rsum[0] = 0;
  csum[0] = 0;
  long long bestr, bestc;
  for (int i = 1; i <= k; ++i) {
    bestr = pr.top();
    pr.pop();
    rsum[i] = rsum[i - 1] + bestr;
    pr.push(bestr - m * p);
  }
  for (int i = 1; i <= k; ++i) {
    bestc = pc.top();
    pc.pop();
    csum[i] = csum[i - 1] + bestc;
    pc.push(bestc - n * p);
  }
  long long best = -100000000000000001;
  for (int i = 0; i <= k; ++i) {
    best = max(best, rsum[i] + csum[k - i] - (i * 1ll) * (k - i) * p);
  }
  cout << best << endl;
  return 0;
}
