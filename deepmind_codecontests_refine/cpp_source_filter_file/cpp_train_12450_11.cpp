#include <bits/stdc++.h>
using namespace std;
long double n, p, a[100001], b[100001], sum;
bool Ver(long double time) {
  long double x = 0;
  for (int i = 1; i <= n; i++) {
    x += max((long double)0, time * a[i] - b[i]);
  }
  return p * time >= x;
}
int main() {
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= n; i++) sum += a[i];
  if (sum <= p) {
    cout << "-1";
    return 0;
  }
  long double li, ls, mid;
  li = 0;
  ls = 10000000000000000000;
  for (int i = 1; i <= 300; i++) {
    mid = (li + ls) / 2;
    if (Ver(mid))
      li = mid;
    else
      ls = mid;
  }
  cout << fixed << setprecision(10) << mid;
}
