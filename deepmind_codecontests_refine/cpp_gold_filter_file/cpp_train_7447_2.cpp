#include <bits/stdc++.h>
using namespace std;
long long int n, h, k, a[100005], ans, x, y;
int main() {
  cin >> n >> h >> k;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  int i = 0;
  while (i < n) {
    if ((x + a[i]) <= h) {
      x += a[i++];
    }
    y = x / k;
    ans += y;
    x = x % k;
    if (x > 0 && x + a[i] > h) {
      x = 0;
      ans++;
    }
  }
  if (x > 0) {
    float i;
    i = (float)x / (float)k;
    ans += x / k;
    if (x % k > 0) ans++;
  }
  cout << ans;
  return 0;
}
