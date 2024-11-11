#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const long long mod = 10007;
const int N = 110;
int val[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= j; k++) {
        val[k]++;
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, val[i]);
  }
  printf("%d\n", ans);
  return 0;
}
