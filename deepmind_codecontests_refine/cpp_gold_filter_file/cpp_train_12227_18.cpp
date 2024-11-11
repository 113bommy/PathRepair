#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[505];
double ans;
int main() {
  int i, a, b, c;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    ans = max(ans, double(arr[a] + arr[b]) / double(c));
  }
  printf("%.15lf\n", ans);
  return 0;
}
