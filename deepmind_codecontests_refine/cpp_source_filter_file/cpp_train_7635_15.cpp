#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int oo = 2100000000;
vector<int> a[1100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int k, x;
    scanf("%d", &k);
    a[i].clear();
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  a[0] = a[n];
  a[n + 1] = a[0];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int i1 = 0, i2 = 0;
    while (i1 < a[i - 1].size() && a[i - 1][i1] < a[i][0]) i1++;
    while (i2 < a[i + 1].size() && a[i + 1][i2] < a[i][0]) i2++;
    int n1, n2;
    for (int j = 0; j < a[i].size() - 1; j++) {
      n1 = n2 = 0;
      while (i1 < a[i - 1].size() && a[i - 1][i1] < a[i][j + 1]) {
        i1++;
        n1++;
      }
      while (i2 < a[i + 1].size() && a[i + 1][i2] < a[i][j + 1]) {
        i2++;
        n2++;
      }
      if (n1 != n2) ans++;
    }
  }
  printf("%d\n", ans);
  return (0);
}
