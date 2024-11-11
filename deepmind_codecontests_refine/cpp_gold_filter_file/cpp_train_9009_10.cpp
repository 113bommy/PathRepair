#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int ans = 0;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  sort(b, b + n, greater<int>());
  for (int i = 0; i < n; i++) {
    ans += a[i] * 1ll * b[i];
  }
  cout << ans % 10007;
}
