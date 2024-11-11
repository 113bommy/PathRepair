#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main() {
  double n, x, y;
  cin >> n >> x >> y;
  double per = x / n * 100;
  y -= per;
  int ans = ceil(y / 100.0 * n);
  cout << max(ans, 0) << endl;
}
