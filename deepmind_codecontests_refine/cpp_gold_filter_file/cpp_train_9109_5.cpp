#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, a1, b1, dis1[2001], dis2[2001];
  cin >> n >> a >> b >> a1 >> b1;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    long long sqr = (a - x) * (a - x) + (b - y) * (b - y);
    dis1[i] = sqr;
    sqr = (a1 - x) * (a1 - x) + (b1 - y) * (b1 - y);
    dis2[i] = sqr;
  }
  long long res = -1;
  for (int i = 0; i <= n; i++) {
    long long r1 = dis1[i];
    long long r2 = 0;
    for (int j = 0; j <= n; j++) {
      if (dis1[j] > r1) r2 = max(r2, dis2[j]);
    }
    if (res == -1)
      res = r1 + r2;
    else
      res = min(res, r1 + r2);
  }
  cout << res;
  return 0;
}
