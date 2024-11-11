#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, l, trace[MAXN];
int x[MAXN], b[MAXN];
double f[MAXN], c[MAXN][MAXN];
vector<int> res;
bool check(double ans) {
  for (int i = 1; i <= n; ++i) {
    f[i] = sqrt(x[i]) - ans * b[i];
    trace[i] = 0;
    for (int j = 1; j <= i - 1; ++j)
      if (f[i] > f[j] + c[j][i] - ans * b[i])
        f[i] = f[j] + c[j][i] - ans * b[i], trace[i] = j;
  }
  int pos = n;
  res.clear();
  while (pos > 0) res.push_back(pos), pos = trace[pos];
  return f[n] <= 0;
}
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &b[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) c[i][j] = sqrt(abs(x[j] - x[i] - l));
  double L = 0, R = 1E6;
  for (int i = 0; i < 100; ++i) {
    double M = (L + R) / 2;
    if (check(M))
      R = M;
    else
      L = M;
  }
  for (int i = int(res.size()) - 1; i >= 0; --i) printf("%d ", res[i]);
}
