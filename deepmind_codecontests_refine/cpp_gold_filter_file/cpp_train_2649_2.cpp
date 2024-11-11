#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x;
  cin >> n >> x;
  long long ans = 0;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    ans += a[i] * x;
    if (x > 1) x--;
  }
  cout << ans;
}
