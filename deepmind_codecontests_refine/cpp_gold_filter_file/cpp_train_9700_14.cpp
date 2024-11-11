#include <bits/stdc++.h>
using namespace std;
int n, k, q, m;
double minP, maxP;
int p[111];
vector<int> pp;
bool remain[111];
int main() {
  scanf("%d%d", &n, &k);
  m = n / k;
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  scanf("%d", &q);
  minP = 1e9;
  maxP = -1;
  memset(remain, 1, sizeof remain);
  for (int i = 1; i <= q; i++) {
    double sum = 0;
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      remain[x] = 0;
      sum += p[x];
    }
    minP = min(minP, sum / m);
    maxP = max(maxP, sum / m);
  }
  for (int i = 1; i <= n; i++)
    if (remain[i]) pp.push_back(p[i]);
  if (pp.size() > n - k * m) {
    sort(pp.begin(), pp.end());
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < m; i++) {
      sum1 += pp[i];
      sum2 += pp[pp.size() - i - 1];
    }
    minP = min(minP, sum1 / m);
    maxP = max(maxP, sum2 / m);
  }
  cout << fixed << setprecision(6) << minP << " " << maxP;
  return 0;
}
