#include <bits/stdc++.h>
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
int r[5005], c[5005], II[5005], JJ[5005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int a, b, cc;
    cin >> a >> b >> cc;
    if (a == 1) {
      r[b] = cc;
      II[cc] = i;
    } else {
      c[b] = cc;
      JJ[cc] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (II[i] > JJ[j]) {
        printf("%d ", r[i]);
      } else
        printf("%d ", c[j]);
    }
    printf("\n");
  }
  return 0;
}
