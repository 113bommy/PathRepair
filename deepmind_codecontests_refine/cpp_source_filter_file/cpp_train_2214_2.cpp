#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2e3 + 100;
int t, n;
int a[NMAX], fw[NMAX][NMAX];
void update(int fwId, int p, int n) {
  for (int i = p; i <= n; i += i & (-i)) {
    fw[fwId][i]++;
  }
}
int getSum(int fwId, int r) {
  int res = 0;
  for (int i = r; i >= 1; i -= i & (-i)) {
    res += fw[fwId][i];
  }
  return res;
}
int get(int fwId, int l, int r) {
  return getSum(fwId, r) - getSum(fwId, l - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    vector<bool> had(n + 1);
    vector<int> unique(0);
    for (int i = 0; i <= n; i++) {
      had[i] = 0;
      for (int j = 0; j <= n; j++) fw[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (had[a[i]] == 0) {
        had[a[i]] = 1;
        unique.push_back(a[i]);
      }
    }
    for (int i = 0; i < unique.size(); i++)
      for (int j = 1; j <= n; j++)
        if (a[j] == unique[i]) {
          update(a[j], j, n);
        }
    long long res = 0;
    for (int j = 2; j <= n - 2; j++)
      for (int k = j + 1; k <= n - 1; k++)
        res += 1ll * get(a[k], 1, j - 1) * get(a[j], k + 1, n);
    printf("%lld\n", res);
  }
}
