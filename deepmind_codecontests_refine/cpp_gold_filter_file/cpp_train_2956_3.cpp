#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c, t;
  cin >> n >> m;
  int sum[n + 1];
  sum[0] = 0;
  for (int x = 1; x <= n; x++) {
    cin >> c >> t;
    sum[x] = sum[x - 1] + c * t;
  }
  int v;
  int cal = 0;
  for (int x = 0; x < m; x++) {
    cin >> v;
    while (sum[cal] < v) cal++;
    cout << cal << endl;
  }
  return 0;
}
