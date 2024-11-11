#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int M = 1e6 + 1;
int rsum[N], csum[N];
int rowans[M], colans[M];
int n, m, k, p;
int rowred, colred;
priority_queue<int> pq;
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  rowred = m * p;
  colred = n * p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int t;
      scanf("%d", &t);
      rsum[i] += t;
      csum[j] += t;
    }
  }
  for (int i = 0; i < n; ++i) {
    pq.push(rsum[i]);
  }
  long long ans = -1e16;
  for (int i = 1; i <= k; ++i) {
    int best = pq.top();
    pq.pop();
    rowans[i] = best;
    pq.push(best - rowred);
  }
  while (pq.size()) pq.pop();
  for (int i = 0; i < m; ++i) {
    pq.push(csum[i]);
  }
  for (int i = 1; i <= k; ++i) {
    int best = pq.top();
    pq.pop();
    colans[i] = best;
    pq.push(best - colred);
  }
  for (int i = 1; i <= k; ++i) {
    rowans[i] += rowans[i - 1];
    colans[i] += colans[i - 1];
  }
  for (int i = 0; i <= k; ++i) {
    ans = max(ans, rowans[i] + colans[k - i] - 1LL * i * (k - i) * p);
  }
  printf("%lld\n", ans);
}
