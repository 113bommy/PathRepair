#include <bits/stdc++.h>
using namespace std;
int g[100005];
int main() {
  int n, a, b;
  double x;
  cin >> n >> x;
  double cnt = 0;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    g[a]++;
    g[b]++;
  }
  for (int i = 1; i <= n; i++) {
    if (g[i] == 1) cnt++;
  }
  double ans = (cnt / x) * 2.0;
  cout << fixed << setprecision(10) << ans;
}
