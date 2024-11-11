#include <bits/stdc++.h>
using namespace std;
long long x[100000], y[100000];
int main() {
  int n, j;
  cin >> n >> j;
  j %= (2 * n);
  long long x1, y1;
  cin >> x1 >> y1;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &x[i], &y[i]);
  }
  for (int i = 0; i < j; i++) {
    int k = i % n;
    x1 = 2ll * x[k] - x1;
    y1 = 2ll * y[k] - y1;
  }
  cout << x1 << " " << y1 << endl;
  return 0;
}
