#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * (1e5);
long long a[maxn], b[maxn];
const int base = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  b[0] = 1;
  for (int i = 1; i < n; i++) b[i] = (2 * b[i - 1]) % base;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    long long temp = ((b[i] - 1) * (b[n - i] - 1)) % base;
    temp = ((a[i] - a[i - 1]) * temp) % base;
    ans += temp;
    ans = ans % base;
  }
  cout << ans << endl;
  return 0;
}
