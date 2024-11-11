#include <bits/stdc++.h>
using namespace std;
int n, a[501];
long long calc(int x) {
  x = x + 1;
  bool f = 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int aa = (a[i] + x - 1) / x, bb = aa * x - a[i];
    if (aa < bb) f = 0;
    sum += aa;
  }
  if (f)
    return sum;
  else
    return 1e9;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long ans = 1e9;
  for (int i = 1; i < 200000; i++) {
    ans = min(ans, calc(i));
    if (a[0] % i == 0) ans = min(ans, calc(a[0] / i - 1));
    ans = min(ans, calc(a[0] / i));
  }
  cout << ans << endl;
}
