#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a[111111], c;
  cin >> n >> x;
  for (long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  sort(a, a + n);
  for (long long i = 0; i < n; i++) {
    ans += x * a[i];
    if (x > 1) x--;
  }
  cout << ans;
  return 0;
}
