#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a[2210], ans = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long i = 0; i < k; i++) ans += a[i];
  cout << ans << endl;
  return 0;
}
