#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int MOD = 100000007;
const double EPS = 1e-7;
int prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int a[500010];
int main() {
  int n, p = 0;
  scanf("%d", &n);
  for (int i = 0; p < n; i++) {
    a[p++] = prm[i];
    for (int j = 0; j < p; j++) {
      if (a[j] * prm[i] > 2 * n * n) continue;
      a[p++] = a[j] * prm[i];
    }
  }
  for (int i = p - 1, j = 0; j < n; i--, j++) printf("%d ", a[i]);
  return 0;
}
