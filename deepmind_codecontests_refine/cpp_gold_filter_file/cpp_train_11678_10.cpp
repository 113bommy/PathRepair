#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 50;
long long n, m, k, a[N] = {0}, b[N] = {0}, ans = 0;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  for (int i = n - 1; i >= 0; i--) {
    long long x = 0, s = 0;
    for (int j = i; j < i + m && j < n; j++) {
      s += a[j];
      x = max(x, s);
    }
    b[i] = max(max(x, s + b[i + m]) - k, 0LL);
    ans = max(ans, b[i]);
  }
  cout << ans;
}
