#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long a[11000];
unsigned long long b[11000];
unsigned long long c;
unsigned long long f(unsigned long long x) {
  unsigned long long ans = n;
  for (int i = 0; i < n; ++i) ans += a[i] * x / b[i];
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> c;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  unsigned long long ans = 0;
  for (unsigned long long x = 0; x < 100000; ++x)
    if (f(x) == c) ans++;
  if (ans == 100000)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
