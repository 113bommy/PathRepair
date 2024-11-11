#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int n, m, k;
vector<int> p[MAXN];
int solve(vector<int> &a) {
  int res = 0, sum = 0;
  for (int i = 0, j = 1; i < ((int)a.size()) - 1; i++) {
    for (; j < ((int)a.size()) && sum + a[j] - a[j - 1] - 1 <= k;
         sum += a[j] - a[j - 1] - 1, j++)
      ;
    res = max(res, j - i);
    if (i + 1 != j)
      sum -= a[i + 1] - a[i] - 1;
    else
      j++;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0, x; i < n; i++) scanf("%d", &x), p[x - 1].push_back(i);
  int res = 0;
  for (int i = 0; i < m; i++) res = max(res, solve(p[i]));
  printf("%d\n", res);
  return 0;
}
